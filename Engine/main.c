#include "raylib.h"

#include "simulation.h"
#include "game_time.h"

#include "Utility/init.h"

#include <time.h>

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(WIDTH, HEIGHT, TITLE);

    start();

    GameTime gameTime;

    float totalTimeSinceUpdate = 0;
    float previousTimeElapsed = 0;
    float totalTimeElapsed;
    float deltaTime;

    while (!WindowShouldClose())
    {
        float elapsedTime = clock();

        totalTimeElapsed = (float) elapsedTime / CLOCKS_PER_SEC;
        deltaTime = totalTimeElapsed - previousTimeElapsed;
        previousTimeElapsed = totalTimeElapsed;

        totalTimeSinceUpdate += deltaTime;

        if (totalTimeSinceUpdate >= (float) 1/60)
        {
            gameTime.deltaTime = totalTimeSinceUpdate;
            gameTime.totalElapsedTime = elapsedTime / CLOCKS_PER_SEC;
            totalTimeSinceUpdate = 0;

            update(&gameTime);

            BeginDrawing();
            draw();
            EndDrawing();
        }
    }

    CloseWindow();

    return 0;
}
