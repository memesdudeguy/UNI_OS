#include <iostream>
#include <fstream>
#include "run_executor.h"

namespace FileSystem {
    void executeRunFile(const std::string& filePath) {
        std::ifstream runFile(filePath);

        if (!runFile) {
            std::cerr << "[FileSystem] Error: Unable to open .run file: " << filePath << std::endl;
            return;
        }

        std::cout << "[FileSystem] Executing .run file: " << filePath << std::endl;
        std::string line;
        while (std::getline(runFile, line)) {
            std::cout << "[FileSystem] " << line << std::endl;
            // Placeholder: Interpret and execute commands in .run file
        }

        runFile.close();
    }
}