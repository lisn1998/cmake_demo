#include <iostream>
#include "hellodll/hellofun.h"

namespace cmakeHello
{
    void HELLO_EXPORT printInfo()
    {
        std::cout << "c++ cmakeHello printInfo" << std::endl;
    }
}