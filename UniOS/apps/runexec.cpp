#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: runexec <file.run>\n";
        return 1;
    }

    std::string cmd = "chmod +x ";
    cmd += argv[1];
    system(cmd.c_str());

    cmd = "./";
    cmd += argv[1];
    return system(cmd.c_str());
}
