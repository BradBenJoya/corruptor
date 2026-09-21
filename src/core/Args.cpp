#include "Args.h"
#include <stdexcept>

namespace core {
    Args::Args(int argc, char** argv) {
        for (int i{1uz}; i < argc; ++i) {
            std::string_view arg(argv[i]);
            if (!arg.empty() && arg.front() != '-') {
                enteries.emplace_back(arg);
            } else if (arg == "-preserve" || arg == "-p") {
                preserve = true;
            } else if (arg == "-overwrite" || arg == "-o") {
                overwrite = true;
            } else {
                throw std::invalid_argument("Unknown argument: " + std::string(arg));
            }
        }
    }
}