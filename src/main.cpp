#include <print>
#include "core/Corruptor.h"
#include "core/Args.h"

int main(int argc, char** argv) {
    core::Args args(argc, argv);
    if (args.entries.empty()) {
        std::println("Usage: {} <file_to_corrupt>...", argv[0]);
        return 1;
    }

    for (const auto& entry : args.entries) {
        core::Corruptor corruptor{entry};
        corruptor.corrupt(args);
    }

    return 0;
}