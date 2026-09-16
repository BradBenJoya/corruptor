#include "Corruptor.h"
#include "Randomizer.h"

#include <cctype>
#include <fstream>
#include <stdexcept>

namespace core {
void Corruptor::corrupt() {
    const std::filesystem::path output_path = m_path.string() + ".corrupted";

    std::ifstream input(m_path, std::ios::binary);
    if (!input.is_open()) {
        throw std::runtime_error("File not found: " + m_path.string());
    }

    std::ofstream output(output_path, std::ios::binary);
    if (!output.is_open()) {
        throw std::runtime_error("Failed to create output file: " + output_path.string());
    }

    char c = 0;
    while (input.get(c)) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            const std::size_t random_byte = Randomizer{}.getRandomNumber(0, 255);
            output.put(static_cast<char>(random_byte));
        } else {
            output.put(c);
        }
    }
}
}