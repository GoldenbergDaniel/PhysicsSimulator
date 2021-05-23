#ifndef PHYSICSSIMULATOR_COLLISION_H
#define PHYSICSSIMULATOR_COLLISION_H

#include <stdbool.h>
#include <math.h>

#include "../object/object.h"

bool RangeIntersect(float min1, float max1, float min2, float max2)
{
    return max1 >= min2 && min1 <= max2;
}

bool RectToRectCollision(Object *obj1, Object *obj2)
{
    return RangeIntersect(obj1->position.x, obj1->position.x + obj1->size, obj2->position.x, obj2->position.x + obj2->size) &&
           RangeIntersect(obj1->position.y, obj1->position.y + obj1->size, obj2->position.y, obj2->position.y + obj2->size);
}

#endif
