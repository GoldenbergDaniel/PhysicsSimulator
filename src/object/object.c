#include "object.h"

void object_start(Object *this)
{
    this->currColor = this->color;
}

void object_update(Object *this, GameTime* gameTime)
{
    this->acceleration.x = this->netExternalForces.x / this->mass;
    this->acceleration.y = -(this->netExternalForces.y / this->mass + GRAVITY);

    this->netExternalForces = ZERO;

    float adjustedPosX = this->position.x + ((this->velocity.x + this->acceleration.x) * gameTime->deltaTime);
    float adjustedPosY = this->position.y + ((this->velocity.y + this->acceleration.y) * gameTime->deltaTime);

    if (adjustedPosX < WIDTH - this->size && adjustedPosX > 0)
    {
        this->velocity.x += this->acceleration.x;
        this->position.x += this->velocity.x * gameTime->deltaTime;
    }
    else
    {
        this->acceleration.x = 0;
        this->velocity.x = 0;

        if (adjustedPosX < 0)
        {
            this->position.x = 0;
        }
        else if (adjustedPosX > WIDTH - this->size)
        {
            this->position.x = WIDTH - this->size;
        }
    }

    if ( adjustedPosY < HEIGHT - 30 - this->size)
    {
        this->velocity.y += this->acceleration.y;
        this->position.y += this->velocity.y * gameTime->deltaTime;
    }
    else
    {
        this->acceleration.y = 0;
        this->velocity.y = 0;
        this->position.y = HEIGHT - this->size - 30;
    }
}

void object_draw(Object *this)
{
    if (strcmp(this->type, "circle") == 0)
    {
        DrawCircleV(this->position, this->size, this->currColor);
    }
    else if (strcmp(this->type, "square") == 0)
    {
        DrawRectangleV(this->position, (Vector2) {this->size, this->size}, this->currColor);
    }
}
