#include <stdio.h>

#include "globals.h"

#include "./object/object.h"
#include "./storage/storage.h"
#include "./utility/collision.h"

Object square1;
Object square2;
Storage storage;

const i32 object_count = 2;
Object *object_list[object_count];

void start()
{
    // Square1 Input
    printf("Force applied on right object (x y): ");
    scanf("%f %f", &storage.external_force1.x, &storage.external_force1.y);
    printf("Mass of right object: ");
    scanf("%f", &storage.mass1);

    // Square2 Input
    printf("Force applied on left object (x y): ");
    scanf("%f %f", &storage.external_force2.x, &storage.external_force2.y);
    printf("Mass of left object: ");
    scanf("%f", &storage.mass2);

    square1 = object_new(
        75, 
        storage.mass1, 
        (v2) {200, 200},
        (v2) {storage.external_force1.x, storage.external_force1.y}, 
        COLOR_BLUE
    );

    square2 = object_new(
        100, 
        storage.mass2, 
        (v2) {WIDTH-200, 200},
        (v2) {storage.external_force2.x, storage.external_force2.y},
        COLOR_GREEN
    );

    object_list[0] = &square1;
    object_list[1] = &square2;
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
        if (collision(&square1, &square2))
        {
            recalculate_velocities(&square1, &square2);
        }
    }
}

void draw()
{
    DrawRectangleV((v2) {0, HEIGHT-GROUND_OFFSET}, (v2) {WIDTH, GROUND_OFFSET}, COLOR_BLACK);

    i8 buffer[20];
    sprintf(buffer, "%f", storage.external_force1.x);

    DrawText(buffer, 100, 100, 20, BLACK);

    for (u8 i = 0; i < object_count; i++)
    {
        object_draw(object_list[i]);
    }

    ClearBackground(COLOR_WHITE);
}

int main()
{
    start();

    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    SetTargetFPS(60);

    InitWindow(WIDTH, HEIGHT, TITLE);

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
