#ifndef APP_EVENTS
#define APP_EVENTS
#include <conio.h>
#include <windows.h>
namespace app_events
{
    char image1[] = "123123";
    const char allKeys[37] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char getKeyPressed()
    {
        return getche();
    }
    char getKeyPressed2()
    {
        for (int i = 0; i < 37; i++)
        {
            if ((GetAsyncKeyState(allKeys[i]) & 0x8000))
            {
                return allKeys[i];
            }
        }
        return 0;
    }
}

#endif