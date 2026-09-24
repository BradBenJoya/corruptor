#include "help.h"
#include <print>

namespace core {
void printHelp() {
    std::println("Usage: corrupter [options] <file_to_corrupt>...");
    std::println("Arguments:");
    std::println("  -preserve, -p   Preserve non-alphanumeric characters");
    std::println("  -overwrite, -o  Overwrite the original file after confirmation");
    std::println("  -help, -h       Show this help message");
}
}