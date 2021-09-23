#pragma once

#include <stdbool.h>
#include <math.h>

#include "../object/object.h"

bool RangeIntersect(f32 min1, f32 max1, f32 min2, f32 max2)
{
    return max1 >= min2 && min1 <= max2;
}

bool Collision(Object *obj1, Object *obj2)
{
    return RangeIntersect(obj1->position.x, obj1->position.x + obj1->size, obj2->position.x, obj2->position.x + obj2->size) &&
           RangeIntersect(obj1->position.y, obj1->position.y + obj1->size, obj2->position.y, obj2->position.y + obj2->size);
}

v2 RecalculateVelocity(Object *obj1)
{
    v2 newVelocity;
    newVelocity.x = -obj1->velocity.x * obj1->mass;
    newVelocity.y = -obj1->velocity.y * obj1->mass;

    return newVelocity;
}
