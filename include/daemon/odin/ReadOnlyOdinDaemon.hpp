#pragma once

#include <core/Block.hpp>
#include <core/Coin.hpp>
#include <core/Transaction.hpp>
#include <daemon/ReadOnlyDaemonBase.hpp>
#include <jsonrpccpp/client.h>
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <utilxx/Opt.hpp>
#include <utilxx/Result.hpp>

namespace buddy::daemon {

class ReadOnlyOdinDaemon : public ReadOnlyDaemonBase
{
public:
    ReadOnlyOdinDaemon(const std::string& host,
                       const std::string& user,
                       const std::string& password,
                       std::size_t port,
                       core::Coin coin);

    virtual ~ReadOnlyOdinDaemon() = default;

    auto getNewestBlock() const
        -> utilxx::Result<core::Block, DaemonError> override;

    auto getTransaction(std::string&& txid) const
        -> utilxx::Result<core::Transaction, DaemonError> override;

    auto resolveTxIn(core::TxIn&& vin) const
        -> utilxx::Result<core::TxOut, DaemonError> override;

    auto getBlockCount() const
        -> utilxx::Result<std::size_t, DaemonError> override;

    auto getBlockHash(std::size_t index) const
        -> utilxx::Result<std::string, DaemonError> override;

    auto getBlock(std::string&& hash) const
        -> utilxx::Result<core::Block, DaemonError> override;

protected:
    auto sendcommand(const std::string& command,
                     const Json::Value& params) const
        -> utilxx::Result<Json::Value, DaemonError>;


private:
    jsonrpc::HttpClient http_client_;
    mutable jsonrpc::Client client_;
};

} // namespace buddy::daemon
