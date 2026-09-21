#pragma once
#include <unordered_set>
#include <string_view>
#include <stdexcept>

class Args {
    public:
        Args(int argc, char** argv) {
        for (int i{1}; i < argc; ++i) {
            if (!m_args.contains(argv[i])) {
                throw std::invalid_argument("Invalid argument: " + std::string(argv[i]));
            } else if (argv[i] == std::string_view("-preserve") || argv[i] == std::string_view("-p")) {
                preserve = true;
            }
        }
    }
    bool preserve{false};
    private:
        std::unordered_set<std::string_view> m_args {
        {"-preserve", "-p"}
    };
};