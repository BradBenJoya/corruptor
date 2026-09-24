#include "Args.h"
#include "help.h"
#include <print>
#include <stdexcept>
#include <iostream>

namespace core {
    Args::Args(int argc, char** argv) {
        for (int i{1}; i < argc; ++i) {
            std::string_view arg(argv[i]);
            if (!arg.empty() && arg.front() != '-') {
                entries.emplace_back(arg);
            } else if (arg == "-preserve" || arg == "-p") {
                preserve = true;
            } else if (arg == "-overwrite" || arg == "-o") {
                overwrite = true;
            } else if (arg == "-help" || arg == "-h") {
                help = true;
            } else {
                std::println(std::cerr, "Unknown argument: {}", arg);
                core::printHelp();
                return;
            }
        }
    }
}