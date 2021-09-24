#include <stdio.h>

#include "globals.h"

#include "./object/object.h"
#include "./utility/collision.h"

Object square1;
Object square2;
Object square3;

const i32 object_count = 3;
Object *object_list[object_count];

void start()
{
    square1 = object_new(70, 1, (v2) {100, 200}, (v2) {800, 300}, COLOR_BLUE);
    square2 = object_new(40, 1, (v2) {WIDTH-100, 250}, (v2) {-800, 300}, COLOR_GREEN);
    square3 = object_new(50, 1, (v2) {WIDTH/2, 100}, (v2) {0, 0}, COLOR_RED);

    object_list[0] = &square1;
    object_list[1] = &square2;
    object_list[2] = &square3;

    for (u8 i = 0; i < object_count; i++)
    {
        object_start(object_list[i]);
    }
}

void update()
{
    if (GetTime() > 0.25f)
    {
        // Update
        for (u8 i = 0; i < object_count; i++)
        {
            object_update(object_list[i]);
        }

        // Collision
        for (u8 i = 0; i < object_count; i++)
        {
            for (u8 j = 0; j < object_count; j++)
            {
                if (i != j)
                {
                    if (collision(object_list[i], object_list[j]))
                    {
                        object_list[i]->velocity = recalculate_velocity(object_list[i]);
                    }
                    else
                    {
                        object_list[i]->curr_color = object_list[i]->color;
                    }
                }
            }
        }
    }
}

void draw()
{
    DrawRectangleV((v2) {0, HEIGHT-30}, (v2) {WIDTH, 30}, COLOR_BLACK);

    for (u8 i = 0; i < object_count; i++)
    {
        object_draw(object_list[i]);
    }

    ClearBackground(COLOR_WHITE);
}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(WIDTH, HEIGHT, TITLE);

    start();

    while (!WindowShouldClose())
    {
        update();
        
        BeginDrawing();
        draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
