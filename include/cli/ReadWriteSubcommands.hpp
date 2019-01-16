#pragma once

#include <CLI/CLI.hpp>
#include <cli/CLIGlobalVariables.hpp>
#include <rpc/readwritewalletstubclient.h>

namespace buddy::cli {

auto addCreateEntry(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;

auto addRenewEntry(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;

auto addUpdateEntry(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;

auto addDeleteEntry(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;

auto addTransferOwnership(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;

auto addPayToEntry(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;

auto addReadWriteSubcommands(CLI::App& app, buddy::rpc::ReadWriteWalletStubClient& client)
    -> void;


} // namespace buddy::cli