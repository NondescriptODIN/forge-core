/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_BUDDY_RPC_ABSTRACTREADONLYWALLETSTUBSEVER_H_
#define JSONRPC_CPP_STUB_BUDDY_RPC_ABSTRACTREADONLYWALLETSTUBSEVER_H_

#include <jsonrpccpp/server.h>

namespace buddy {
    namespace rpc {
        class AbstractReadOnlyWalletStubSever : public jsonrpc::AbstractServer<AbstractReadOnlyWalletStubSever>
        {
            public:
                AbstractReadOnlyWalletStubSever(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<AbstractReadOnlyWalletStubSever>(conn, type)
                {
                    this->bindAndAddMethod(jsonrpc::Procedure("updatelookup", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::updatelookupI);
                    this->bindAndAddNotification(jsonrpc::Procedure("shutdown", jsonrpc::PARAMS_BY_NAME,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::shutdownI);
                    this->bindAndAddNotification(jsonrpc::Procedure("rebuildlookup", jsonrpc::PARAMS_BY_NAME,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::rebuildlookupI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupvalue", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::lookupvalueI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupowner", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::lookupownerI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupactivationblock", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_INTEGER, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::lookupactivationblockI);
                    this->bindAndAddMethod(jsonrpc::Procedure("checkvalidity", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::checkvalidityI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupallentrysof", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY, "owner",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::lookupallentrysofI);
                    this->bindAndAddNotification(jsonrpc::Procedure("addwatchonlyaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::addwatchonlyaddressI);
                    this->bindAndAddNotification(jsonrpc::Procedure("deletewatchonlyaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::deletewatchonlyaddressI);
                    this->bindAndAddNotification(jsonrpc::Procedure("addnewownedaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::addnewownedaddressI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::getownedentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchonlyentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::getwatchonlyentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getallwatchedentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::getallwatchedentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchedaddresses", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::getwatchedaddressesI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedaddresses", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &buddy::rpc::AbstractReadOnlyWalletStubSever::getownedaddressesI);
                }

                inline virtual void updatelookupI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->updatelookup();
                }
                inline virtual void shutdownI(const Json::Value &/*request*/)
                {
                    this->shutdown();
                }
                inline virtual void rebuildlookupI(const Json::Value &/*request*/)
                {
                    this->rebuildlookup();
                }
                inline virtual void lookupvalueI(const Json::Value &request, Json::Value &response)
                {
                    response = this->lookupvalue(request["isstring"].asBool(), request["key"].asString());
                }
                inline virtual void lookupownerI(const Json::Value &request, Json::Value &response)
                {
                    response = this->lookupowner(request["isstring"].asBool(), request["key"].asString());
                }
                inline virtual void lookupactivationblockI(const Json::Value &request, Json::Value &response)
                {
                    response = this->lookupactivationblock(request["isstring"].asBool(), request["key"].asString());
                }
                inline virtual void checkvalidityI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->checkvalidity();
                }
                inline virtual void lookupallentrysofI(const Json::Value &request, Json::Value &response)
                {
                    response = this->lookupallentrysof(request["owner"].asString());
                }
                inline virtual void addwatchonlyaddressI(const Json::Value &request)
                {
                    this->addwatchonlyaddress(request["address"].asString());
                }
                inline virtual void deletewatchonlyaddressI(const Json::Value &request)
                {
                    this->deletewatchonlyaddress(request["address"].asString());
                }
                inline virtual void addnewownedaddressI(const Json::Value &request)
                {
                    this->addnewownedaddress(request["address"].asString());
                }
                inline virtual void getownedentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getownedentrys();
                }
                inline virtual void getwatchonlyentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getwatchonlyentrys();
                }
                inline virtual void getallwatchedentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getallwatchedentrys();
                }
                inline virtual void getwatchedaddressesI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getwatchedaddresses();
                }
                inline virtual void getownedaddressesI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getownedaddresses();
                }
                virtual bool updatelookup() = 0;
                virtual void shutdown() = 0;
                virtual void rebuildlookup() = 0;
                virtual Json::Value lookupvalue(bool isstring, const std::string& key) = 0;
                virtual std::string lookupowner(bool isstring, const std::string& key) = 0;
                virtual int lookupactivationblock(bool isstring, const std::string& key) = 0;
                virtual bool checkvalidity() = 0;
                virtual Json::Value lookupallentrysof(const std::string& owner) = 0;
                virtual void addwatchonlyaddress(const std::string& address) = 0;
                virtual void deletewatchonlyaddress(const std::string& address) = 0;
                virtual void addnewownedaddress(const std::string& address) = 0;
                virtual Json::Value getownedentrys() = 0;
                virtual Json::Value getwatchonlyentrys() = 0;
                virtual Json::Value getallwatchedentrys() = 0;
                virtual Json::Value getwatchedaddresses() = 0;
                virtual Json::Value getownedaddresses() = 0;
        };

    }
}
#endif //JSONRPC_CPP_STUB_BUDDY_RPC_ABSTRACTREADONLYWALLETSTUBSEVER_H_
