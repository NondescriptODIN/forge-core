#include <core/Block.hpp>
#include <core/Coin.hpp>
#include <core/Transaction.hpp>
#include <daemon/ReadOnlyDaemonBase.hpp>
#include <daemon/WriteOnlyDaemonBase.hpp>
#include <daemon/odin/ReadOnlyOdinDaemon.hpp>
#include <daemon/odin/ReadWriteOdinDaemon.hpp>
#include <fmt/core.h>
#include <g3log/g3log.hpp>
#include <json/value.h>
#include <utilxx/Opt.hpp>
#include <utilxx/Result.hpp>

using forge::daemon::ReadWriteOdinDaemon;
using forge::daemon::ReadOnlyOdinDaemon;
using utilxx::Opt;
using utilxx::Result;
using forge::core::stringToByteVec;
using forge::core::toHexString;
using forge::core::getDefaultTxFee;
using namespace std::string_literals;


auto ReadWriteOdinDaemon::generateRawTx(std::string input_txid,
                                        std::int64_t index,
                                        std::vector<std::byte> metadata,
                                        std::int64_t burn_value,
                                        std::vector<
                                            std::pair<std::string,
                                                      std::int64_t>>
                                            outputs) const
    -> Result<std::vector<std::byte>,
              DaemonError>
{
    static const auto command = "createrawtransaction"s;

    auto params = generateRpcParamsForRawTx(std::move(input_txid),
                                            index,
                                            std::move(metadata),
                                            burn_value,
                                            std::move(outputs));

    return sendcommand(command, std::move(params))
        .flatMap([](auto json) {
            return odin::processGenerateRawTxResponse(std::move(json));
        });
}

auto ReadWriteOdinDaemon::generateRpcParamsForRawTx(std::string input_txid,
                                                    std::int64_t index,
                                                    std::vector<std::byte> metadata,
                                                    std::int64_t burn_value,
                                                    std::vector<
                                                        std::pair<std::string,
                                                                  std::int64_t>>
                                                        outputs) const
    -> Json::Value
{
    auto metadata_str = toHexString(metadata);

    Json::Value input;
    input["txid"] = std::move(input_txid);
    input["vout"] = index;

    Json::Value inputs;
    inputs.append(std::move(input));

    Json::Value op_return;
    op_return["data"] = std::move(metadata_str);
    op_return["amount"] = static_cast<double>(burn_value) * 0.00000001;

    Json::Value json_outputs;

    for(auto&& [address, value] : outputs) {
        Json::Value output;
        output["address"] = std::move(address);
        output["amount"] = static_cast<double>(value) * 0.00000001;

        json_outputs.append(std::move(output));
    }

    json_outputs.append(std::move(op_return));

    Json::Value param;
    param.append(std::move(inputs));
    param.append(std::move(json_outputs));

    return param;
}

auto ReadWriteOdinDaemon::signRawTx(std::vector<std::byte> tx) const
    -> Result<std::vector<std::byte>,
              DaemonError>
{
    static const auto command = "signrawtransaction"s;

    Json::Value params;
    params.append(toHexString(tx));

    return sendcommand(command, std::move(params))
        .flatMap([](auto json) {
            return odin::processSignRawTxResponse(std::move(json));
        });
}

auto ReadWriteOdinDaemon::sendRawTx(std::vector<std::byte> tx) const
    -> Result<std::string, DaemonError>
{
    static const auto command = "sendrawtransaction"s;

    Json::Value params;
    params.append(toHexString(tx));
    //append to allow high fees
    params.append(true);

    return sendcommand(command, std::move(params))
        .flatMap([](auto json)
                     -> Result<std::string, DaemonError> {
            if(json.isString()) {
                return json.asString();
            }

            return DaemonError{json.toStyledString()};
        });
}

auto ReadWriteOdinDaemon::generateNewAddress() const
    -> utilxx::Result<std::string, DaemonError>
{
    static const auto command = "getnewaddress"s;

    return sendcommand(command, {})
        .flatMap([](auto json) {
            return odin::processGenerateNewAddressResponse(std::move(json));
        });
}

auto ReadWriteOdinDaemon::decodeTxidOfRawTx(const std::vector<std::byte>& tx) const
    -> utilxx::Result<std::string, DaemonError>
{
    static const auto command = "decoderawtransaction"s;

    Json::Value params;
    params.append(toHexString(tx));

    return sendcommand(command, std::move(params))
        .flatMap([](auto json) {
            return odin::processDecodeTxidOfRawTxResponse(std::move(json));
        });
}

auto ReadWriteOdinDaemon::burnAmount(std::int64_t amount,
                                     std::vector<std::byte> metadata) const
    -> utilxx::Result<std::string, DaemonError>
{
    auto fees = getDefaultTxFee(getCoin());
    return getUnspent()
        .flatMap([&](auto unspents)
                     -> utilxx::Result<std::string, DaemonError> {
            auto iter =
                std::find_if(std::cbegin(unspents),
                             std::cend(unspents),
                             [amount, fees](const auto& elem) {
                                 return elem.getValue() >= amount + fees;
                             });
            if(iter == std::cend(unspents)) {
                return DaemonError{"no input available to burn a value of "
                                   + std::to_string(amount)
                                   + " coins + "
                                   + std::to_string(fees)
                                   + " in fees"};
            }

            auto vout = iter->getVoutIdx();
            auto txid = std::move(iter->getTxid());
            auto value = iter->getValue();
            auto value_back = value - (fees + amount);

            //if the fees + burn value eat the whole input,
            //dont use a change address
            if(value_back == 0) {
                return writeTxToBlockchain(std::move(txid),
                                           vout,
                                           std::move(metadata),
                                           amount,
                                           {});
            }

            //if not, generate an new address and use it as output
            return generateNewAddress()
                .flatMap([&](auto exchange_adrs) {
                    return writeTxToBlockchain(std::move(txid),
                                               vout,
                                               std::move(metadata),
                                               amount,
                                               {{std::move(exchange_adrs), value_back}});
                });
        });
}

auto ReadWriteOdinDaemon::burnAmount(std::string txid,
                                     std::int64_t index,
                                     std::int64_t amount,
                                     std::vector<std::byte> metadata,
                                     std::string change_address) const
    -> utilxx::Result<std::string, DaemonError>
{
    return getOutputValue(txid, index)
        .flatMap([&](auto output_value)
                     -> Result<std::string, DaemonError> {
            auto fee = getDefaultTxFee(getCoin());
            //if the output value is less than the requested amount + fee return an error
            if(output_value < amount + fee) {
                auto error = fmt::format("output value of txid: {} and vout: {} is less than requested {}",
                                         txid,
                                         index,
                                         amount);
                return DaemonError{std::move(error)};
            }

            //if the output value is the same as the requested + fee
            //just burn the whole output and we dont need the change address
            if(output_value == amount + fee) {
                return burnOutput(std::move(txid),
                                  index,
                                  std::move(metadata));
            }

            return writeTxToBlockchain(std::move(txid),
                                       index,
                                       std::move(metadata),
                                       amount,
                                       {{change_address, output_value - (fee + amount)}});
        });
}

auto ReadWriteOdinDaemon::burnOutput(std::string txid,
                                     std::int64_t index,
                                     std::vector<std::byte> metadata) const
    -> utilxx::Result<std::string, DaemonError>
{
    return getOutputValue(txid, index)
        .flatMap([&](auto output_value) {
            auto fee = getDefaultTxFee(getCoin());
            return writeTxToBlockchain(std::move(txid),
                                       index,
                                       std::move(metadata),
                                       output_value - fee,
                                       {});
        });
}

namespace {

std::string roundDouble(double num)
{
    std::ostringstream ss;
    ss.precision(8);

    ss << std::fixed << num;
    return ss.str();
}

} // namespace

auto ReadWriteOdinDaemon::sendToAddress(std::int64_t amount,
                                        std::string address) const
    -> utilxx::Result<std::string, DaemonError>
{
    static const auto command = "sendtoaddress"s;

    Json::Value params;
    params.append(address);
    auto coins = static_cast<double>(amount) / 100000000.;
    params.append(roundDouble(coins));


    return sendcommand(command, std::move(params))
        .flatMap([&](auto json) {
            return odin::processSendToAddressResponse(std::move(json),
                                                      address);
        });
}


auto ReadWriteOdinDaemon::getVOutIdxByAmountAndAddress(std::string txid,
                                                       std::int64_t amount,
                                                       std::string address) const
    -> utilxx::Result<std::int64_t, DaemonError>
{
    static const auto command = "getrawtransaction"s;

    Json::Value params;
    params.append(std::move(txid));
    params.append(1);


    return sendcommand(command, std::move(params))
        .flatMap([&](auto json) {
            return odin::processGetVOutIdxByAmountAndAddressResponse(std::move(json),
                                                                     amount,
                                                                     std::move(address));
        });
}


auto forge::daemon::odin::processGenerateRawTxResponse(Json::Value&& response)
    -> utilxx::Result<std::vector<std::byte>,
                      DaemonError>
{
    auto result = response.toStyledString();

    auto number_of_delimiters =
        std::count(std::begin(result),
                   std::end(result),
                   '"');

    if(number_of_delimiters < 2) {
        return DaemonError{"The result of \"createrawtransaction\" was way to short"};
    }

    auto first = result.find('"') + 1;
    auto last = result.find_last_of('"');
    result = result.substr(first, last - first);

    if(auto byte_vec_opt = stringToByteVec(result);
       byte_vec_opt) {
        return byte_vec_opt.getValue();
    } else {
        return DaemonError{std::move(result)};
    }
}

auto forge::daemon::odin::processSignRawTxResponse(Json::Value&& response)
    -> utilxx::Result<std::vector<std::byte>,
                      DaemonError>
{
    //check if the request was complete
    if(!response.isMember("complete")
       || !response["complete"].isBool()
       || !response["complete"].asBool()) {

        if(response.isMember("errors")
           && response["errors"].isArray()
           && response["errors"].isValidIndex(0)
           && response["errors"][0].isMember("error")
           && response["errors"][0]["error"].isString()) {
            return DaemonError{std::move(response["errors"][0]["error"].asString())};
        }
        return DaemonError{"unknown error during transaction signing"};
    }

    if(!response.isMember("hex")
       || !response["hex"].isString()) {
        return DaemonError{"no hex value was returned from transaction signing"};
    }

    auto hex_str = response["hex"].asString();

    auto hex_vec = stringToByteVec(hex_str);

    if(!hex_vec) {
        return DaemonError{"wasn't able to create byte vec from the result of a transaction signing"};
    }

    return hex_vec.getValue();
}

auto forge::daemon::odin::processGenerateNewAddressResponse(Json::Value&& response)
    -> utilxx::Result<std::string, DaemonError>
{
    if(!response.isString()) {
        return DaemonError{"unknown error while getting new address"};
    }

    return response.asString();
}

auto forge::daemon::odin::processDecodeTxidOfRawTxResponse(Json::Value&& response)
    -> utilxx::Result<std::string, DaemonError>
{
    if(!response.isMember("txid")
       || !response["txid"].isString()) {
        auto error = fmt::format("unable to find txid in decoded raw transaction {}",
                                 response.toStyledString());
        return DaemonError{std::move(error)};
    }

    return response["txid"].asString();
}

auto forge::daemon::odin::processSendToAddressResponse(Json::Value&& response,
                                                       const std::string& address)
    -> utilxx::Result<std::string, DaemonError>
{
    if(!response.isString()) {
        auto error = fmt::format("unknown error sending odin to address {}",
                                 address);
        return DaemonError{std::move(error)};
    }

    return response.asString();
}


auto forge::daemon::odin::processGetVOutIdxByAmountAndAddressResponse(Json::Value&& response,
                                                                      std::int64_t amount,
                                                                      const std::string& address)
    -> utilxx::Result<std::int64_t, DaemonError>
{
    if(!response.isMember("vout")
       || !response["vout"].isArray()) {
        auto error = fmt::format("unable to decode response of \"getrawtransaction\"");
        return DaemonError{std::move(error)};
    }

    auto coins_raw = static_cast<double>(amount) / 100000000.;
    auto coins_expected = roundDouble(coins_raw);

    auto vouts = std::move(response["vout"]);

    std::int64_t counter{0};
    for(auto&& out : vouts) {
        if(!out.isMember("value")
           || !out["value"].isDouble()
           || !out.isMember("scriptPubKey")
           || !out["scriptPubKey"].isMember("addresses")
           || !out["scriptPubKey"]["addresses"].isArray()) {

            auto error = fmt::format("unable to decode vout:{} response of \"getrawtransaction\"",
                                     counter);
            return DaemonError{std::move(error)};
        }

        auto holds_address =
            std::find(std::cbegin(out["scriptPubKey"]["addresses"]),
                      std::cend(out["scriptPubKey"]["addresses"]),
                      address)
            != std::cend(out["addresses"]);

        if(coins_expected == roundDouble(out["value"].asDouble())
           && holds_address) {
            return counter;
        }

        counter++;
    }

    auto error =
        fmt::format("unable to find matching vout index for address: {} with amount {}",
                    address,
                    amount);

    return DaemonError{std::move(error)};
}
