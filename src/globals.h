#pragma once

#include "raylib.h"

#define TITLE "Physics Simulator"
#define WIDTH (f32) 800
#define HEIGHT (f32) 450

#define ZERO (v2) {0, 0}
#define CENTER (v2) {(f32) WIDTH/2, (f32) HEIGHT/2}

#define COLOR_BLACK (Color) {19, 19, 19, 255}
#define COLOR_WHITE (Color) {236, 236, 236, 255}
#define COLOR_RED (Color) {229, 78, 48, 255}
#define COLOR_GREEN (Color) {100, 160, 60, 255}
#define COLOR_BLUE (Color) {55, 107, 186, 255}

#define GRAVITY -9.81f

#define NIL 0

typedef unsigned char u8;
typedef short unsigned int u16;
typedef unsigned int u32;
typedef long unsigned int u64;
typedef char i8;
typedef short int i16;
typedef int i32;
typedef long int i64;
typedef float f32;
typedef long f64;
typedef Vector2 v2;
typedef Vector3 v3;
typedef Vector4 v4;
typedef Matrix m4;
