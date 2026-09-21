#include "Args.h"
#include <stdexcept>

namespace core {
    Args::Args(int argc, char** argv) {
        for (int i = 1; i < argc; ++i) {
            std::string_view arg(argv[i]);
            if (!arg.empty() && arg.front() != '-') {
                enteries.emplace_back(arg);
            } else if (m_args.find(arg) != m_args.end()) {
                preserve = true;
            } else {
                throw std::invalid_argument("Unknown argument: " + std::string(arg));
            }
        }
    }
}