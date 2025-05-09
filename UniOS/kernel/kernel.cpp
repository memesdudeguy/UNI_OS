#include <iostream>
#include <vector>
#include <algorithm> // Add this line to include std::sort
#include "kernel.h"

namespace Kernel {
    static std::vector<Process> processTable;
    static const size_t totalMemory = 1024 * 1024 * 1024; // 1GB
    static size_t allocatedMemory = 0;

    void initialize() {
        std::cout << "[Kernel] Initializing UNI-OS Kernel..." << std::endl;
        initializeMemory();
    }

    void initializeMemory() {
        std::cout << "[Kernel] Total available memory: " << totalMemory / (1024 * 1024) << " MB" << std::endl;
    }

    int createProcess(const std::string& name, int priority) {
        static int nextPid = 1;
        Process newProcess = { nextPid++, name, priority };
        processTable.push_back(newProcess);
        std::cout << "[Kernel] Process created: " << newProcess.name << " with PID " << newProcess.pid << std::endl;
        return newProcess.pid;
    }

    void scheduleProcesses() {
        std::cout << "[Kernel] Scheduling processes based on priority..." << std::endl;
        std::sort(processTable.begin(), processTable.end(), [](const Process& a, const Process& b) {
            return a.priority > b.priority;
        });
    }

    void displayProcessTable() {
        std::cout << "[Kernel] Process Table:" << std::endl;
        for (const auto& process : processTable) {
            std::cout << "PID: " << process.pid << ", Name: " << process.name << ", Priority: " << process.priority << std::endl;
        }
    }

    void allocateMemory(int processId, size_t size) {
        if (allocatedMemory + size > totalMemory) {
            std::cout << "[Kernel] Memory allocation failed for PID " << processId << ". Not enough memory." << std::endl;
            return;
        }
        allocatedMemory += size;
        std::cout << "[Kernel] Allocated " << size / (1024 * 1024) << " MB to PID " << processId << ". Total allocated: " << allocatedMemory / (1024 * 1024) << " MB." << std::endl;
    }

    void freeMemory(int processId) {
        // For simplicity, free all memory for the process (mock implementation)
        allocatedMemory = 0;
        std::cout << "[Kernel] Freed all memory for PID " << processId << ". Total allocated: " << allocatedMemory / (1024 * 1024) << " MB." << std::endl;
    }
}