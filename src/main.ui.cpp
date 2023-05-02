/*
** EPITECH PROJECT, 2022
** optim
** File description:
** main.ui.cpp
*/

#include "graph.hpp"
#include "include.hpp"
using namespace nana;

void setup_labels(label &current, label &next, label &start, label &changes)
{
    current.caption(std::string("Current mode: ") + get_mode("mode"));
    next.caption(std::string("Next mode: ") + get_mode("next-mode"));
    start.caption(std::string("Start mode: ") + get_mode("startup"));
    changes.caption(std::string("Changes: None"));
    current.bgcolor(colors::white);
    next.bgcolor(colors::white);
    start.bgcolor(colors::white);
    changes.bgcolor(colors::white);
    current.text_align(align::center, align_v::center);
    next.text_align(align::center, align_v::center);
    start.text_align(align::center, align_v::center);
    changes.text_align(align::center, align_v::center);
}

void setup_window(form &fm)
{
    paint::image img{"~/Optim/assets/nvidia_logo.jpg"};
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

void apply_change(labels_t &all)
{
    if (a_gpu == c_gpu) {
        all.changes.caption(std::string("Cannot apply: No changes"));
        return;
    }
    std::string new_mode;
    switch (a_gpu) {
        case gpu::INTEGRATED:
            new_mode = "integrated";
            break;
        case gpu::HYBRID:
            new_mode = "hybrid";
            break;
        case gpu::NVIDIA:
            new_mode = "nvidia";
            break;
        default:
            all.changes.caption(std::string("Cannot apply: New GPU mode is unknown"));
            return;
    }
    std::string cmd = "optimus-manager --switch " + new_mode + " --no-confirm";
    if (system(cmd.c_str()) == 0) {
        all.changes.caption(std::string("Changes: Applied"));
        c_gpu = a_gpu;
    } else
        all.changes.caption(std::string("Cannot apply: An error occured when using optimus-manager"));
}

void setup_actions(buttons_t &b, labels_t &a)
{
    b.integrated.events().click([&] {
        b.integrated.enabled(false);
        b.hybrid.enabled(true);
        b.nvidia.enabled(true);
        a.changes.caption(std::string("Changes: Switching to integrated"));
        a_gpu = gpu::INTEGRATED;
    });
    b.hybrid.events().click([&] {
        b.integrated.enabled(true);
        b.hybrid.enabled(false);
        b.nvidia.enabled(true);
        a.changes.caption(std::string("Changes: Switching to hybrid"));
        a_gpu = gpu::HYBRID;
    });
    b.nvidia.events().click([&] {
        b.integrated.enabled(true);
        b.hybrid.enabled(true);
        b.nvidia.enabled(false);
        a.changes.caption(std::string("Changes: Switching to nvidia"));
        a_gpu = gpu::NVIDIA;
    });
    b.apply.events().click([&] {
        apply_change(a);
    });
}

void setup(form &fm, labels_t &all, buttons_t &buttons)
{
    setup_window(fm);
    setup_labels(all.current, all.next, all.start, all.changes);
    button_setup(buttons.integrated, buttons.hybrid, buttons.nvidia, buttons.apply);
    setup_actions(buttons, all);
}

int g_main(void)
{
    form fm;
    label current(fm, rectangle{10, 10, WINDOW_WIDTH - 20, 20});
    label next(fm, rectangle{10, 30, WINDOW_WIDTH - 20, 20});
    label start(fm, rectangle{10, 50, WINDOW_WIDTH - 20, 20});
    label changes(fm, rectangle{10, 100, WINDOW_WIDTH - 20, 20});
    button integrated(fm, rectangle{10, 80, 120, 20});
    button hybrid(fm, rectangle{(WINDOW_WIDTH / 2) - 60, 80, 120, 20});
    button nvidia(fm, rectangle{WINDOW_WIDTH - 130, 80, 120, 20});
    button apply(fm, rectangle{WINDOW_WIDTH / 2 - 60, 120, 120, 20});
    labels_t all = {current, next, start, changes};
    buttons_t buttons = {integrated, hybrid, nvidia, apply};
    setup(fm, all, buttons);
    fm.show();
    exec();
    return 0;
}
