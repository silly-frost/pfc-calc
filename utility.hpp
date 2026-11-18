#pragma once

#include<cstdlib>
namespace Utility{
    void clear_screen(){
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }
}
