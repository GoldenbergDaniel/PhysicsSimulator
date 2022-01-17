#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../object/object.h"
#include "collision.h"

bool range_intersect(f32 min1, f32 max1, f32 min2, f32 max2)
{
    return max1 >= min2 && min1 <= max2;
}

bool collision(Object *obj1, Object *obj2)
{
    return range_intersect(obj1->position.x, obj1->position.x + obj1->size, obj2->position.x, obj2->position.x + obj2->size) &&
           range_intersect(obj1->position.y, obj1->position.y + obj1->size, obj2->position.y, obj2->position.y + obj2->size);
}

void recalculate_velocities(Object *obj1, Object *obj2)
{
    printf("Initial v1: %f, %f \n", obj1->velocity.x, obj1->velocity.y);
    printf("Initial v2: %f, %f \n", obj2->velocity.x, obj1->velocity.y);

    v2 vel1_f;
    vel1_f.x = (obj1->mass * obj1->velocity.x + 2 * obj2->mass * obj2->velocity.x - obj2->mass * obj1->velocity.x) / (obj1->mass + obj2->mass);
    vel1_f.y = obj1->velocity.y;

    v2 vel2_f;
    vel2_f.x = (obj1->velocity.x - obj2->velocity.x + vel1_f.x);
    vel2_f.y = obj2->velocity.y;

    printf("Final v1: %f, %f \n", vel1_f.x, vel1_f.y);
    printf("Final v2: %f, %f \n", vel2_f.x, vel1_f.y);

    obj1->velocity = vel1_f;
    obj2->velocity = vel2_f;
}
