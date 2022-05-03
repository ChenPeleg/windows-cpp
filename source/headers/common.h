
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
    const int AnimationDelay = 500;
};

#endif