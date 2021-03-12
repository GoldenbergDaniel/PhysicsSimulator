#include "raylib.h"
#include "game_time.h"

#include "./Objects/circle.h"
#include "./Utility/init.h"

const float gravity = (float) -9.81 * 2;

Circle *circle = &(Circle) {ZERO, ZERO, ZERO, 15, 1};

Vector2 netExternalForces = (Vector2) {300, 200};

void start()
{
    circle->position = (Vector2) {50, 50};
}

void update(GameTime *gameTime)
{
    circle->acceleration.x = (netExternalForces.x / circle->mass);
    circle->acceleration.y = -((netExternalForces.y / circle->mass) + gravity);

    netExternalForces = ZERO;

    if (circle->position.y + circle->velocity.y * gameTime->deltaTime < HEIGHT - circle->radius / 2)
    {
        circle->velocity.x += circle->acceleration.x;
        circle->velocity.y += circle->acceleration.y;

        circle->position.y += circle->velocity.y * gameTime->deltaTime;
    }

    circle->position.x += circle->velocity.x * gameTime->deltaTime;
}

void draw()
{
    DrawCircleV(circle->position, circle->radius, COLOR_BLUE);

    ClearBackground(COLOR_WHITE);
}
