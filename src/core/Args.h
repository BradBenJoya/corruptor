#pragma once
#include <unordered_set>
#include <string_view>

namespace core {
    class Args {
        public:
            Args(int argc, char** argv);
            bool preserve{false};
        private:
            std::unordered_set<std::string_view> m_args {
            {"-preserve", "-p"}
        };
    };
}