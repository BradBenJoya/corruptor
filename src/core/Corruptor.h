#pragma once
#include <filesystem>
namespace core {
    class Corruptor {
        public:
            Corruptor(std::filesystem::path path) : m_path(path) {};
            ~Corruptor() = default;

            void corrupt();
        private:
            std::filesystem::path m_path;
    };
}