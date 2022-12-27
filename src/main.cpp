/**
 ******************************************************************************
 * @file     main.cpp
 * @brief    Main program entry point
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the Apache License v2.0
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#include <iostream>
#include <fstream>
#include "restaurant.hpp"


int main(int argc, const char** argv)
{
    if (argc > 1) {
        std::ifstream file(argv[1]);
        if (file.fail()) {
            std::cerr << "Cannot open '" << argv[1] << "' file" << std::endl;
            return 1;
        }
        return restaurant_manager(file);
    } else {
        return restaurant_manager(std::cin);
    }
}
