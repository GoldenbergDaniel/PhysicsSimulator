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

void object_start(Object *this)
{
	this->is_active = true;
    this->curr_color = this->color;
}

void object_update(Object *this)
{
	if (this->is_active) 
	{
		this->acceleration.x = this->net_external_forces.x / this->mass;
	    this->acceleration.y = -(this->net_external_forces.y / this->mass + GRAVITY);
	
	    this->net_external_forces = ZERO;
	
	    f32 adjustedPosX = this->position.x + ((this->velocity.x + this->acceleration.x) * GetFrameTime());
	    f32 adjustedPosY = this->position.y + ((this->velocity.y + this->acceleration.y) * GetFrameTime());
	
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
	
	    if (adjustedPosY < HEIGHT - this->size - 30)
	    {
	        this->velocity.y += this->acceleration.y;
	        this->position.y += this->velocity.y * GetFrameTime();
	    }
	    else
	    {
	        this->acceleration.y = 0;
	        this->velocity.y = 0;
	        this->position.y = HEIGHT - this->size - 30;
	    }	
	}
}

void object_draw(Object *this)
{
	if (this->is_active)
	{
		DrawRectangleV(this->position, (v2) {this->size, this->size}, this->curr_color);	
	}
}

void object_destroy(Object *this)
{
	this->is_active = false;
}
