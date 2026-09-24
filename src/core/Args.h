#pragma once
#include <string_view>
#include <vector>
#include <filesystem>

namespace core {
    class Args {
        public:
            Args(int argc, char** argv);

            bool preserve{false};
            bool overwrite{false};
            bool help{false};

            std::vector<std::filesystem::path> entries;
    };
}