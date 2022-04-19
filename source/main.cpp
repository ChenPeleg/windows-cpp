#include "./images/images.cpp"
#include "constants.cpp"
#include "grapihics_utils.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <conio.h>

using namespace std;
using namespace constants;

int eventLoop();

int main()
{
    cout << endl;
    graphicUtils::clear();
    eventLoop();
    return 0;
}

char *duplicateChar(char c, int len)
{
    char *newChar = new char[len];
    for (int i = 0; i < len; i++)
    {
        newChar[i] = c;
    }
    return newChar;
}

int keypressed(char key)
{
    cout << key << endl;
    graphicUtils::clear();
    char *multichar = duplicateChar(key, rowLength);
    for (int y = 0; y < 10; y++)
    {
        for (int i = 0; i < rowLength; i++)
        {
            cout << multichar[i];
        }
        cout << endl;
    }

    cout << key << endl;

    return 0;
}

int eventLoop()
{
    char a;
    do
    {
        char a = getche();
        keypressed(a);

    } while (a != '\n');
    return 0;
}