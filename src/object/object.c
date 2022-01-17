#include "object.h"

Object object_new(f32 size, f32 mass, v2 pos, v2 force, Color color)
{
	Object object = {
		size,
		mass,
		pos,
		ZERO,
		ZERO,
		force,
		color
	};

	return object;
}

void object_update(Object *this)
{
	// Update acceleration
	this->acceleration.x = this->external_force.x / this->mass;
	this->acceleration.y = -(this->external_force.y / this->mass + GRAVITY);

	this->external_force = ZERO;

	// Update position
	f32 adjustedPosX = this->position.x + ((this->velocity.x + this->acceleration.x) * GetFrameTime());
	f32 adjustedPosY = this->position.y + ((this->velocity.y + this->acceleration.y) * GetFrameTime());

	// Clamp position within width of window
	if (adjustedPosX < WIDTH - this->size && adjustedPosX > 0)
	{
		this->velocity.x += this->acceleration.x;
		this->position.x += this->velocity.x * GetFrameTime();
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

	// Clamp position within height of window
	if (adjustedPosY < HEIGHT - this->size - GROUND_OFFSET)
	{
		this->velocity.y += this->acceleration.y;
		this->position.y += this->velocity.y * GetFrameTime();
	}
	else
	{
		this->acceleration.y = 0;
		this->velocity.y = 0;
		this->position.y = HEIGHT - this->size - GROUND_OFFSET;
	}	
}

void object_draw(Object *this)
{
	DrawRectangleV(this->position, (v2) {this->size, this->size}, this->color);
}

v2 object_get_velocity(Object *this)
{
	return this->velocity;
}
