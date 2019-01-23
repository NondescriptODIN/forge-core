/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_FORGE_RPC_ABSTRACTREADWRITEWALLETSTUBSEVER_H_
#define JSONRPC_CPP_STUB_FORGE_RPC_ABSTRACTREADWRITEWALLETSTUBSEVER_H_

#include <jsonrpccpp/server.h>

namespace forge {
    namespace rpc {
        class AbstractReadWriteWalletStubSever : public jsonrpc::AbstractServer<AbstractReadWriteWalletStubSever>
        {
            public:
                AbstractReadWriteWalletStubSever(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<AbstractReadWriteWalletStubSever>(conn, type)
                {
                    this->bindAndAddMethod(jsonrpc::Procedure("updatelookup", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::updatelookupI);
                    this->bindAndAddNotification(jsonrpc::Procedure("shutdown", jsonrpc::PARAMS_BY_NAME,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::shutdownI);
                    this->bindAndAddNotification(jsonrpc::Procedure("rebuildlookup", jsonrpc::PARAMS_BY_NAME,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::rebuildlookupI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupvalue", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::lookupvalueI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupowner", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::lookupownerI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupactivationblock", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_INTEGER, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::lookupactivationblockI);
                    this->bindAndAddMethod(jsonrpc::Procedure("checkvalidity", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::checkvalidityI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupallentrysof", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY, "owner",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::lookupallentrysofI);
                    this->bindAndAddNotification(jsonrpc::Procedure("addwatchonlyaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::addwatchonlyaddressI);
                    this->bindAndAddNotification(jsonrpc::Procedure("deletewatchonlyaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::deletewatchonlyaddressI);
                    this->bindAndAddNotification(jsonrpc::Procedure("addnewownedaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::addnewownedaddressI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::getownedentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchonlyentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::getwatchonlyentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getallwatchedentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::getallwatchedentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchedaddresses", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::getwatchedaddressesI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedaddresses", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractReadWriteWalletStubSever::getownedaddressesI);
                    this->bindAndAddMethod(jsonrpc::Procedure("ownesaddress", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::ownesaddressI);
                    this->bindAndAddMethod(jsonrpc::Procedure("createnewentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "address",jsonrpc::JSON_STRING,"burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"value",jsonrpc::JSON_OBJECT, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::createnewentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("renewentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::renewentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("updateentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"value",jsonrpc::JSON_OBJECT, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::updateentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("deleteentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::deleteentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("transferownership", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"newowner",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::transferownershipI);
                    this->bindAndAddMethod(jsonrpc::Procedure("paytoentryowner", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "amount",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractReadWriteWalletStubSever::paytoentryownerI);
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
                inline virtual void ownesaddressI(const Json::Value &request, Json::Value &response)
                {
                    response = this->ownesaddress(request["address"].asString());
                }
                inline virtual void createnewentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->createnewentry(request["address"].asString(), request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["value"]);
                }
                inline virtual void renewentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->renewentry(request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString());
                }
                inline virtual void updateentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->updateentry(request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["value"]);
                }
                inline virtual void deleteentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->deleteentry(request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString());
                }
                inline virtual void transferownershipI(const Json::Value &request, Json::Value &response)
                {
                    response = this->transferownership(request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["newowner"].asString());
                }
                inline virtual void paytoentryownerI(const Json::Value &request, Json::Value &response)
                {
                    response = this->paytoentryowner(request["amount"].asInt(), request["isstring"].asBool(), request["key"].asString());
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
                virtual bool ownesaddress(const std::string& address) = 0;
                virtual std::string createnewentry(const std::string& address, int burnvalue, bool isstring, const std::string& key, const Json::Value& value) = 0;
                virtual std::string renewentry(int burnvalue, bool isstring, const std::string& key) = 0;
                virtual std::string updateentry(int burnvalue, bool isstring, const std::string& key, const Json::Value& value) = 0;
                virtual std::string deleteentry(int burnvalue, bool isstring, const std::string& key) = 0;
                virtual std::string transferownership(int burnvalue, bool isstring, const std::string& key, const std::string& newowner) = 0;
                virtual std::string paytoentryowner(int amount, bool isstring, const std::string& key) = 0;
        };

    }
}
#endif //JSONRPC_CPP_STUB_FORGE_RPC_ABSTRACTREADWRITEWALLETSTUBSEVER_H_
