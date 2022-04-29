
#include "../headers/views_engine.h"

ConsoleView::ConsoleView(int charsPerRow, int numOfRows)
{
    this->charsPerRow = charsPerRow;
    this->numOfRows = numOfRows;
    // this->rows
};
ConsoleView::~ConsoleView(){

};
void ConsoleView::hideCursor()
{
    ConsoleView::ShowConsoleCursor(false);
};
void ConsoleView::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
};

void ConsoleView::trimRows(){};
