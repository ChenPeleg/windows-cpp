#ifndef VIEWS_ENGINE
#define VIEWS_ENGINE
#include <windows.h>

class ConsoleView
{
private:
    int charsPerRow;
    int numOfRows;
    char *rows[][50];

public:
    static const int maxCatridgeBarSize = 7;
    static const int ticsForKeyPress = 2000;
    ConsoleView(int charsPerRow, int numOfRows);
    ~ConsoleView();
    static void hideCursor();
    static void ShowConsoleCursor(bool showFlag);
    void trimRows();
};

#endif