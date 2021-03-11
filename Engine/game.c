#include "raylib.h"
#include "game_time.h"

#include "./Content/circle.h"
#include "./Utility/init.h"

const float gravity = (float) -9.81 * 2;

Circle *circle = &(Circle) {(Vector2){0, 0}, (Vector2){0, 0}, 0, 20, 20, 1};

Vector2 externalForce = (Vector2) {300, 200};

void start()
{
    circle->position = (Vector2) {0, 100};
}

void update(GameTime *gameTime)
{
    circle->acceleration.x = (externalForce.x / circle->mass);
    circle->acceleration.y = (externalForce.y / circle->mass) + gravity;

    externalForce = (Vector2) {0, 0};

    if (circle->position.y - circle->velocity.y * gameTime->deltaTime < HEIGHT - circle->radius/2)
    {
        circle->velocity.x += circle->acceleration.x;
        circle->velocity.y += circle->acceleration.y;

        circle->position.x += circle->velocity.x * gameTime->deltaTime;
        circle->position.y -= circle->velocity.y * gameTime->deltaTime;
    }
}

void draw()
{
    DrawCircleV(circle->position, circle->radius, COLOR_BLUE);

    ClearBackground(COLOR_WHITE);
}
