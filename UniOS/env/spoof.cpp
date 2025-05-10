#include <iostream>
#include <cstring>

void spoof_kernel() {
    // Fake uname to simulate different kernel (e.g., Windows 11)
    std::string kernel_version = "Linux 5.15.0-UNI-OS";
    std::cout << "Kernel: " << kernel_version << std::endl;
}

int main() {
    spoof_kernel();
    return 0;
}
