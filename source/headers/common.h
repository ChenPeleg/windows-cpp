
#ifndef COMMON_H
#define COMMON_H
namespace common
{
    enum AnimationType
    {
        none = 0,
        FadeIn = 1,
        FadeOut = 2,
        Choose = 3
    };
    /* from 1 to 10000 im miliseconds*/
    typedef int ClockTicksState;
    const int AnimationDelay = 500;
    int string_size(const char *str)
    {

        int Size = 0;
        while (str[Size] != '\0')
            Size++;
        return Size;
    }
};

#endif