#include <iostream>
#include "kernel/kernel.h"
#include "filesystem/run_executor.h"
#include "drivers/linux_drivers.h"

int main() {
    // Initialize Kernel
    Kernel::initialize();

    // Create processes
    int pid1 = Kernel::createProcess("Process1", 10);
    int pid2 = Kernel::createProcess("Process2", 5);

    // Allocate memory
    Kernel::allocateMemory(pid1, 512 * 1024 * 1024); // 512 MB
    Kernel::allocateMemory(pid2, 256 * 1024 * 1024); // 256 MB

    // Schedule processes
    Kernel::scheduleProcesses();
    Kernel::displayProcessTable();

    // Initialize Drivers
    Drivers::initializeDrivers();

    // Execute a .run file
    FileSystem::executeRunFile("example.run");

    return 0;
}