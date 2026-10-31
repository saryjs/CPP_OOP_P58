#include <iostream>
#include <conio.h>
#include "intro.h"
#include "basics.h"
#include "data_structures.h"


int main()
{
    std::cout << "Choose mode: " << std::endl
        << "1. Intro" << std::endl
        << "2. Basics" << std::endl
        << "3. Data Struct" << std::endl;
    switch (_getch()) {
    case 49:
        intro();
        break;
    case 50:
        basics();
        break;
    case 51:
        data_structures();
        break;
    default:
        std::cout << "Selected wrong mode";
        break;
    }

    return 0;
}