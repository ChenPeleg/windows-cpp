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

    void paintKeyPressBar(int);
    Page page = Page::getPages(1);
    State *state = new State(1);

    int app()
    {

        cout << endl;
        ViewEngine::hideCursor();

        graphicUtils::clear();
        eventLoop();
        return 0;
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
        paintKeyPressBar(state->carridgePos);
    };
    void paintKeyPressBar(int carriagePos)
    {
        if (carriagePos < 1)
        {
            return;
        }
        int barLenght = pow(carriagePos, 2) - ((carriagePos - 1) * 4) + 2;

        const char *block = duplicateChar(32, barLenght);

        cout << "\x1b[47m" << block << "\033[0m\t\t"
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
        page = Page::getPages(1);
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

                if (keyDownTime > ViewEngine::ticsForKeyPress)
                {
                    keyDownTime = 0;

                    if (ViewEngine::maxCatridgeBarSize > carpos)
                    {
                        carpos = carpos + 1;
                        state->carridgePos = carpos;
                        cout << carpos;
                        paint();
                    }
                }
            }
            else if (carpos > 0)
            {
                keyDownTime--;
                if (keyDownTime < (ViewEngine::ticsForKeyPress * -1))
                {
                    keyDownTime = 0;
                    if (carpos > 2)
                    {
                        carpos = carpos - 1;
                        state->carridgePos = carpos;
                        paint();
                    }
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
