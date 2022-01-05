#pragma once

#include "../globals.h"

typedef struct Storage
{
    v2 position1;
    v2 position2;
    v2 external_force1;
    v2 external_force2;
    f32 mass1;
    f32 mass2;
} Storage;
