#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    std::cout << "[UNI_OS] Waydroid launcher stub initializing..." << std::endl;
    std::cout << "This will later start an LXC container with Android inside ReactOS." << std::endl;

    // Placeholder for LXC launch
    // In future: system("lxc-start -n waydroid");
    std::cout << "Launching stubbed container shell..." << std::endl;

    system("cmd.exe");

    return 0;
}
