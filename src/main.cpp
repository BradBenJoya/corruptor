#include "core/Corruptor.h"
#include "core/Args.h"
#include "core/help.h"

int main(int argc, char** argv) {
    core::Args args(argc, argv);
    if (args.help) {
        core::printHelp();
        return 0;
    }

    if (args.entries.empty()) {
        core::printHelp();
        return 1;
    }

    for (const auto& entry : args.entries) {
        core::Corruptor corruptor{entry};
        corruptor.corrupt(args);
    }

    return 0;
}