

#include "./headers/constants.h"
#include "./headers/app_state.h"
#include "./headers/views_engine.h"
#include "./headers/common.h"

#include "grapihics_utils.h"
#include "./classes/app_state.cpp"
#include "./views/views_engine.cpp"
#include "./events/app_events.cpp"
#include "./content/content_pages.cpp"
#include "./images/images.cpp"

#include <windows.h>
#include <iostream>

using namespace std;
using namespace constants;
using namespace common;

class AppMain
{
    // int eventLoop();
    // void optionWasPressed(char);
    // void paintKeyPressBar(int);
    // void paintContent();
    // int getOptionFromKeyPressed(char key);
public:
    int start()
    {

        cout << endl;
        ViewEngine::hideCursor();
        graphicUtils::clear();
        paintContent();
        eventLoop();
        return 0;
    };

private:
    Page page = Page::getPages(1);
    State *state = new State(1);

    void newPageWasChosen(int newPage)
    {
        state->setPage(newPage);
        page = Page::getPages(newPage);
        state->animation = AnimationType::FadeIn;
        paintContent();
    }
    void paintContent()
    {
        ViewEngine::paint(state, &page);
    }

    void optionWasPressed(char key)
    {
        state->lastKey = key;
        int chosenAnswer = getOptionFromKeyPressed(key);
        if (chosenAnswer > 0)
        {
            state->highLightedAns = chosenAnswer;
        }
    }
    int getOptionFromKeyPressed(char key)
    {
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
            return highLightedAns;
        }
        else
        {
            return 0;
        }
    };
    void finish()
    {
        cout << "Finished, Goodbye!" << endl;
    };

    int eventLoop()
    {
        char keyPressed = 0, lastChar = 240;
        int lastSecond = 0;
        long keyDownTime = 0;
        int carpos = 0;
        bool pauseKeyPress = false;
        bool runing = true;

        while (runing)
        {
            char keyPressed = app_events::getKeyPressed2();
            int sec = state->getSecondsPassed();
            lastSecond = sec;

            if (keyPressed != lastChar)
            {
                lastChar = keyPressed;
                optionWasPressed(keyPressed);
            }

            if (keyPressed && keyPressed == lastChar)
            {
                if (pauseKeyPress)
                {
                    continue;
                }

                keyDownTime++;
                if (keyDownTime > ViewEngine::ticsForKeyPress)
                {
                    keyDownTime = 0;
                    if (ViewEngine::maxCatridgeBarSize > carpos)
                    {
                        carpos = carpos + 1;
                        state->carridgePos = carpos;
                        paintContent();
                    }
                    else
                    {
                        int chosenAnswer = getOptionFromKeyPressed(keyPressed);
                        if (chosenAnswer > 0)
                        {
                            state->highLightedAns = chosenAnswer;
                            int newPAgeNumber = page.optionsNumber[chosenAnswer - 1];
                            if (newPAgeNumber > 0)
                            {
                                newPageWasChosen(newPAgeNumber);
                                pauseKeyPress = true;
                            }
                        }
                    }
                }
            }
            else if (carpos > 0)
            {
                // If no key is pressed
                keyDownTime--;
                if (keyDownTime < (ViewEngine::ticsForKeyPress * -1))
                {
                    keyDownTime = 0;
                    if (carpos > 2)
                    {
                        carpos = carpos - 1;
                        state->carridgePos = carpos;
                        paintContent();
                    }
                    else
                    {
                        pauseKeyPress = false;
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
    AppMain app;
    cout << "works";
    app.start();
    return 0;
};
