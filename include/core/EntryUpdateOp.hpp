#pragma once

#include <core/Entry.hpp>

namespace forge::core {

class EntryUpdateOp
{
public:
    EntryUpdateOp(Entry&& entry,
                  std::string&& owner,
                  std::int64_t block,
                  std::int64_t value);

    auto getEntryKey() const
        -> const EntryKey&;
    auto getEntryKey()
        -> EntryKey&;

    auto getNewEntryValue() const
        -> const EntryValue&;

    auto getNewEntryValue()
        -> EntryValue&;

    auto getEntry() const
        -> const Entry&;
    auto getEntry()
        -> Entry&;

    auto getBlock() const
        -> std::int64_t;

    auto getValue() const
        -> std::int64_t;

    auto getOwner() const
        -> const std::string&;
    auto getOwner()
        -> std::string&;

private:
    Entry entry_;
    std::string owner_;
    std::int64_t block_;
    std::int64_t value_;
};

auto createEntryUpdateOpMetadata(EntryKey&& key,
                                 EntryValue new_value)
    -> std::vector<std::byte>;


} // namespace forge::core
