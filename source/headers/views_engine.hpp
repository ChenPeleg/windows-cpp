#ifndef VIEWS_ENGINE
#define VIEWS_ENGINE
#include <windows.h>
#include <iostream>
#include "./app_state.hpp"
#include "./content_pages.hpp"
#include "./combat_state.hpp"
#include "../images/images.cpp"
#include "../images/asciiWords.cpp"
#include "../images/animations1.cpp"
#include "content_monsters.hpp"
#include "monster.hpp"

class ViewEngine
{
private:
    int charsPerRow;
    int numOfRows;
    char *rows[][50];
    static int getStageClockTicks(common::ClockTicksState animationState, int numberOfStages, int durationInMs);
    static void paintCombatButtons(combatController::CombatState *combat);
    static void paintUpperStatusBar(State *state);
    static void paintMosterStatusBar(Monster *monster);
    static void paintCombatMessage(combatController::CombatState *combat, State *state);

public:
    static const int maxCatridgeBarSize = 8; // Original 9 // for debugging 7
    static const int minCatridgeBarSize = 1;
    static const int ticsForKeyPress = 3000; // 3000 as default
    ViewEngine(int charsPerRow, int numOfRows);
    ~ViewEngine();
    static void hideCursor();
    static void paint(State *state, Page *page);
    static void paintKeyPressBar(int carriagePos);
    static void ShowConsoleCursor(bool showFlag);
    static char *duplicateChar(char c, int len);
    static char *proccessImage(const char *);
    static char *getImage(ImageEnumb image, common::ClockTicksState animbationState = 0);
    static char *getTextImage(AsciiWordsEnumb asciiWord, common::ClockTicksState animbationState = 0);

    void trimRows();
};

#endif