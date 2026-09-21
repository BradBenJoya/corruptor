#include "Corruptor.h"
#include "Randomizer.h"
#include "Args.h"

#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <print>

namespace core {
    void Corruptor::corrupt(const Args& args) {
        const std::filesystem::path output_path = args.overwrite
            ? m_path
            : std::filesystem::path{m_path.string() + ".corrupted"};

        if (!isFileValid()) {
            throw std::runtime_error("File is invalid or a directory in path: " + m_path.string());
        }

        if (args.overwrite) {
            std::println("WARNING: this will overwrite {}", m_path.string());
            std::print("Continue? [Y/N]: ");

            char confirmation{0};
            std::cin >> confirmation;
            if (confirmation != 'y' && confirmation != 'Y') {
                std::println("Operation cancelled.");
                return;
            }

            std::fstream file(m_path, std::ios::in | std::ios::out | std::ios::binary);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file: " + m_path.string());
            }

            std::println("Corrupting file: {} -> {}", m_path.string(), output_path.string());

            char c{0};
            while (file.get(c)) {
                const std::streampos position = file.tellg();
                const char corrupted = args.preserve && !std::isalnum(static_cast<unsigned char>(c))
                    ? c
                    : static_cast<char>(Randomizer{}.getRandomNumber(0, 255));
                file.seekp(position - std::streamoff{1});
                file.put(corrupted);
                file.flush();
                file.seekg(position);
            }

            std::println("File corrupted successfully: {}", output_path.string());
            return;
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