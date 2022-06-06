
#include <windows.h>

#ifndef GRAPHIC_UTILS
#define GRAPHIC_UTILS

// define your own namespace to hold constants
namespace graphicUtils
{
    enum ConsoleColor
    {
        reset,
        blackBGWhite,
        whiteBGRed,
        whiteBGBlue,
        whiteBGGreen

    };
    void
    clear()
    {
        COORD topLeft = {0, 0};
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
        FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
        SetConsoleCursorPosition(console, topLeft);
    }
    const char *getColorText(ConsoleColor conClr)
    {
        switch (conClr)
        {
        case ConsoleColor::reset:
            return "\033[0m";
        case ConsoleColor::blackBGWhite:
            return "\x1b[30m\x1b[47m";
        case ConsoleColor::whiteBGRed:
            return "\x1b[37m\x1b[41m";
        case ConsoleColor::whiteBGBlue:
            return "\x1b[37m\x1b[44m";
        case ConsoleColor::whiteBGGreen:
            return "\x1b[37m\x1b[42m";
        default:
            return "";
        }
    }
}

#endif