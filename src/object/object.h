#ifndef PHYSICSSIMULATOR_OBJECT_H
#define PHYSICSSIMULATOR_OBJECT_H

#include "../globals.h"

typedef struct Object
{
    f32 size;
    f32 mass;
    v2 position;
    v2 velocity;
    v2 acceleration;
    v2 net_external_forces;
    Color color;
    Color curr_color;
    bool is_active;
} Object;

Object object_new(f32 size, f32 mass, v2 pos, v2 force, Color color);
void object_start(Object *this);
void object_update(Object *this);
void object_draw(Object *this);
void object_destroy(Object *this);

#endif
