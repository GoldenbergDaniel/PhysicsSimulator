#include "object.h"

void object_start(Object *this)
{
	this->isActive = true;
    this->currColor = this->color;
}

void object_update(Object *this)
{
	if (this->isActive) 
	{
		this->acceleration.x = this->netExternalForces.x / this->mass;
	    this->acceleration.y = -(this->netExternalForces.y / this->mass + GRAVITY);
	
	    this->netExternalForces = ZERO;
	
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
	
	    if (adjustedPosY < HEIGHT - 30 - this->size)
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
	if (this->isActive)
	{
		DrawRectangleV(this->position, (v2) {this->size, this->size}, this->currColor);	
	}
}

void object_destroy(Object *this)
{
	this->isActive = false;
}
