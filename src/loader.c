#include "loader.h"
#include <fstream>
#include <vector>

bool loadStageFromFile(const std::string &path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        return false; 
    }

    std::vector<unsigned char> buffer(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );
    file.close();

    if (buffer.empty()) {
        return false; 
    }

    return true;
}
