#include "raylib.h"
#include "game_time.h"

#include <stdio.h>

#include "./Utility/init.h"
#include "./Utility/collision.h"

const float gravity = -9.81f;

//Object *circle = &(struct Object) {15, 1, ZERO, ZERO, ZERO, ZERO, "circle"};

Object *square1 = &(Object) {30, 1, ZERO, ZERO, ZERO, ZERO, "square", COLOR_BLUE};
Object *square2 = &(Object) {30, 1, ZERO , ZERO, ZERO, ZERO, "square", COLOR_RED};

Object *shapeList[2];

void start()
{
    shapeList[0] = square1;
    shapeList[1] = square2;

    square1->position = (Vector2) {50, 50};
    square2->position = (Vector2) {WIDTH-50, 50};

    square1->netExternalForces = (Vector2) {100, 0};
    square2->netExternalForces = (Vector2) {-100, 0};
}

void update(GameTime *gameTime)
{
    if (gameTime->totalElapsedTime > 0.25f)
    {
        if (RectToRectCollision(square1, square2, gameTime))
        {
            printf("collision!\n");
            square2->color = COLOR_GREEN;
        }

        for (int i = 0; i < (sizeof(shapeList) / sizeof(&shapeList[0])); i++)
        {
            updatePosition(shapeList[i], gravity, gameTime);
        }
    }
}

void draw()
{
    DrawText(TextFormat("%.2f", square1->position.x), WIDTH-70, 50, 20, COLOR_BLACK);
    DrawText(TextFormat("%.2f", square2->position.x), WIDTH-70, 70, 20, COLOR_RED);
    DrawText(TextFormat("%.2f", square1->position.y), WIDTH-70, 90, 20, COLOR_BLACK);
    DrawText(TextFormat("%.2f", square2->position.y), WIDTH-70, 120, 20, COLOR_RED);

    DrawRectangleV((Vector2) {0, HEIGHT-30}, (Vector2) {WIDTH, 30}, COLOR_BLACK);

    for (int i = 0; i < (sizeof(shapeList) / sizeof(&shapeList[0])); i++)
    {
        drawShape(shapeList[i]);
    }

    DrawRectangleV(square2->position, (Vector2) {square2->size, square2->size}, square2->color);

    ClearBackground(COLOR_WHITE);
}
