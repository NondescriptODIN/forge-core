#include <core/FlagIndexes.hpp>
#include <entrys/umentry/UMEntry.hpp>
#include <entrys/umentry/UMEntryDeletionOp.hpp>
#include <entrys/umentry/UMEntryOperation.hpp>

using forge::core::UMEntry;
using forge::core::UMEntryDeletionOp;
using forge::core::UMENTRY_DELETION_FLAG;
using forge::core::FORGE_IDENTIFIER_MASK;

UMEntryDeletionOp::UMEntryDeletionOp(UMEntry&& entry,
                                     std::string&& owner,
                                     std::int64_t block,
                                     std::int64_t value)
    : entry_(std::move(entry)),
      owner_(std::move(owner)),
      block_(block),
      value_(value) {}


auto UMEntryDeletionOp::getEntryKey() const
    -> const EntryKey&
{
    return entry_.getKey();
}

auto UMEntryDeletionOp::getEntryKey()
    -> EntryKey&
{
    return entry_.getKey();
}

auto UMEntryDeletionOp::getUMEntryValue() const
    -> const UMEntryValue&
{
    return entry_.getValue();
}

auto UMEntryDeletionOp::getUMEntryValue()
    -> UMEntryValue&
{
    return entry_.getValue();
}

auto UMEntryDeletionOp::getUMEntry() const
    -> const UMEntry&
{
    return entry_;
}
auto UMEntryDeletionOp::getUMEntry()
    -> UMEntry&
{
    return entry_;
}

auto UMEntryDeletionOp::getBlock() const
    -> std::int64_t
{
    return block_;
}

auto UMEntryDeletionOp::getValue() const
    -> std::int64_t
{
    return value_;
}

auto UMEntryDeletionOp::getOwner() const
    -> const std::string&
{
    return owner_;
}
auto UMEntryDeletionOp::getOwner()
    -> std::string&
{
    return owner_;
}

auto forge::core::createUMEntryDeletionOpMetadata(UMEntry&& entry)
    -> std::vector<std::byte>
{
    auto data = entry.toRawData();
    auto flag = forge::core::UMENTRY_DELETION_FLAG;

    data.insert(std::begin(data), flag);

    data.insert(std::begin(data), UMENTRY_IDENTIFICATION_FLAG);

    data.insert(std::begin(data),
                std::begin(FORGE_IDENTIFIER_MASK),
                std::end(FORGE_IDENTIFIER_MASK));

    return data;
}
