#include <print>
#include "core/Corruptor.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::println("Usage: {} <file_to_corrupt>", argv[0]);
        return 1;
    }

    core::Corruptor corruptor{argv[1]};
    corruptor.corrupt();

    return 0;
}