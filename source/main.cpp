#include "constants.h" // include a copy of each constant in this file
#include <iostream>

int main()
{
    int radius{};
    int respons;
    int e = constants::eight();
    printf("\033c");
    std::cout << "\n\n\n";
    std::cout << "Hello World! eight is 1 " << e << std::endl;
    std::cout << "answer one question " << std::endl;
    std::cin >> respons;
}