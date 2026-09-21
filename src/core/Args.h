#pragma once
#include <unordered_set>
#include <string_view>
#include <vector>
#include <filesystem>

namespace core {
    class Args {
        public:
            Args(int argc, char** argv);

            bool preserve{false};
            bool overwrite{false};

            std::vector<std::filesystem::path> enteries;
        private:
            std::unordered_set<std::string_view> m_args {
            "-preserve", "-p",
            "-overwrite", "-o"
        };
    };
}