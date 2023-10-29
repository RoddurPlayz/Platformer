#pragma once


#include <iostream>


struct Vector2f
{
    float x, y;

    Vector2f()
    :x(0.0f), y(0.0f)
    {}
    Vector2f(float x, float y);

    void move_ip(float x, float y);

    std::string print(char end);
};


struct Vector3f
{
    float x, y, z;

    Vector3f()
    :x(0.0f), y(0.0f), z(0.0f)
    {}
    Vector3f(float x, float y, float z);

    void move_ip(float x, float y, float z);

    std::string print(char end);
};


struct Vector4f
{
    float x, y, z, w;

    Vector4f()
    :x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}
    Vector4f(float x, float y, float z, float w);

    void move_ip(float x, float y, float z, float w);

    std::string print(char end);
};


struct Vector4b
{
    bool x, y, z, w;

    Vector4b()
    :x(false), y(false), z(false), w(false)
    {}
    Vector4b(bool x, bool y, bool z, bool w);

    std::string print(char end);
};
