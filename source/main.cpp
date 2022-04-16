#include "constants.h"
#include "grapihics_utils.h"
#include <windows.h>
#include <iostream>

int main()
{
    int radius{};
    int respons;
    int e = constants::eight();

    graphicUtils::clear();
    for (int i = 1; i < 3; i++)
    {
        std::cout << "\n\n\n";
        std::cout << "Hello World! eight is 1 " << e << std::endl;
        std::cout << "answer one question " << std::endl;
        std::cin >> respons;
        graphicUtils::clear();
    }
}