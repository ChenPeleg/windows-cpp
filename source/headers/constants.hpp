#ifndef CONSTANTS_H
#define CONSTANTS_H

// The norm is not to include cpp files in other cpp files
namespace constants
{

    constexpr int rowLength{20};
    int eight()
    {
        return 8;
    }
    const int TIME_FOR_COMBAT_MESSAGE = 2000;
    const int COMBAT_BUTTONS_SPEED = 500;
    const int TIME_FOR_WIN_MESSAGE = 5000;
    const int MAX_NUMBER_OF_OPTIONS = 5;
}
#endif