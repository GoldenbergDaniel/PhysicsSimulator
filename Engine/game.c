#include "raylib.h"
#include "game_time.h"

#include "./Utility/init.h"
#include "./Objects/shape.h"

const float gravity = (float) -9.81*2;

Shape *circle = &(Shape) {ZERO, ZERO, ZERO, 1, 15};

Vector2 netExternalForces = (Vector2) {300, 0};

void start()
{
    circle->position = (Vector2) {50, 50};
}

void update(GameTime *gameTime)
{
    if (gameTime->totalElapsedTime > 0.5)
    {
        circle->acceleration.x = (netExternalForces.x / circle->mass);
        circle->acceleration.y = -((netExternalForces.y / circle->mass) + gravity);

        netExternalForces = ZERO;

        if (circle->position.y + (circle->velocity.y + circle->acceleration.y) * gameTime->deltaTime <= HEIGHT - circle->radius)
        {
            circle->velocity.y += circle->acceleration.y;
            circle->position.y += circle->velocity.y * gameTime->deltaTime;
        }

        if (circle->position.x + (circle->velocity.x + circle->acceleration.x) * gameTime->deltaTime <= WIDTH - circle->radius)
        {
            circle->velocity.x += circle->acceleration.x;
            circle->position.x += circle->velocity.x * gameTime->deltaTime;
        }
    }
}

void draw()
{
    DrawRectangleV((Vector2) {0, HEIGHT-25}, (Vector2) {WIDTH, 50}, COLOR_BLACK);

    DrawCircleV(circle->position, circle->radius, COLOR_BLUE);

    DrawText(TextFormat("%.00f", circle->acceleration.y), WIDTH-50, 50, 20, COLOR_BLACK);

    ClearBackground(COLOR_WHITE);
}
