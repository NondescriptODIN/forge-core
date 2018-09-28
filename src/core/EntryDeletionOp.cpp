#include <core/Entry.hpp>
#include <core/EntryDeletionOp.hpp>

using buddy::core::Entry;
using buddy::core::EntryDeletionOp;

EntryDeletionOp::EntryDeletionOp(Entry&& entry,
                                 std::string&& owner,
                                 std::size_t block)
    : entry_(std::move(entry)),
      owner_(std::move(owner)),
      block_(block) {}


auto EntryDeletionOp::getKey() const
    -> const EntryKey&
{
    return entry_.first;
}

auto EntryDeletionOp::getKey()
    -> EntryKey&
{
    return entry_.first;
}

auto EntryDeletionOp::getValue() const
    -> const EntryValue&
{
    return entry_.second;
}

auto EntryDeletionOp::getValue()
    -> EntryValue&
{
    return entry_.second;
}

auto EntryDeletionOp::getBlock() const
    -> std::size_t
{
    return block_;
}

auto EntryDeletionOp::getOwner() const
    -> const std::string&
{
    return owner_;
}
auto EntryDeletionOp::getOwner()
    -> std::string&
{
    return owner_;
}