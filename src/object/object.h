#pragma once

#include "../globals.h"

typedef struct Object
{
    f32 size;
    f32 mass;
    v2 position;
    v2 velocity;
    v2 acceleration;
    v2 external_force;
    Color color;
} Object;

Object object_new(f32 size, f32 mass, v2 pos, v2 force, Color color);
void object_update(Object *this);
void object_draw(Object *this);
void object_destroy(Object *this);
