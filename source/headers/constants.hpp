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
    const int SAVE_RECORD_SIZE_BYTES = 100;
    const int CUSTOM_ID_UPDATE_SAVED_NAMES = 100;
    const int PAGE_NUMBER_RETURN_TO_GAME = 10000000;
    const int PAGE_NUMBER_SAVE_SLOTS = 11111111;
    const int PAGE_NUMBER_LOAD_SLOTS = 21111111;
}
#endif