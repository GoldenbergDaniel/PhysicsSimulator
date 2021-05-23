#include "globals.h"

#include "./object/object.h"
#include "./utility/collision.h"

Object *square1 = &(Object) {70, 1, {100, 200}, ZERO, ZERO, ZERO, "square", COLOR_BLUE};
Object *square2 = &(Object) {40, 1, {WIDTH-100, 250}, ZERO, ZERO, ZERO, "square", COLOR_GREEN};

Object *objectList[2];

void start()
{
    objectList[0] = square1;
    objectList[1] = square2;

    for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
    {
        object_start(objectList[i]);
    }

    square1->netExternalForces = (Vector2) {200, 300};
    square2->netExternalForces = (Vector2) {-800, 400};
}

void update(GameTime *gameTime)
{
    if (gameTime->totalElapsedTime > 0.25f)
    {
        // Collision
        for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
        {
            for (int j = 0; j < (sizeof(objectList) / sizeof(&objectList[0])); j++)
            {
                if (i != j)
                {
                    if (RectToRectCollision(objectList[i], objectList[j]))
                    {
                        objectList[i]->currColor = COLOR_RED;
                    }
                    else
                    {
                        objectList[i]->currColor = objectList[i]->color;
                    }
                }
            }
        }

        // Update
        for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
        {
            object_update(objectList[i], gameTime);
        }
    }
}

void draw()
{
    DrawRectangleV((Vector2) {0, HEIGHT-30}, (Vector2) {WIDTH, 30}, COLOR_BLACK);

    for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
    {
        object_draw(objectList[i]);
    }

    ClearBackground(COLOR_WHITE);
}
