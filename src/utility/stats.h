#pragma once

#include "../globals.h"

void displayStat(float stat, v2 *pos, Color color)
{
    DrawText(TextFormat("%.2f", stat), (i32) pos->x, (i32) pos->y, 20, color);
}
