#ifndef VIEWS_ENGINE
#define VIEWS_ENGINE
#include <windows.h>
#include <iostream>
#include "./app_state.h"
#include "./content_pages.h"
#include "../content/content_pages.cpp"
#include "../images/images.cpp"
#include "../images/animations1.cpp"

class ViewEngine
{
private:
    int charsPerRow;
    int numOfRows;
    char *rows[][50];
    static int GetAnimationStage(common::AnimState animationState, int numberOfStages, int durationInMs);

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
    static char *getImage(ImageEnumb image, common::AnimState animbationState = 0);

    void trimRows();
};

#endif