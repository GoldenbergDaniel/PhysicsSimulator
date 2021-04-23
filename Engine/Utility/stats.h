#ifndef PHYSICSSIMULATOR_STATS_H
#define PHYSICSSIMULATOR_STATS_H

void displayStat(float stat, Vector2 *pos, Color color)
{
    DrawText(TextFormat("%.2f", stat), (int) pos->x, (int) pos->y, 20, color);
}

#endif
