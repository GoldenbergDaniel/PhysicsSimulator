#include "globals.h"
#include "simulation.h"

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
