#include "./images/images.cpp"
#include "constants.cpp"
#include "grapihics_utils.h"
#include "./classes/app_state.hpp"
#include "./events/app_events.cpp"
#include "./content/content_pages.cpp"
#include <windows.h>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace constants;
namespace app_main
{

    int eventLoop();
    void paint();
    void keypressed(char);
    char *duplicateChar(char, int);
    content_pages::Page page = content_pages::getPages(1);
    app_state::State *state = new app_state::State(1);

    int app()
    {

        // app_state::State state(10);

        cout << endl;
        graphicUtils::clear();
        eventLoop();
        return 0;
    }

    char *duplicateChar(char c, int len)
    {
        char *newChar = new char[len];
        for (int i = 0; i < len; i++)
        {
            newChar[i] = c;
        }
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
        for (int o = 0; o < 5; o++)
        {
            if (page.optionsNumber[o] < 1)
            {
                continue;
            }

            if (keyAsInt == (o + 1))
            {
                newPageNumber = page.optionsNumber[o];
            }

            // cout << page.options[o] << "\n\n"
            //      << endl;
        }
        if (newPageNumber > 0)
        {
            state->highLightedAns = keyAsInt;
            page = content_pages::getPages(newPageNumber);
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
            if (page.optionsNumber[o] < 1)
            {
                continue;
            }
            cout << o + 1 << ". " << page.options[o] << "\n"
                 << endl;
        }
        // cout << page.options[0]21
    };
    int eventLoop()
    {
        char keyPressed, lastChar;
        int lastSecond;
        bool runing = true;
        page = content_pages::getPages(1);
        paint();
        // content_pages::Page *currentPage = content_pages::pages[0];Page

        //   cout << images::mage << endl;

        // cout
        //     << "\x1B[31mRED\033[0m\t\t";
        // printf("\x1B[32mTexting\033[0m\t\t");
        // printf("\x1B[33mTexting\033[0m\t\t");
        while (runing)
        {

            char keyPressed = app_events::getKeyPressed2();

            int sec = state->getSecondsPassed();
            lastSecond = sec;

            if (keyPressed != lastChar)
            {
                keypressed(keyPressed);
                keyPressed = '\0';
                lastChar = keyPressed;
                // cout << " \n pressed:" << keyPressed << endl;
                // lastChar = keyPressed;
                // if (keyPressed == '1')
                // {
                //     graphicUtils::clear();
                //     cout << images::mage << endl;
                // }
                // if (keyPressed == '2')
                // {
                //     graphicUtils::clear();
                //     cout << images::fighter << endl;
                // }
                //
            }
            if (keyPressed == 'Q' || sec > 20)
            {
                finish();
                runing = false;
            }
        }

        return 0;
    }

}
int main()
{
    app_main::app();
    return 0;
}
