#pragma once

// Check for range intersection
bool range_intersect(f32 min1, f32 max1, f32 min2, f32 max2);

// Check for object intersection
bool collision(Object *obj1, Object *obj2);

// Recalculate velocity after collision
v2 recalculate_velocity(Object *obj1);
