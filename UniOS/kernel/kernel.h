#ifndef UNI_OS_KERNEL_H
#define UNI_OS_KERNEL_H

#include <string>
#include <vector>

namespace Kernel {
    // Process structure
    struct Process {
        int pid;                     // Process ID
        std::string name;            // Process name
        int priority;                // Priority of the process
    };
    
    // Initialize the kernel
    void initialize();

    // Create and manage processes
    int createProcess(const std::string& name, int priority);
    void scheduleProcesses();
    void displayProcessTable();

    // Memory management
    void initializeMemory();
    void allocateMemory(int processId, size_t size);
    void freeMemory(int processId);
}

#endif // UNI_OS_KERNEL_H