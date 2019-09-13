/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_FORGE_RPC_ABSTRACTJSONRPCSTUBSEVER_H_
#define JSONRPC_CPP_STUB_FORGE_RPC_ABSTRACTJSONRPCSTUBSEVER_H_

#include <jsonrpccpp/server.h>

namespace forge {
    namespace rpc {
        class AbstractJsonRpcStubSever : public jsonrpc::AbstractServer<AbstractJsonRpcStubSever>
        {
            public:
                AbstractJsonRpcStubSever(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<AbstractJsonRpcStubSever>(conn, type)
                {
                    this->bindAndAddMethod(jsonrpc::Procedure("updatelookup", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN,  NULL), &forge::rpc::AbstractJsonRpcStubSever::updatelookupI);
                    this->bindAndAddNotification(jsonrpc::Procedure("shutdown", jsonrpc::PARAMS_BY_NAME,  NULL), &forge::rpc::AbstractJsonRpcStubSever::shutdownI);
                    this->bindAndAddNotification(jsonrpc::Procedure("rebuildlookup", jsonrpc::PARAMS_BY_NAME,  NULL), &forge::rpc::AbstractJsonRpcStubSever::rebuildlookupI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupumvalue", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::lookupumvalueI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupuniquevalue", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::lookupuniquevalueI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupowner", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::lookupownerI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupactivationblock", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_INTEGER, "isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::lookupactivationblockI);
                    this->bindAndAddMethod(jsonrpc::Procedure("checkvalidity", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN,  NULL), &forge::rpc::AbstractJsonRpcStubSever::checkvalidityI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getlastvalidblockheight", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_INTEGER,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getlastvalidblockheightI);
                    this->bindAndAddMethod(jsonrpc::Procedure("lookupallentrysof", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY, "owner",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::lookupallentrysofI);
                    this->bindAndAddNotification(jsonrpc::Procedure("addwatchonlyaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::addwatchonlyaddressI);
                    this->bindAndAddNotification(jsonrpc::Procedure("deletewatchonlyaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::deletewatchonlyaddressI);
                    this->bindAndAddNotification(jsonrpc::Procedure("addnewownedaddress", jsonrpc::PARAMS_BY_NAME, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::addnewownedaddressI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedumentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getownedumentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchonlyumentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getwatchonlyumentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getallwatchedumentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getallwatchedumentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getowneduniqueentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getowneduniqueentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchonlyuniqueentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getwatchonlyuniqueentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getallwatcheduniqueentrys", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getallwatcheduniqueentrysI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchedaddresses", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getwatchedaddressesI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedaddresses", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getownedaddressesI);
                    this->bindAndAddMethod(jsonrpc::Procedure("ownesaddress", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_BOOLEAN, "address",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::ownesaddressI);
                    this->bindAndAddMethod(jsonrpc::Procedure("createnewumentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "address",jsonrpc::JSON_STRING,"burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"value",jsonrpc::JSON_OBJECT, NULL), &forge::rpc::AbstractJsonRpcStubSever::createnewumentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("createnewuniqueentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "address",jsonrpc::JSON_STRING,"burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"value",jsonrpc::JSON_OBJECT, NULL), &forge::rpc::AbstractJsonRpcStubSever::createnewuniqueentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("updateumentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"value",jsonrpc::JSON_OBJECT, NULL), &forge::rpc::AbstractJsonRpcStubSever::updateumentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("renewentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::renewentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("deleteentry", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::deleteentryI);
                    this->bindAndAddMethod(jsonrpc::Procedure("transferownership", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"newowner",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::transferownershipI);
                    this->bindAndAddMethod(jsonrpc::Procedure("paytoentryowner", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "amount",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::paytoentryownerI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getbalanceof", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "isstring",jsonrpc::JSON_BOOLEAN,"owner",jsonrpc::JSON_STRING,"token",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::getbalanceofI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getutilitytokensof", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY, "owner",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::getutilitytokensofI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getsupplyofutilitytoken", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "isstring",jsonrpc::JSON_BOOLEAN,"token",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::getsupplyofutilitytokenI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getownedutilitytokens", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getownedutilitytokensI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getwatchonlyutilitytokens", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getwatchonlyutilitytokensI);
                    this->bindAndAddMethod(jsonrpc::Procedure("getallwatchedutilitytokens", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY,  NULL), &forge::rpc::AbstractJsonRpcStubSever::getallwatchedutilitytokensI);
                    this->bindAndAddMethod(jsonrpc::Procedure("createnewutilitytoken", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_STRING, "address",jsonrpc::JSON_STRING,"burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"supply",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::createnewutilitytokenI);
                    this->bindAndAddMethod(jsonrpc::Procedure("sendutilitytokens", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY, "amount",jsonrpc::JSON_STRING,"burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING,"recipient",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::sendutilitytokensI);
                    this->bindAndAddMethod(jsonrpc::Procedure("burnutilitytokens", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_ARRAY, "amount",jsonrpc::JSON_STRING,"burnvalue",jsonrpc::JSON_INTEGER,"isstring",jsonrpc::JSON_BOOLEAN,"key",jsonrpc::JSON_STRING, NULL), &forge::rpc::AbstractJsonRpcStubSever::burnutilitytokensI);
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
                inline virtual void lookupumvalueI(const Json::Value &request, Json::Value &response)
                {
                    response = this->lookupumvalue(request["isstring"].asBool(), request["key"].asString());
                }
                inline virtual void lookupuniquevalueI(const Json::Value &request, Json::Value &response)
                {
                    response = this->lookupuniquevalue(request["isstring"].asBool(), request["key"].asString());
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
                inline virtual void getlastvalidblockheightI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getlastvalidblockheight();
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
                inline virtual void getownedumentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getownedumentrys();
                }
                inline virtual void getwatchonlyumentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getwatchonlyumentrys();
                }
                inline virtual void getallwatchedumentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getallwatchedumentrys();
                }
                inline virtual void getowneduniqueentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getowneduniqueentrys();
                }
                inline virtual void getwatchonlyuniqueentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getwatchonlyuniqueentrys();
                }
                inline virtual void getallwatcheduniqueentrysI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getallwatcheduniqueentrys();
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
                inline virtual void createnewumentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->createnewumentry(request["address"].asString(), request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["value"]);
                }
                inline virtual void createnewuniqueentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->createnewuniqueentry(request["address"].asString(), request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["value"]);
                }
                inline virtual void updateumentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->updateumentry(request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["value"]);
                }
                inline virtual void renewentryI(const Json::Value &request, Json::Value &response)
                {
                    response = this->renewentry(request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString());
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
                inline virtual void getbalanceofI(const Json::Value &request, Json::Value &response)
                {
                    response = this->getbalanceof(request["isstring"].asBool(), request["owner"].asString(), request["token"].asString());
                }
                inline virtual void getutilitytokensofI(const Json::Value &request, Json::Value &response)
                {
                    response = this->getutilitytokensof(request["owner"].asString());
                }
                inline virtual void getsupplyofutilitytokenI(const Json::Value &request, Json::Value &response)
                {
                    response = this->getsupplyofutilitytoken(request["isstring"].asBool(), request["token"].asString());
                }
                inline virtual void getownedutilitytokensI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getownedutilitytokens();
                }
                inline virtual void getwatchonlyutilitytokensI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getwatchonlyutilitytokens();
                }
                inline virtual void getallwatchedutilitytokensI(const Json::Value &/*request*/, Json::Value &response)
                {
                    response = this->getallwatchedutilitytokens();
                }
                inline virtual void createnewutilitytokenI(const Json::Value &request, Json::Value &response)
                {
                    response = this->createnewutilitytoken(request["address"].asString(), request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["supply"].asString());
                }
                inline virtual void sendutilitytokensI(const Json::Value &request, Json::Value &response)
                {
                    response = this->sendutilitytokens(request["amount"].asString(), request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString(), request["recipient"].asString());
                }
                inline virtual void burnutilitytokensI(const Json::Value &request, Json::Value &response)
                {
                    response = this->burnutilitytokens(request["amount"].asString(), request["burnvalue"].asInt(), request["isstring"].asBool(), request["key"].asString());
                }
                virtual bool updatelookup() = 0;
                virtual void shutdown() = 0;
                virtual void rebuildlookup() = 0;
                virtual Json::Value lookupumvalue(bool isstring, const std::string& key) = 0;
                virtual Json::Value lookupuniquevalue(bool isstring, const std::string& key) = 0;
                virtual std::string lookupowner(bool isstring, const std::string& key) = 0;
                virtual int lookupactivationblock(bool isstring, const std::string& key) = 0;
                virtual bool checkvalidity() = 0;
                virtual int getlastvalidblockheight() = 0;
                virtual Json::Value lookupallentrysof(const std::string& owner) = 0;
                virtual void addwatchonlyaddress(const std::string& address) = 0;
                virtual void deletewatchonlyaddress(const std::string& address) = 0;
                virtual void addnewownedaddress(const std::string& address) = 0;
                virtual Json::Value getownedumentrys() = 0;
                virtual Json::Value getwatchonlyumentrys() = 0;
                virtual Json::Value getallwatchedumentrys() = 0;
                virtual Json::Value getowneduniqueentrys() = 0;
                virtual Json::Value getwatchonlyuniqueentrys() = 0;
                virtual Json::Value getallwatcheduniqueentrys() = 0;
                virtual Json::Value getwatchedaddresses() = 0;
                virtual Json::Value getownedaddresses() = 0;
                virtual bool ownesaddress(const std::string& address) = 0;
                virtual std::string createnewumentry(const std::string& address, int burnvalue, bool isstring, const std::string& key, const Json::Value& value) = 0;
                virtual std::string createnewuniqueentry(const std::string& address, int burnvalue, bool isstring, const std::string& key, const Json::Value& value) = 0;
                virtual std::string updateumentry(int burnvalue, bool isstring, const std::string& key, const Json::Value& value) = 0;
                virtual std::string renewentry(int burnvalue, bool isstring, const std::string& key) = 0;
                virtual std::string deleteentry(int burnvalue, bool isstring, const std::string& key) = 0;
                virtual std::string transferownership(int burnvalue, bool isstring, const std::string& key, const std::string& newowner) = 0;
                virtual std::string paytoentryowner(int amount, bool isstring, const std::string& key) = 0;
                virtual std::string getbalanceof(bool isstring, const std::string& owner, const std::string& token) = 0;
                virtual Json::Value getutilitytokensof(const std::string& owner) = 0;
                virtual std::string getsupplyofutilitytoken(bool isstring, const std::string& token) = 0;
                virtual Json::Value getownedutilitytokens() = 0;
                virtual Json::Value getwatchonlyutilitytokens() = 0;
                virtual Json::Value getallwatchedutilitytokens() = 0;
                virtual std::string createnewutilitytoken(const std::string& address, int burnvalue, bool isstring, const std::string& key, const std::string& supply) = 0;
                virtual Json::Value sendutilitytokens(const std::string& amount, int burnvalue, bool isstring, const std::string& key, const std::string& recipient) = 0;
                virtual Json::Value burnutilitytokens(const std::string& amount, int burnvalue, bool isstring, const std::string& key) = 0;
        };

    }
}
#endif //JSONRPC_CPP_STUB_FORGE_RPC_ABSTRACTJSONRPCSTUBSEVER_H_