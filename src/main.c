#include <stdio.h>

#include "globals.h"

#include "./object/object.h"
#include "./collision/collision.h"

Object square1;
Object square2;

const i32 object_count = 2;
Object *object_list[object_count];

// Start program
void start()
{
    // Input variables for Square1
    v2 external_force1;
    f32 mass1;

    // Input variables for Square2
    v2 external_force2;
    f32 mass2;

    // Square1 input
    printf("Force applied on right object (-1000<>1000) (x y): ");
    scanf("%f %f", &external_force1.x, &external_force1.y);
    printf("Mass of right object (0.1<>100): ");
    scanf("%f", &mass1);

    // Square2 input
    printf("Force applied on left object (-1000<>1000) (x y): ");
    scanf("%f %f", &external_force2.x, &external_force2.y);
    printf("Mass of left object (0.1<>100): ");
    scanf("%f", &mass2);

    square1 = object_new(
        75, 
        mass1, 
        (v2) {200, 200},
        (v2) {external_force1.x, external_force1.y}, 
        COLOR_BLUE
    );

    square2 = object_new(
        100, 
        mass2, 
        (v2) {WIDTH-200, 200},
        (v2) {external_force2.x, external_force2.y},
        COLOR_GREEN
    );

    object_list[0] = &square1;
    object_list[1] = &square2;
}

// Update physics
void update()
{
    if (GetTime() > 0.25f)
    {
        // Logic
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

// Draw to window
void draw()
{
    // Ground
    DrawRectangleV((v2) {0, HEIGHT-GROUND_OFFSET}, (v2) {WIDTH, GROUND_OFFSET}, COLOR_BLACK);

    // Text
    DrawText(TextFormat("Vel1: %f", object_get_velocity(object_list[0]).x), 100, 30, 20, BLACK);
    DrawText(TextFormat("Vel2: %f", object_get_velocity(object_list[1]).x), 600, 30, 20, BLACK);

    // Objects
    for (u8 i = 0; i < object_count; i++)
    {
        object_draw(object_list[i]);
    }

    // Background
    ClearBackground(COLOR_WHITE);
}

int main()
{
    start();

    // Config program arguments
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    SetTargetFPS(60);

    InitWindow(WIDTH, HEIGHT, TITLE);

    // Game loop
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
