#ifndef PHYSICSSIMULATOR_CIRCLE_H
#define PHYSICSSIMULATOR_CIRCLE_H

#include <string.h>

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
} Object;

//float getCenterOfMass(Shape *shape)
//{
//    if (strcmp(shape->type, "circle") == 0)
//    {
//        return shape->size;
//    }
//
//    return shape->size;
//}

void updatePosition(Object *obj, float gravity, GameTime* gameTime)
{
    obj->acceleration.x = obj->netExternalForces.x / obj->mass;
    obj->acceleration.y = -(obj->netExternalForces.y / obj->mass + gravity);

    obj->netExternalForces = ZERO;

    if (obj->position.x + (obj->velocity.x * gameTime->deltaTime) < WIDTH - obj->size + (obj->velocity.x * gameTime->deltaTime))
    {
        obj->velocity.x += obj->acceleration.x;
        obj->position.x += obj->velocity.x * gameTime->deltaTime;
    }
    else
    {
        obj->acceleration.x = 0;
        obj->velocity.x = 0;
    }

    if (obj->position.y + (obj->velocity.y * gameTime->deltaTime) < (HEIGHT - 30) - obj->size + (obj->velocity.y * gameTime->deltaTime))
    {
        obj->velocity.y += obj->acceleration.y;
        obj->position.y += obj->velocity.y * gameTime->deltaTime;
    }
    else
    {
        obj->acceleration.y = 0;
        obj->velocity.y = 0;
    }
}

void drawShape(Object *obj)
{
    if (strcmp(obj->type, "circle") == 0)
    {
        DrawCircleV(obj->position, obj->size, obj->color);
    }
    else if (strcmp(obj->type, "square") == 0)
    {
        DrawRectangleV(obj->position, (Vector2) {obj->size, obj->size}, obj->color);
    }
}

#endif
