#ifndef APP_EVENTS
#define APP_EVENTS
#include <conio.h>
#include <windows.h>
namespace app_events
{
    char image1[] = "123123";
    const char allKeys[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    char getKeyPressed()
    {
        return getche();
    }
    char getKeyPressed2()
    {
        for (int i = 0; i < 63; i++)
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