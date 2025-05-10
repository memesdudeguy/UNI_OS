#include <iostream>
#include <map>

enum SysCall {
    PRINT = 1,
    EXIT,
    ALLOC_MEMORY,
    FREE_MEMORY,
};

std::map<int, void(*)()> syscalls;

void print_message() {
    std::cout << "System Call: Print message" << std::endl;
}

void exit_program() {
    std::cout << "System Call: Exit program" << std::endl;
    exit(0);
}

void allocate_memory() {
    std::cout << "System Call: Allocate memory" << std::endl;
    // You can add memory allocation code here (e.g., using `new` or `malloc`)
}

void free_memory() {
    std::cout << "System Call: Free memory" << std::endl;
    // Free memory if allocated (e.g., using `delete` or `free`)
}

void syscall_handler(int syscall_number) {
    if (syscalls.find(syscall_number) != syscalls.end()) {
        syscalls[syscall_number]();
    } else {
        std::cout << "Invalid System Call" << std::endl;
    }
}

extern "C" void kernel_main() {
    // Register system calls
    syscalls[PRINT] = &print_message;
    syscalls[EXIT] = &exit_program;
    syscalls[ALLOC_MEMORY] = &allocate_memory;
    syscalls[FREE_MEMORY] = &free_memory;

    // Simulate a system call for testing
    syscall_handler(PRINT);  // Prints message
    syscall_handler(EXIT);   // Exits the program
}
