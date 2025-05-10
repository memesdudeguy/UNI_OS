// kernel/process_handling.cpp
#include <vector>

enum ProcessState { RUNNING, READY, BLOCKED, TERMINATED };

struct PCB {  // Process Control Block
    int pid;
    ProcessState state;
    void* program_counter;  // Address to start execution
};

// Process table to manage processes
std::vector<PCB> process_table;

// Scheduler function
void scheduler() {
    for (auto& pcb : process_table) {
        if (pcb.state == READY) {
            pcb.state = RUNNING;
            // Simulate running the process (context switching logic here)
            // Call the process function stored in program_counter
            ((void(*)())pcb.program_counter)();
            pcb.state = READY;  // Return to ready state after running
        }
    }
}
