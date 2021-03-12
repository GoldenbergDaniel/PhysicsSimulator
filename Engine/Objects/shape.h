#ifndef PHYSICSSIMULATOR_CIRCLE_H
#define PHYSICSSIMULATOR_CIRCLE_H

typedef struct Shape
{
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float mass;
    float radius;
} Shape;

#endif
