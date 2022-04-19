#include "./images/images.cpp"
#include "constants.cpp"
#include "grapihics_utils.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <conio.h>

const size_t BUFFER_SIZE = 1024;
int eventLoop();
int eventLoop2();

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
    graphicUtils::clear();
    eventLoop2();
    return 0;
}
int old_main()

{
    int radius{};
    int respons;

    char *inputFileName = new char[BUFFER_SIZE];

    graphicUtils::clear();
    for (int i = 1; i < 1; i++)
    {
        graphicUtils::clear();
        std::cout << "\n\n";
        std::cout << "Dungeons and Ghosts" << images::image1 << std::endl;
        std::cout << inputFileName << std::endl;
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
    return 0;
}

int keypressed(int key)
{
    std::cout << key << std::endl;
    return 0;
}
int eventLoop()
{
    int c, l, last = 0;
    char str[100];
    do
    {
        c = getchar();
        str[l] = c;
        if (c != l)
        {
            keypressed(c);
        }

    } while (c != '\n');
    return 0;
}
int eventLoop2()
{
    char a;
    do
    {
        a = getche();
        graphicUtils::clear();
        std::cout << a;

    } while (a != '\n');
    return 0;
}