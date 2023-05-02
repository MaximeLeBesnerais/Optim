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
    current.text_align(align::center, align_v::center);
    next.text_align(align::center, align_v::center);
    start.text_align(align::center, align_v::center);
}

void setup_window(form &fm)
{
    paint::image img{"./assets/nvidia_logo.jpg"};
    fm.caption("Optimus Manager");
    fm.bgcolor(colors::white);
    fm.size(size{WINDOW_WIDTH, WINDOW_HEIGHT});
    fm.icon(img);
}

void button_setup(button &integrated, button &hybrid, button &nvidia, button &apply)
{
    integrated.caption("Integrated");
    hybrid.caption("Hybrid");
    nvidia.caption("Nvidia");
    apply.caption("Apply");
    integrated.bgcolor(colors::white);
    hybrid.bgcolor(colors::white);
    nvidia.bgcolor(colors::white);
    apply.bgcolor(colors::white);
}

gpu get_current(void)
{
    std::string mode = get_mode("mode");
    if (mode == "integrated")
        return gpu::INTEGRATED;
    else if (mode == "hybrid")
        return gpu::HYBRID;
    else
        return gpu::NVIDIA;
}

void deactivate_buttons(button &integrated, button &hybrid, button &nvidia, gpu current)
{
    switch (current)
    {
    case gpu::INTEGRATED:
        integrated.enabled(false);
        break;
    case gpu::HYBRID:
        hybrid.enabled(false);
        break;
    case gpu::NVIDIA:
        nvidia.enabled(false);
        break;
    default:
        break;
    }
}

void setup_actions(button &integrated, button &hybrid, button &nvidia)
{
    integrated.events().click([&] {
        integrated.enabled(false);
        hybrid.enabled(true);
        nvidia.enabled(true);
        a_gpu = gpu::INTEGRATED;
        DISABLE_CURRENT
    });
    hybrid.events().click([&] {
        integrated.enabled(true);
        hybrid.enabled(false);
        nvidia.enabled(true);
        a_gpu = gpu::HYBRID;
        DISABLE_CURRENT
    });
    nvidia.events().click([&] {
        integrated.enabled(true);
        hybrid.enabled(true);
        nvidia.enabled(false);
        a_gpu = gpu::NVIDIA;
        DISABLE_CURRENT
    });
}

void setup(form &fm, label &current, label &next, label &start, button &integrated, button &hybrid, button &nvidia, button &apply)
{
    setup_window(fm);
    setup_labels(current, next, start);
    button_setup(integrated, hybrid, nvidia, apply);
    deactivate_buttons(integrated, hybrid, nvidia, c_gpu);
    setup_actions(integrated, hybrid, nvidia);
}

int g_main(void)
{
    form fm;
    label current(fm, rectangle{10, 10, WINDOW_WIDTH - 20, 20});
    label next(fm, rectangle{10, 30, WINDOW_WIDTH - 20, 20});
    label start(fm, rectangle{10, 50, WINDOW_WIDTH - 20, 20});
    button integrated(fm, rectangle{10, 80, 120, 20});
    button hybrid(fm, rectangle{(WINDOW_WIDTH / 2) - 60, 80, 120, 20});
    button nvidia(fm, rectangle{WINDOW_WIDTH - 130, 80, 120, 20});
    button apply(fm, rectangle{WINDOW_WIDTH / 2 - 60, 110, 120, 20});
    setup(fm, current, next, start, integrated, hybrid, nvidia, apply);
    fm.show();
    exec();
    return 0;
}
