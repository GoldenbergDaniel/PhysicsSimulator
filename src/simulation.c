#include <stdio.h>

#include "globals.h"

#include "./object/object.h"
#include "./utility/collision.h"

Object *square1 = &(Object) {70, 1, {100, 200}, ZERO, ZERO, ZERO, COLOR_BLUE};
Object *square2 = &(Object) {40, 1, {WIDTH-100, 250}, ZERO, ZERO, ZERO, COLOR_GREEN};
Object *square3 = &(Object) {50, 1, {WIDTH/2, 100}, ZERO, ZERO, ZERO, COLOR_RED};

Object *objectList[3];
i32 objectCount;

void start()
{
    square1->netExternalForces = (v2) {800, 300};
    square2->netExternalForces = (v2) {-800, 300};
    square3->netExternalForces = (v2) {0, 0};

    objectList[0] = square1;
    objectList[1] = square2;
    objectList[2] = square3;

    objectCount = sizeof(objectList) / sizeof(&objectList[0]);

    for (i8 i = 0; i < objectCount; i++)
    {
        object_start(objectList[i]);
    }
}

void update()
{
    if (GetTime() > 0.25f)
    {
        // Update
        for (i8 i = 0; i < objectCount; i++)
        {
            object_update(objectList[i]);
        }

        // Collision
        for (i8 i = 0; i < objectCount; i++)
        {
            for (i8 j = 0; j < objectCount; j++)
            {
                if (i != j)
                {
                    if (Collision(objectList[i], objectList[j]))
                    {
                        objectList[i]->velocity = RecalculateVelocity(objectList[i]);
                        // objectList[i]->currColor = WHITE;
                        // object_destroy(objectList[i]);
                    }
                    else
                    {
                        objectList[i]->currColor = objectList[i]->color;
                    }
                }
            }
        }
    }
}

void draw()
{
    DrawRectangleV((v2) {0, HEIGHT-30}, (v2) {WIDTH, 30}, COLOR_BLACK);

    for (i8 i = 0; i < objectCount; i++)
    {
        object_draw(objectList[i]);
    }

    ClearBackground(COLOR_WHITE);
}
