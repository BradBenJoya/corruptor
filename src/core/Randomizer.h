#pragma once
#include <random>
namespace core {
    class Randomizer {
        public:
            Randomizer() = default;
            ~Randomizer() = default;

            std::size_t getRandomNumber(std::size_t min, std::size_t max) {
                std::uniform_int_distribution<std::size_t> dist(min, max);
                return dist(m_gen);
            }

        private:
            std::random_device m_rd;
            std::mt19937 m_gen{m_rd()};
    };
}