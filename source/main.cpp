#include "./images/images.cpp"
#include "constants.cpp"
#include "grapihics_utils.h"
#include "./headers/app_state.h"
#include "./headers/views_engine.h"
#include "./classes/app_state.cpp"
#include "./views/views_engine.cpp"
#include "./events/app_events.cpp"
#include "./content/content_pages.cpp"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;
using namespace constants;

namespace app_main
{

    int eventLoop();
    void paint();
    void keypressed(char);
    char *duplicateChar(char, int);
    void paintKeyPressBar(int);
    content_pages::Page page = content_pages::getPages(1);
    State *state = new State(1);

    int app()
    {

        cout << endl;
        ConsoleView::hideCursor();

        graphicUtils::clear();
        eventLoop();
        return 0;
    }

    char *duplicateChar(char c, int len)
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

    void keypressed(char key)
    {
        if (state->lastKey == key)
        {
            return;
        }
        state->lastKey = key;

        int keyAsInt = key - '0';
        int newPageNumber = 0;
        int highLightedAns = 0;
        for (int o = 0; o < 5; o++)
        {
            if (page.optionsNumber[o] < 1)
            {
                continue;
            }

            if (keyAsInt == (o + 1))
            {
                newPageNumber = page.optionsNumber[o];
                highLightedAns = o + 1;
            }
        }
        if (newPageNumber > 0)
        {
            state->highLightedAns = keyAsInt;
            // page = content_pages::getPages(newPageNumber);
            state->highLightedAns = highLightedAns;
            paint();
        }
    }
    void finish()
    {
        cout << "Finished, Goodbye!" << endl;
    }
    void paint()
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
            //\x1b[30m \x1b[47m //
            const char *chooseColor = "\x1b[37m"; // white

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
        paintKeyPressBar(state->carridgePos);
    };
    void paintKeyPressBar(int carriagePos)
    {
        if (carriagePos < 1)
        {
            return;
        }
        const char *block = duplicateChar(61, pow(carriagePos, 2) - (carriagePos * 3) + 4);

        cout << "\x1b[47m" << block << "\033[0m\t\t"
             << "\n\n"
             << carriagePos << "\n"
             << endl;
        // cout << block << "\n"
        //      << endl;
    }

    int eventLoop()
    {
        char keyPressed = 0, lastChar = 0;
        int lastSecond = 0;
        long keyDownTime = 0;
        int carpos = 0;
        bool runing = true;
        page = content_pages::getPages(1);
        paint();

        while (runing)
        {

            char keyPressed = app_events::getKeyPressed2();

            int sec = state->getSecondsPassed();
            lastSecond = sec;

            if (keyPressed != lastChar)
            {
                keypressed(keyPressed);
                // keyPressed = '\0';
                lastChar = keyPressed;
            }
            else if (keyPressed && keyPressed == lastChar)
            {
                keyDownTime++;

                if (keyDownTime > 1000)
                {
                    keyDownTime = 0;
                    carpos = carpos + 1;
                    state->carridgePos = carpos;
                    paint();
                }
            }
            else if (carpos > 0)
            {
                keyDownTime--;
                if (keyDownTime < -1000)
                {
                    keyDownTime = 0;
                    carpos = carpos - 1;
                    state->carridgePos = carpos;
                    paint();
                }
            }
            if (keyPressed == 'Q' || sec > 20)
            {
                finish();
                runing = false;
            }
        }

        return 0;
    };

};
int main()
{
    app_main::app();
    return 0;
}
