#pragma once


#include <cstdint>
#include <entrys/token/UtilityToken.hpp>

namespace forge::core {

class UtilityTokenOwnershipTransferOp
{
public:
    UtilityTokenOwnershipTransferOp(UtilityToken token,
                                    std::uint64_t amount,
                                    std::string sender,
                                    std::string reciever,
                                    std::int64_t block);

    auto getUtilityToken() const
        -> const UtilityToken&;
    auto getUtilityToken()
        -> UtilityToken&;

    auto getAmount()
        -> std::uint64_t;

    auto getSender() const
        -> const std::string&;
    auto getSender()
        -> std::string&;

    auto getReciever() const
        -> const std::string&;
    auto getReciever()
        -> std::string&;

    auto getBlock() const
        -> std::int64_t;

private:
    UtilityToken token_;
    std::uint64_t amount_;
    std::string sender_;
    std::string reciever_;
    std::int64_t block_;
};

auto createUtilityTokenOwnershipTransferOpMetadata(UtilityToken&& entry,
                                                   std::uint64_t)
    -> std::vector<std::byte>;

} // namespace forge::core
