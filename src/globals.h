#pragma once

#include "raylib.h"

// Config
#define TITLE "Physics Simulator"
#define WIDTH (f32) 800
#define HEIGHT (f32) 450

#define GRAVITY -9.81f
#define GROUND_OFFSET 50

// Colors
#define COLOR_BLACK (Color) {19, 19, 19, 255}
#define COLOR_WHITE (Color) {236, 236, 236, 255}
#define COLOR_GREEN (Color) {100, 160, 60, 255}
#define COLOR_BLUE (Color) {55, 107, 186, 255}

// Shorthands
#define ZERO (v2) {0, 0}

// Type shorthands
typedef unsigned char u8;
typedef short unsigned int u16;
typedef unsigned int u32;
typedef long unsigned int u64;
typedef char i8;
typedef short int i16;
typedef int i32;
typedef long int i64;
typedef float f32;
typedef double f64;
typedef Vector2 v2;
