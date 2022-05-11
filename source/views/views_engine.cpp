#include <windows.h>
#include <iostream>
#include <math.h>

#include "../headers/common.h"
#include "../headers/views_engine.h"
#include "../content/content_pages.cpp"
#include "../images/images.cpp"

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
void ViewEngine::paint(State *state, Page *page)
{
    bool fadeIn = false;
    bool fadeOut = false;
    if (state->animation == AnimationType::FadeIn)
    {
        fadeIn = true;
    }
    cout << "\n\n\n"
         << endl;
    graphicUtils::clear();

    char *img = getImage(page->image);
    cout << img << endl;

    cout << "\n";
    cout << page->text << endl
         << "\n_________________\n"
         << endl;
    if (fadeIn)
        Sleep(AnimationDelay);
    for (int o = 0; o < 5; o++)
    {

        const char *chooseColor = "\x1b[37m";

        if (page->optionsNumber[o] < 1)
        {
            continue;
        }
        if (state->highLightedAns == o + 1)
        {
            chooseColor = "\x1b[30m\x1b[47m";
        };

        cout << chooseColor << o + 1 << ". " << page->options[o] << " "
             << "\033[0m\t\t"
             << "\n"
             << endl;

        if (fadeIn)
            Sleep(AnimationDelay);
    }
    ViewEngine::paintKeyPressBar(state->carridgePos);
};
void ViewEngine::paintKeyPressBar(int carriagePos)
{
    bool isArrowAnimation = true;

    const char *arrow = ">>========>";

    if (carriagePos < 1)
    {
        return;
    };

    int barLenght = pow(carriagePos, 2) - ((carriagePos - 1) * 4) + 2;

    const char *block = duplicateChar(32, barLenght);
    if (isArrowAnimation)
    {
        const char *emptySpaces = duplicateChar(32, barLenght - 2);

        cout << emptySpaces << arrow << "\033[0m\t\t"
             << endl;
        delete emptySpaces;
    }
    else
    {

        cout << "\x1b[47m" << block << "\033[0m\t\t" << endl;

        delete block;
    }
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
char *ViewEngine::getImage(ImageEnumb image)
{
    switch (image)
    {
    case ImageEnumb::fighter:
        return ViewEngine::proccessImage(images::fighter);
    case ImageEnumb::mage:
        return ViewEngine::proccessImage(images::mage);
    case ImageEnumb::none:
    default:
        return ViewEngine::proccessImage(images::none);
    }
};
char *ViewEngine::proccessImage(const char *rawImage)
{
    int linesWithEmptySpaces = 0;
    int rowsWithText = 0;
    int emptySpaces = 100;
    int thisRowEmptySpaces = 0;
    bool allStartingCharsSpaces = true;
    int overallSize = common::string_size(rawImage);

    for (int i = 0; i < overallSize; i++)
    {
        char c = rawImage[i];

        if (c == '\n')
        {
            bool isConsecutiveNewLinse = false;
            if (i < 0 && rawImage[i - 1] == '\n')
            {
                isConsecutiveNewLinse = true;
            }
            if (!isConsecutiveNewLinse)
            {
                if (emptySpaces > thisRowEmptySpaces)
                {
                    emptySpaces = thisRowEmptySpaces;
                }
                linesWithEmptySpaces++;
            }
            thisRowEmptySpaces = 0;
            allStartingCharsSpaces = true;
        }
        else if (allStartingCharsSpaces && c == ' ')
        {
            thisRowEmptySpaces++;
        }
        else
        {
            allStartingCharsSpaces = false;
        }
    }
    int newSize = overallSize - (emptySpaces * linesWithEmptySpaces);

    char *newImage = new char[newSize + 1];
    linesWithEmptySpaces = 0;
    thisRowEmptySpaces = 0;
    allStartingCharsSpaces = true;
    int newImageIndex = 0;

    for (int i = 0; i < overallSize; i++)
    {

        const char c = rawImage[i];
        bool addToNewImage = true;
        if (c == '\n')
        {
            linesWithEmptySpaces++;
            thisRowEmptySpaces = 0;
            allStartingCharsSpaces = true;
        }
        else if (allStartingCharsSpaces && c == ' ' && thisRowEmptySpaces < emptySpaces)
        {
            thisRowEmptySpaces++;
            addToNewImage = false;
        }
        else
        {
            allStartingCharsSpaces = false;
        }

        if (addToNewImage)
        {
            newImage[newImageIndex] = c;
            newImageIndex++;
        }
    }
    newImage[newImageIndex] = '\0';
    return newImage;
};

void ViewEngine::trimRows(){};
