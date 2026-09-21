#include "Corruptor.h"
#include "Randomizer.h"
#include "Args.h"

#include <cctype>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <print>

namespace core {
    void Corruptor::corrupt(const Args& args) {
        const std::filesystem::path output_path = m_path.string() + ".corrupted";

        if (!isFileValid()) {
            throw std::runtime_error("File is invalid or a directory in path: " + m_path.string());
        }

        std::ifstream input(m_path, std::ios::binary);
        if (!input.is_open()) {
            throw std::runtime_error("Failed to open input file: " + m_path.string());
        }

        std::ofstream output(output_path, std::ios::binary);
        if (!output.is_open()) {
            throw std::runtime_error("Failed to create output file: " + output_path.string());
        }

        std::println("Corrupting file: {} -> {}", m_path.string(), output_path.string());

        char c{0};
        while (input.get(c)) {
            if (args.preserve) {
                if (std::isalnum(static_cast<unsigned char>(c))) {
                    const std::size_t random_byte = Randomizer{}.getRandomNumber(0, 255);
                    output.put(static_cast<char>(random_byte));
                } else {
                    output.put(c);
                }
            } else {
                const std::size_t random_byte = Randomizer{}.getRandomNumber(0, 255);
                output.put(static_cast<char>(random_byte));
            }
        }

        std::println("File corrupted successfully: {}", output_path.string());
    }
}