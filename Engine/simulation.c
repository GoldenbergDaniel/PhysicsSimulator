#include "raylib.h"

#include "game_time.h"
#include "./Utility/init.h"
#include "./Objects/ground_check.h"
#include "./Objects/object.h"
#include "./Utility/collision.h"

const float gravity = -9.81f;

//Object *circle = &(struct Object) {15, 1, ZERO, ZERO, ZERO, ZERO, "circle"};

Object *square1 = &(Object) {30, 1, ZERO, ZERO, ZERO, ZERO, "square", COLOR_BLUE};
Object *square2 = &(Object) {30, 1, ZERO, ZERO, ZERO, ZERO, "square", COLOR_BLUE};

Object *objectList[2];

void start()
{
    objectList[0] = square1;
    objectList[1] = square2;

    square1->position = (Vector2) {100, 100};
    square2->position = (Vector2) {WIDTH-100, 100};

    square1->netExternalForces = (Vector2) {150, 100};
    square2->netExternalForces = (Vector2) {-150, 100};
}

void update(GameTime *gameTime)
{
    if (gameTime->totalElapsedTime > 0.25f)
    {
        for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
        {
            for (int j = 0; j < (sizeof(objectList) / sizeof(&objectList[0])); j++)
            {
                if (j != i)
                {
                    if (RectToRectCollision(objectList[i], objectList[j], gameTime))
                    {
                        objectList[j]->color = COLOR_RED;
                    }
                    else
                    {
                        objectList[j]->color = COLOR_BLUE;
                    }
                }
            }
        }

        for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
        {
            updateObject(objectList[i], gravity, gameTime);
        }
    }
}

void draw()
{
    BeginDrawing();

    DrawRectangleV((Vector2) {0, HEIGHT-30}, (Vector2) {WIDTH, 30}, COLOR_BLACK);

    for (int i = 0; i < (sizeof(objectList) / sizeof(&objectList[0])); i++)
    {
        drawObject(objectList[i]);
    }

    ClearBackground(COLOR_WHITE);

    EndDrawing();
}
