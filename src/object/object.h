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
    char type[16];
    Color color;
    Color currColor;
} Object;

void object_start(Object *this);
void object_update(Object *this, GameTime* gameTime);
void object_draw(Object *this);

#endif
