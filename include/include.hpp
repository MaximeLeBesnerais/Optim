/*
** EPITECH PROJECT, 2022
** optim
** File description:
** include.hpp
*/

#ifndef INCLUDE_HPP
    #define INCLUDE_HPP
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>

    typedef enum GPU_STATUS {
        INTEGRATED = 0,
        HYBRID = 1,
        NVIDIA = 2
    } gpu;
    
    std::string get_mode(std::string print);    
#endif //INCLUDE_HPP
