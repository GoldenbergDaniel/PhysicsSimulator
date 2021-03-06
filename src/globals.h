#ifndef PHYSICSSIMULATOR_GLOBALS_H
#define PHYSICSSIMULATOR_GLOBALS_H

#include "raylib.h"
#include "game_time.h"

#define TITLE "Physics Simulator"
#define WIDTH (float) 800
#define HEIGHT (float) 450

#define ZERO (Vector2) {0, 0}
#define CENTER (Vector2) {(float) WIDTH/2, (float) HEIGHT/2}

#define COLOR_BLACK (Color) {19, 19, 19, 255}
#define COLOR_WHITE (Color) {236, 236, 236, 255}
#define COLOR_RED (Color) {229, 78, 48, 255}
#define COLOR_GREEN (Color) {100, 160, 60, 255}
#define COLOR_BLUE (Color) {55, 107, 186, 255}

#define GRAVITY -9.81f

#endif
