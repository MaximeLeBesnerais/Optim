/*
** EPITECH PROJECT, 2022
** optim
** File description:
** graph.hpp
*/

#ifndef GRAPH_HPP
    #define GRAPH_HPP
    #include <iostream>
    #include <nana/gui.hpp>
    #include <nana/gui/widgets/group.hpp>
    #include <nana/gui/widgets/label.hpp>
    #include <nana/gui/widgets/combox.hpp>
    #include <nana/gui/widgets/form.hpp>
    #include <nana/paint/image.hpp>
    #include <nana/gui/widgets/button.hpp>
    #define WINDOW_WIDTH 500
    #define WINDOW_HEIGHT 150
    typedef enum GPU_STATUS {
        INTEGRATED = 0,
        HYBRID = 1,
        NVIDIA = 2
    } gpu;
    typedef struct buttons_s {
        nana::button &integrated;
        nana::button &hybrid;
        nana::button &nvidia;
        nana::button &apply;
    } buttons_t;
    typedef struct labels_s {
        nana::label &current;
        nana::label &next;
        nana::label &start;
        nana::label &changes;
    } labels_t;
    gpu get_current(void);
    static gpu c_gpu = get_current();
    static gpu a_gpu = get_current();
#endif //GRAPH_HPP
