#pragma once
#include <filesystem>
#include "Args.h"

namespace core {
    class Corruptor {
        public:
            Corruptor(std::filesystem::path path) : m_path(path) {};
            ~Corruptor() = default;

            void corrupt(const Args& args);
        private:
            std::filesystem::path m_path;
            bool isFileValid() const {
                return std::filesystem::exists(m_path) && 
                       std::filesystem::is_regular_file(m_path) && 
                       !std::filesystem::is_directory(m_path);
            }
    };
}