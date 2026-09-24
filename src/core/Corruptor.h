#pragma once
#include <filesystem>
#include "Args.h"
#include "Randomizer.h"

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
                       std::filesystem::is_regular_file(m_path);
            }

            std::uint8_t getRandomByte() {
                return static_cast<std::uint8_t>(m_randomizer.getRandomNumber(0, 255));
            }

            Randomizer m_randomizer;
    };
}