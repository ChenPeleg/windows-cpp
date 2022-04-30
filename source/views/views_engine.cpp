#include <windows.h>
#include <iostream>
#include <math.h>

#include "../headers/views_engine.h"
#include "../content/content_pages.cpp"

using namespace std;

ViewEngine::ViewEngine(int charsPerRow, int numOfRows)
{
    this->charsPerRow = charsPerRow;
    this->numOfRows = numOfRows;
};
ViewEngine::~ViewEngine(){

};
void ViewEngine::hideCursor()
{
    ViewEngine::ShowConsoleCursor(false);
};
void ViewEngine::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
};
void ViewEngine::paint(State *state, Page page)
{
    cout << "\n\n\n"
         << endl;
    graphicUtils::clear();
    cout << "\n\n\n";
    cout << page.text << endl
         << "\n_________________\n"
         << endl;

    for (int o = 0; o < 5; o++)
    {

        const char *chooseColor = "\x1b[37m";

        if (page.optionsNumber[o] < 1)
        {
            continue;
        }
        if (state->highLightedAns == o + 1)
        {
            chooseColor = "\x1b[30m\x1b[47m";
        };

        cout << chooseColor << o + 1 << ". " << page.options[o] << " "
             << "\033[0m\t\t"
             << "\n"
             << endl;
    }
    ViewEngine::paintKeyPressBar(state->carridgePos);
};
void ViewEngine::paintKeyPressBar(int carriagePos)
{
    if (carriagePos < 1)
    {
        return;
    }
    int barLenght = pow(carriagePos, 2) - ((carriagePos - 1) * 4) + 2;

    const char *block = duplicateChar(32, barLenght);

    cout << "\x1b[47m" << block << "\033[0m\t\t"
         << endl;
};
char *ViewEngine::duplicateChar(char c, int len)
{
    int i;
    char *newChar = new char[len];
    for (i = 0; i < len; i++)
    {
        newChar[i] = c;
    }
    newChar[i] = '\0';
    return newChar;
}

void ViewEngine::trimRows(){};
