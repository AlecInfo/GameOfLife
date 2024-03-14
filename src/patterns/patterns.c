//
// Created by ALEC PTT on 14.03.2024.
// Last update on 14.03.2024.
//

// src/patterns/patterns.c
#include "../inc/patterns.h"

// Glider pattern
// The glider is a pattern that moves diagonally
int glider_coords[][2] = {
        {1, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}
};

// Gosper Glider Gun pattern
// The Gosper Glider Gun is the first known pattern with unbounded growth
int glider_gun_coords[][2] = {
        {1, 5}, {1, 6}, {2, 5}, {2, 6},
        {11, 5}, {11, 6}, {11, 7}, {12, 4}, {12, 8}, {13, 3}, {13, 9}, {14, 3}, {14, 9}, {15, 6}, {16, 4}, {16, 8}, {17, 5}, {17, 6}, {17, 7}, {18, 6},
        {21, 3}, {21, 4}, {21, 5}, {22, 3}, {22, 4}, {22, 5}, {23, 2}, {23, 6}, {25, 1}, {25, 2}, {25, 6}, {25, 7},
        {35, 3}, {35, 4}, {36, 3}, {36, 4}

};

int

// Other patterns ...

// Table of patterns
Pattern patterns[] = {
        {"Glider", SDLK_h, glider_coords, sizeof(glider_coords)/sizeof(glider_coords[0])},
        {"Gosper Glider Gun", SDLK_g, glider_gun_coords, sizeof(glider_gun_coords)/sizeof(glider_gun_coords[0])},
        // Other patterns ...
};

// Number of patterns
const int patterns_count = sizeof(patterns) / sizeof(patterns[0]);