#include "Corruptor.h"
#include <fstream>

namespace core {
    void Corruptor::corrupt() {
        std::ofstream out(m_path += ".corrupted");
        out.write("i cowuppted the fwile mu heheheheheh", 29);
    }
}