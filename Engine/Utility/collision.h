#ifndef PHYSICSSIMULATOR_COLLISION_H
#define PHYSICSSIMULATOR_COLLISION_H

#include <stdbool.h>
#include <math.h>

#include "../game_time.h"
#include "../Objects/object.h"

float max(float x, float y)
{
    if (x > y)
    {
        return x;
    }

    return y;
}

float min(float x, float y)
{
    if (x < y)
    {
        return y;
    }

    return x;
}

bool RangeIntersect(float min1, float max1, float min2, float max2)
{
//    return max(min1, max1) >= min(min2, max2) && min(min1, max1) <= max(min2, max2);
    return max1 >= min2 && min1 <= max2;
}

//bool RectToRectCollision(Object *s1, Object *s2, GameTime* gameTime)
//{
//    return RangeIntersect(s1->position.x, s1->position.x + s1->size, s2->position.x, s2->position.x + s2->size) &&
//           RangeIntersect(s1->position.x, s1->position.y + s1->size, s2->position.x, s2->position.y + s2->size);
//}

bool RectToRectCollision(Object *obj1, Object *obj2, GameTime *gameTime)
{
    return RangeIntersect(obj1->position.x, obj1->position.x + obj1->size,
                          obj2->position.x, obj2->position.x + obj2->size) &&

           RangeIntersect(obj1->position.y, obj1->position.y + obj1->size,
                          obj2->position.y, obj2->position.y + obj2->size);
}

#endif
