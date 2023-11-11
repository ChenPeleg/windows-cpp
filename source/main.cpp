

#include "./headers/constants.hpp"
#include "./headers/app_state.hpp"
#include "./headers/views_engine.hpp"
#include "./headers/common.hpp"
#include "./headers/grapihics_utils.hpp"
#include "./headers/app_events.hpp"
#include "./headers/file_manager.hpp"
#include "./headers/inventory.hpp"
#include "./headers/debuging.hpp"
#include "./headers/save_load.hpp"

#include "./classes/app_state.cpp"
#include "./classes/combat_state.cpp"
#include "./classes/views_engine.cpp"
#include "./images/images.cpp"

#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;
using namespace common;

class AppMain
{

public:
    AppMain()
    {
        srand(time(NULL));
    };
    int start()
    {

        ViewEngine::hideCursor();
        graphicUtils::clear();
        newPageWasChosen(1); // 44410001
        paintContent();
        eventLoop();
        return 0;
    };

private:
    State *state = new State(1);
    bool saveDataTest(int slotNumber, char *saveName)
    { //
        try
        {

            char *charArr = new char[sizeof(SaveLoad::SaveLoadData)];
            SaveLoad::GetByteArrayFromStateAndData(*(state), saveName, charArr);

            cout << "\n\n SaveDataTest Byte array: ";

            for (int i = 0; i < sizeof(SaveLoad::SaveLoadData); i++)
            {
                cout << charArr[i];
            }

            FileManager fm = *(new FileManager());
            fm.addBin(charArr, sizeof(SaveLoad::SaveLoadData));
        }
        catch (exception e)
        {
            return false;
        }
        return true;
    }
    bool loadDataTest(int slotNumber)
    {
        try
        {
            //
            char *charArr = new char[sizeof(SaveLoad::SaveLoadData)];
            FileManager fm = *(new FileManager());
            fm.getBin(charArr, sizeof(SaveLoad::SaveLoadData));
            SaveLoad::SaveLoadData *slPtr = SaveLoad::ByteArrayToStruct(charArr);
            SaveLoad::SaveLoadData slRef = *slPtr;
            delete charArr;
        }
        catch (exception e)
        {
            return false;
        }
        return true;
    }
    void newPageWasChosen(int newPage)
    {

        state->setPage(newPage);
        state->animation = AnimationType::FadeIn;
        state->highLightedAns = 0;
        state->carridgePos = ViewEngine::minCatridgeBarSize;
        paintContent();
        state->animation = AnimationType::none;
    }
    void paintContent()
    {
        Page &pgRef = state->currentPage();
        Page *pgPtr = &pgRef;
        ViewEngine::paint(state, pgPtr);
    }

    bool optionWasPressed(char key)
    {
        const Page pageGlob = state->currentPage();
        state->lastKey = key;
        int chosenAnswer = getOptionFromKeyPressed(key);
        if (chosenAnswer > 0)
        {
            if (pageGlob.isFight)
            {
                state->combat->combatKeyPressed(key);
            }
            else
            {
                if (pageGlob.choices[chosenAnswer - 1].optionBlocked)
                {
                    return false;
                }
                state->highLightedAns = chosenAnswer;
            }
        } //
        return true;
    }
    void specialKeyPressed(char key)
    { //
        switch (key)
        {
        case 'S':
            newPageWasChosen(10002);
            break;
        case 'E':
        {
            char name[] = "Chen"; //
            if (saveDataTest(1, name))
            {
                cout << "\n\n Game was saved! \n\n";
                int a2;
                cin >> a2;
            };
        }
        break;
        case 'W':
        {
            if (loadDataTest(1))
            {
                cout << "\n\n Game was loaded! \n\n";
                int a;
                cin >> a;
            };
        }
        break;
        }
    }
    int getOptionFromKeyPressed(char key)
    {
        const Page &pageGlob = state->currentPage();
        int keyAsInt = key - '0';

        if (pageGlob.isFight && keyAsInt < 5 && keyAsInt > 0)
        {
            return keyAsInt + 1;
        }
        int newPageNumber = 0;
        int highLightedAns = 0;
        for (int o = 0; o < 5; o++)
        {
            if (pageGlob.choices[o].pageNumber < 1)
            {
                continue;
            }

            if (keyAsInt == (o + 1))
            {
                newPageNumber = pageGlob.choices[o].pageNumber;
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
        long keyDownTime = 0;
        bool pauseKeyPress = false;
        bool runing = true;
        bool paintOrNot = true;
        state->carridgePos = 0;
        state->setMsTimer(100);
        bool isAllowed = true;
        while (runing)
        {
            state->tik();
            int sec = state->getSeconds();
            if (state->isTimerDone())
            {
                paintOrNot = true;
            }
            char keyPressed = app_events::getKeyPressed();

            if (!((keyPressed >= 49 && keyPressed <= 56) || keyPressed == 'S' || keyPressed == 'E' || keyPressed == 'W' || keyPressed == 116 || keyPressed == 0))
            {
                keyPressed = 0;
                continue;
            }

            if (keyPressed != lastChar || state->currentPage().isFight)
            {
                lastChar = keyPressed;
                isAllowed = optionWasPressed(keyPressed);
            }
            if (!isAllowed)
            {
                continue;
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
                    if (ViewEngine::maxCatridgeBarSize > state->carridgePos)
                    {
                        state->carridgePos = state->carridgePos + 1;

                        paintOrNot = true;
                    }
                    else
                    {
                        int chosenAnswer = getOptionFromKeyPressed(keyPressed);
                        if (chosenAnswer > 0)
                        {
                            state->highLightedAns = chosenAnswer;
                            int newPAgeNumber = state->currentPage().choices[chosenAnswer - 1].pageNumber;
                            if (newPAgeNumber > 0)
                            {
                                newPageWasChosen(newPAgeNumber);
                                pauseKeyPress = true;
                            }
                        }
                    }
                }
            }
            else if (state->carridgePos > 0)
            {
                // If no key is pressed
                keyDownTime--;
                if (keyDownTime < (ViewEngine::ticsForKeyPress * -1))
                {
                    keyDownTime = 0;
                    if (state->carridgePos > ViewEngine::minCatridgeBarSize)
                    {
                        state->carridgePos = state->carridgePos - 1;

                        paintOrNot = true;
                    }
                    else
                    {
                        pauseKeyPress = false;
                    }
                }
            }
            if (keyPressed == 116 || keyPressed == 'Q' || sec > 40)
            {
                finish();
                runing = false;
            }
            else if ((keyPressed == 'S' || keyPressed == 'B' || keyPressed == 'E' || keyPressed == 'W') && state->getPage() < 10000)
            {
                specialKeyPressed(keyPressed);
            }

            // end of loop
            if (paintOrNot)
            {
                paintContent();
                paintOrNot = false;
            }
        }

        return 0;
    };
};
int main()
{

    AppMain app;
    app.start();
    return 0;
};
