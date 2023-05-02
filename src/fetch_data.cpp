/*
** EPITECH PROJECT, 2022
** optim
** File description:
** fetch_data.cpp
*/

#include "include.hpp"

std::string get_mode(std::string print)
{
    std::string cmd = "optimus-manager --print-" + print;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe)
        return "EX-FF";
    char buffer[4096];
    std::string mode;
    while (fgets(buffer, sizeof(buffer), pipe) != NULL)
        mode += buffer;
    pclose(pipe);
    mode = mode.substr(mode.find(":") + 2);
    mode = mode.substr(0, mode.size() - 1);
    return mode;
}
