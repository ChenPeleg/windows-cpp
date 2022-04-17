#include "./images/images.cpp"
#include "constants.cpp"
#include "grapihics_utils.h"
#include <windows.h>
#include <iomanip>
#include <iostream>

const size_t BUFFER_SIZE = 1024;
bool checkExit(char *stringToCheck)
{
    char exitString[5] = "exit";
    bool isExit = true;
    for (int i = 0; i < 5; i++)
    {
        if (stringToCheck[i] != exitString[i])
        {
            isExit = false;
        }
    }
    return isExit;
}

int main()
{
    int radius{};
    int respons;

    char *inputFileName = new char[BUFFER_SIZE];

    graphicUtils::clear();
    for (int i = 1; i < 100; i++)
    {
        graphicUtils::clear();
        std::cout << "\n\n\n";
        std::cout << "Hello World! is 1 " << images::image1 << std::endl;
        std::cout << inputFileName << std::endl;
        std::cout << inputFileName << std::endl;
        std::cout << inputFileName << std::endl;
        std::cout << "answer one question " << std::endl;
        std::cin >> std::setw(BUFFER_SIZE) >> inputFileName;
        if (checkExit(inputFileName))
        {
            std::cout << "Goodbye!" << std::endl;
            i = 100;
            break;
        }
    }
    delete[] inputFileName;
}