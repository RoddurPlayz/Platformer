#pragma once


#include <SDL2/SDL.h>

#include "Math.hpp"


struct Rect
{
    Rect();
    Rect(Vector4f pos_and_size);

    Vector4f get_top_left();
    Vector4f get_top_right();

    Vector4f get_center();

    Vector4f get_bottom_left();
    Vector4f get_bottom_right();

    void set_top_left(Vector4f pos_and_size);
    void set_top_right(Vector4f pos_and_size);

    void set_center(Vector4f pos_and_size);

    void set_bottom_left(Vector4f pos_and_size);
    void set_bottom_right(Vector4f pos_and_size);

    void move_ip(float x, float y);

    private:
        Vector4f rtop_left;
        Vector4f rtop_right;

        Vector4f rcenter;

        Vector4f rbottom_left;
        Vector4f rbottom_right;

};
