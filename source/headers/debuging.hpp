#ifndef DEBUGING_H
#define DEBUGING_H

#include "common.hpp"
using namespace common;
namespace debuging
{
    void stop()
    {
        std::cout << "\n";
        std::system("PAUSE");
    }
};

#endif