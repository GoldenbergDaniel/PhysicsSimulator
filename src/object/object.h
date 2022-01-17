#pragma once

#include "../globals.h"

// Object type
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

// Create new object
Object object_new(f32 size, f32 mass, v2 pos, v2 force, Color color);

// Update object
void object_update(Object *this);

// Draw object
void object_draw(Object *this);

// Get velocity of object
v2 object_get_velocity(Object *this);
