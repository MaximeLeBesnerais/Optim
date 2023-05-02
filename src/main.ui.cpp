/*
** EPITECH PROJECT, 2022
** optim
** File description:
** main.ui.cpp
*/

#include "graph.hpp"
#include "include.hpp"
using namespace nana;

void setup_labels(label &current, label &next, label &start)
{
    current.caption(std::string("Current mode: ") + get_mode("mode"));
    next.caption(std::string("Next mode: ") + get_mode("next-mode"));
    start.caption(std::string("Start mode: ") + get_mode("startup"));
    current.bgcolor(colors::white);
    next.bgcolor(colors::white);
    start.bgcolor(colors::white);
}

void setup_window(form &fm)
{
    paint::image img{"./assets/nvidia_logo.jpg"};
    fm.caption("Optimus Manager");
    fm.bgcolor(colors::white);
    fm.size(size{800, 400});
    fm.icon(img);
}

void setup_combox(combox &mode_box)
{
    mode_box.push_back("integrated");
    mode_box.push_back("hybrid");
    mode_box.push_back("nvidia");
    mode_box.option(0);
    mode_box.bgcolor(colors::white);
}

int g_main(void)
{
    form fm;
    label current(fm, rectangle{10, 10, 200, 20});
    label next(fm, rectangle{10, 30, 200, 20});
    label start(fm, rectangle{10, 50, 200, 20});
    combox mode_box(fm, rectangle{10, 70, 200, 20});
    setup_window(fm);
    setup_labels(current, next, start);
    setup_combox(mode_box);
    fm.show();
    exec();
    return 0;
}
