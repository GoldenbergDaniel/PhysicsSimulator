#ifndef PHYSICSSIMULATOR_CIRCLE_H
#define PHYSICSSIMULATOR_CIRCLE_H

typedef struct Circle
{
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float radius;
    float mass;
} Circle;

#endif
