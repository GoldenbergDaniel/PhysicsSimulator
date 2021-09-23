#ifndef PHYSICSSIMULATOR_OBJECT_H
#define PHYSICSSIMULATOR_OBJECT_H

#include <string.h>
#include "../globals.h"

typedef struct Object
{
    float size;
    float mass;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    Vector2 netExternalForces;
    Color color;
    Color currColor;
    bool isActive;
} Object;

void object_start(Object *this);
void object_update(Object *this);
void object_draw(Object *this);
void object_destroy(Object *this);

#endif
