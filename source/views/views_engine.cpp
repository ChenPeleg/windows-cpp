#include <windows.h>
#include <iostream>
#include <math.h>
#include <iomanip>

#include "../headers/common.hpp"
#include "../headers/combat_state.hpp"
#include "../headers/views_engine.hpp"
#include "../images/images.cpp"

using namespace std;
using namespace common;

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
void ViewEngine::paintCombatButtons(combatController::CombatState *combat)
{
    const int spaceBetweenLenght = 3;
    const int buttonLength = 10;
    // cout << "  " << combat->highlightPosition;
    for (int btn = 0; btn < combatController::numberOfButtons; btn++)
    {
        char btnText[11];
        cout << (btn == 0 ? "" : "  ");
        if (combat->highlightPosition == btn)
        {
            cout << "\x1b[30m\x1b[47m";
        }
        switch (combat->currentButtons[btn])
        {
        case common::CombatButtonType::Attack:
            cout << " Attack ";
            break;
        case common::CombatButtonType::noop:
            cout << "   " << btn + 1 << "   ";
            break;
        case common::CombatButtonType::Block:
            cout << " Block  ";
            break;
        case common::CombatButtonType::Dodge:
            cout << " Dodge  ";
            break;
        }
        if (combat->highlightPosition == btn)
        {
            cout << "\033[0m";
        }
    }
    cout << endl;
}
void ViewEngine ::paintUpperStatusBar(State *state)
{
    cout << "HP " << state->HP << "/" << state->maxHP << "\n";
}
void ViewEngine ::paintMosterStatusBar(Monster *monster)
{
    cout << (*monster).name << " HP " << (*monster).HP << "/" << (*monster).maxHP << '\n';
}
void ViewEngine ::paintCombatMessage(combatController::CombatState *combat)
{
    // getTextImage(asciiImages::AsciiWordsEnumb::hit);
    // // cout << *combat->monsterName << " HP ";
}
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
    paintUpperStatusBar(state);
    char *img = page->isFight ? getImage(state->combat->monster.monsterImage) : getImage(page->image, state->animationState);
    cout << img << endl;

    if (page->isFight)
    {
        paintMosterStatusBar(&(state->combat->monster));
        paintCombatMessage((*state).combat);
        char *textImage = getTextImage(asciiImages::AsciiWordsEnumb::dodge);
        cout << textImage;
    }
    else
    {
        cout << "\n";
    }

    cout << page->text << endl
         << "_________________\n"
         << endl;
    if (fadeIn)
        Sleep(AnimationDelay);

    if (page->isFight)
    {

        paintCombatButtons(state->combat);
        return;
    }
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

int ViewEngine::getStageClockTicks(common::ClockTicksState clockTicksState, int numberOfStages, int durationOfTickInMs)
{
    return common::getStageClockTicks(clockTicksState, numberOfStages, durationOfTickInMs);
};
char *ViewEngine::getImage(ImageEnumb image, ClockTicksState animationsState)
{
    // int stage = GetAnimationStage(animationsState, 3, 500);
    // cout << "\n\n"
    //      << stage << "\n\n";
    switch (image)
    {
    case ImageEnumb::fighter:
        return ViewEngine::proccessImage(images::fighter);
    case ImageEnumb::mage:
        return ViewEngine::proccessImage(images::mage);
    case ImageEnumb::mageAnimation:
    {
        int stage = getStageClockTicks(animationsState, 10, 100);
        switch (stage)
        {
        case 0:
        case 9:
            return ViewEngine::proccessImage(images::mageA0);
            break;
        case 8:
        case 1:
            return ViewEngine::proccessImage(images::mageA1);
            break;

        case 2:
        case 7:
            return ViewEngine::proccessImage(images::mageA2);
            break;
        case 3:
        case 6:
            return ViewEngine::proccessImage(images::mageA3);
            break;
        case 4:
        case 5:
            return ViewEngine::proccessImage(images::mageA4);
            break;

        default:
            return ViewEngine::proccessImage(images::mage);
            break;
        }
        return ViewEngine::proccessImage(images::mageA0);
        break;
    }
    case ImageEnumb::manPickingFromTree:
        return ViewEngine::proccessImage(images::manPickingFromTree);
    case ImageEnumb::manWalkingSun:
        return ViewEngine::proccessImage(images::manWalkingSun);
    case ImageEnumb::elephant:
        return ViewEngine::proccessImage(images::elephant);
    case ImageEnumb::skeleton:
        return ViewEngine::proccessImage(images::skeleton);
    case ImageEnumb::skull:
        return ViewEngine::proccessImage(images::skull);
    case ImageEnumb::blobMonster:
        return ViewEngine::proccessImage(images::blobMonser);
    case ImageEnumb::ghost:
        return ViewEngine::proccessImage(images::ghost);
    case ImageEnumb::worm:
        return ViewEngine::proccessImage(images::worm);

    case ImageEnumb::none:

    default:
        return ViewEngine::proccessImage(images::none);
    }
};
char *ViewEngine::getTextImage(AsciiWordsEnumb image, ClockTicksState animationsState)
{

    switch (image)
    {
    case AsciiWordsEnumb::blocked:
        return ViewEngine::proccessImage(images::Wblocked);
    case AsciiWordsEnumb::hit:
        return ViewEngine::proccessImage(images::Whit);
    case AsciiWordsEnumb::youWin:
        return ViewEngine::proccessImage(images::WyouWin);
    case AsciiWordsEnumb::dodge:
        return ViewEngine::proccessImage(images::Wdodge);

    case AsciiWordsEnumb::noword:
    default:
        return ViewEngine::proccessImage("");
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
            if (i > 0 && rawImage[i - 1] == '\n')
            {
                isConsecutiveNewLinse = true;
            }
            else if (i == 0)
            {
                isConsecutiveNewLinse = true;
            }

            if (!isConsecutiveNewLinse)
            {
                bool considerThisRow = true;
                if (isConsecutiveNewLinse)
                {
                    considerThisRow = false;
                }
                if (considerThisRow && emptySpaces > thisRowEmptySpaces)
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
            if (thisRowEmptySpaces > 10)
            {
                int c1 = thisRowEmptySpaces;
            }
        }
        else
        {
            allStartingCharsSpaces = false;
        }
    }
    if (emptySpaces > 99)
    {
        emptySpaces = 0;
    }
    if (emptySpaces > 2)
    {
        emptySpaces--;
    }
    int newSize = overallSize - (emptySpaces * linesWithEmptySpaces);
    if (newSize > overallSize)
    {
        throw "new size of image is larger than old size";
    }
    if (overallSize > 200)
    {
        int c = newSize;
    }

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
