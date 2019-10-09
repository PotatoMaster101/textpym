#include <iostream>
#include "textpym.hpp"

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        std::cerr << "No string provided." << std::endl;
        return 1;
    }

    std::string str;
    for (auto i = 1; i < argc; i++)
        str += std::string(argv[i]) + " ";
    std::cout << textpym(str);
    return 0;
}

