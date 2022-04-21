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
    int keypressed(char);
    char *duplicateChar(char, int);
    app_state::State *state = new app_state::State(10);

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

    int keypressed(char key)
    {
        cout << key << endl;
        graphicUtils::clear();
        char *multichar = duplicateChar(key, rowLength);
        for (int y = 0; y < 10; y++)
        {
            for (int i = 0; i < rowLength; i++)
            {
                cout << multichar[i];
            }
            cout << endl;
        }

        cout << key << endl;

        return 0;
    }
    void finish()
    {
        cout << "Finished, Goodbye!" << endl;
    }

    int eventLoop()
    {
        char keyPressed, lastChar;
        int lastSecond;
        bool runing = true;
        // content_pages::Page *currentPage = content_pages::pages[0];Page

        // cout << content_pages::pages[0]->text << endl;
        //   cout << images::mage << endl;

        cout
            << "\x1B[31mRED\033[0m\t\t";
        printf("\x1B[32mTexting\033[0m\t\t");
        printf("\x1B[33mTexting\033[0m\t\t");
        while (runing)
        {

            char keyPressed = app_events::getKeyPressed2();
            int sec =
                state->getSecondsPassed();
            if (sec != lastSecond)
            {
                // cout << " " << sec << "    ";
            }
            lastSecond = sec;

            if (keyPressed != lastChar)
            {
                cout << " \n pressed:" << keyPressed << endl;
                lastChar = keyPressed;
                if (keyPressed == '1')
                {
                    graphicUtils::clear();
                    cout << images::mage << endl;
                }
                if (keyPressed == '2')
                {
                    graphicUtils::clear();
                    cout << images::fighter << endl;
                }
                // keypressed(keyPressed);
            }
            if (keyPressed == 'Q' || sec > 10)
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
