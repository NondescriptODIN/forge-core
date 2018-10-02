include(ExternalProject)
include(GNUInstallDirs)

if (NOT TARGET jsoncpp-project)
  # Include jsoncpp dependency if not included yet.
  include(${CMAKE_CURRENT_LIST_DIR}/jsoncpp.cmake)
endif()

# HTTP client from JSON RPC CPP requires curl library. It can find it itself,
# but we need to know the libcurl location for static linking.
find_package(CURL REQUIRED)

set(CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
  -DCMAKE_BUILD_TYPE=Release
  -DBUILD_STATIC_LIBS=On
  -DBUILD_SHARED_LIBS=Off
  -DUNIX_DOMAIN_SOCKET_SERVER=Off
  -DUNIX_DOMAIN_SOCKET_CLIENT=Off
  -DHTTP_SERVER=Off
  -DHTTP_CLIENT=On
  -DREDIS_SERVER=NO
  -DREDIS_CLIENT=NO
  -DCOMPILE_TESTS=Off
  -DCOMPILE_STUBGEN=Off
  -DWITH_COVERAGE=NO
  -DCOMPILE_EXAMPLES=Off
  # Point to jsoncpp library.
  -DJSONCPP_INCLUDE_DIR=${JSONCPP_INCLUDE_DIR}
  # Select jsoncpp include prefix: <json/...> or <jsoncpp/json/...>
  -DJSONCPP_INCLUDE_PREFIX=json
  -DJSONCPP_LIBRARY=${JSONCPP_LIBRARY}
  -DCURL_INCLUDE_DIR=${CURL_INCLUDE_DIR}
  -DCURL_LIBRARY=${CURL_LIBRARY})

if (WIN32)
  # For Windows we have to provide also locations for debug libraries.
  set(CMAKE_ARGS ${CMAKE_ARGS}
    -DJSONCPP_LIBRARY_DEBUG=${JSONCPP_LIBRARY}
    -DCURL_LIBRARY_DEBUG=${CURL_LIBRARY})
endif()

ExternalProject_Add(jsonrpc-project
  PREFIX deps/jsonrpc
  DOWNLOAD_NAME json-cpp-rpc-1.1.0.tar.gz
  DOWNLOAD_DIR ${CMAKE_BINARY_DIR}/downloads
  URL https://github.com/cinemast/libjson-rpc-cpp/archive/v1.1.0.tar.gz
  # On Windows it tries to install this dir. Create it to prevent failure.
  PATCH_COMMAND cmake -E make_directory <SOURCE_DIR>/win32-deps/include
  CMAKE_ARGS ${CMAKE_ARGS}
  # Overwtire build and install commands to force Release build on MSVC.
  BUILD_COMMAND cmake --build <BINARY_DIR> --config Release
  INSTALL_COMMAND cmake --build <BINARY_DIR> --config Release --target install
  )

add_dependencies(jsonrpc-project jsoncpp-project)

# Create jsonrpc imported libraries
if (WIN32)
  # On Windows CMAKE_INSTALL_PREFIX is ignored and installs to dist dir.
  ExternalProject_Get_Property(jsonrpc-project BINARY_DIR)
  set(INSTALL_DIR ${BINARY_DIR}/dist)
else()
  ExternalProject_Get_Property(jsonrpc-project INSTALL_DIR)
endif()
set(JSONRPC_INCLUDE_DIR ${INSTALL_DIR}/include)
file(MAKE_DIRECTORY ${JSONRPC_INCLUDE_DIR})  # Must exist.

add_library(jsonrpc::common STATIC IMPORTED)
set_property(TARGET jsonrpc::common
  PROPERTY
  IMPORTED_LOCATION
  ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}jsonrpccpp-common${CMAKE_STATIC_LIBRARY_SUFFIX})

set_property(TARGET jsonrpc::common
  PROPERTY
  INTERFACE_LINK_LIBRARIES
  jsoncpp)

set_property(TARGET jsonrpc::common
  PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES
  ${JSONRPC_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR})

add_dependencies(jsonrpc::common jsonrpc-project)

add_library(jsonrpc::client STATIC IMPORTED)
set_property(TARGET jsonrpc::client
  PROPERTY
  IMPORTED_LOCATION
  ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}jsonrpccpp-client${CMAKE_STATIC_LIBRARY_SUFFIX})

set_property(TARGET jsonrpc::client
  PROPERTY
  INTERFACE_LINK_LIBRARIES
  jsonrpc::common ${CURL_LIBRARY})

set_property(TARGET jsonrpc::client
  PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES ${CURL_INCLUDE_DIR})

add_dependencies(jsonrpc::client jsonrpc-project)

# add_library(jsonrpc::server STATIC IMPORTED)
# set_property(TARGET jsonrpc::server PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}jsonrpccpp-server${CMAKE_STATIC_LIBRARY_SUFFIX})
# set_property(TARGET jsonrpc::server PROPERTY INTERFACE_LINK_LIBRARIES jsonrpc::common ${MHD_LIBRARY})
# set_property(TARGET jsonrpc::server PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${MHD_INCLUDE_DIR})
# add_dependencies(jsonrpc::server jsonrpc-project)

unset(INSTALL_DIR)
unset(CMAKE_ARGS)