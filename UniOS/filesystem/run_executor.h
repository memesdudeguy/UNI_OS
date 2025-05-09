#ifndef UNI_OS_RUN_EXECUTOR_H
#define UNI_OS_RUN_EXECUTOR_H

#include <string>

namespace FileSystem {
    // Parse and execute .run files
    void executeRunFile(const std::string& filePath);
}

#endif // UNI_OS_RUN_EXECUTOR_H