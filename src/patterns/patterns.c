/***********************************************************************
 * Author: Alec Piette
 * Created on: 14.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: patterns.c
 * Description: Defines various patterns that can be placed in the Game of Life grid.
 * Includes patterns like Glider, Gosper Glider Gun, and others, along with their
 * initialization coordinates. Allows for dynamic placement of complex structures
 * within the game.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It contains definitions for several
 * pre-defined patterns, enhancing the game by providing interesting starting points
 * for the simulation. All rights reserved.
 ***********************************************************************/

#include "../inc/patterns.h"

// Glider pattern
// The glider is a pattern that moves diagonally
const int glider_coords[][2] = {
        {1, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}
};

// Gosper Glider Gun pattern
// The Gosper Glider Gun is the first known pattern with unbounded growth
const int glider_gun_coords[][2] = {
        {1, 5}, {1, 6}, {2, 5}, {2, 6},
        {11, 5}, {11, 6}, {11, 7}, {12, 4}, {12, 8}, {13, 3}, {13, 9}, {14, 3}, {14, 9}, {15, 6}, {16, 4}, {16, 8}, {17, 5}, {17, 6}, {17, 7}, {18, 6},
        {21, 3}, {21, 4}, {21, 5}, {22, 3}, {22, 4}, {22, 5}, {23, 2}, {23, 6}, {25, 1}, {25, 2}, {25, 6}, {25, 7},
        {35, 3}, {35, 4}, {36, 3}, {36, 4}
};

// Pulsar pattern
// The pulsar is a pattern that oscillates
const int pulsar_coords[][2] = {
        {2, 4}, {2, 5}, {2, 6}, {2, 10}, {2, 11}, {2, 12},
        {4, 2}, {4, 7}, {4, 9}, {4, 14},
        {5, 2}, {5, 7}, {5, 9}, {5, 14},
        {6, 2}, {6, 7}, {6, 9}, {6, 14},
        {7, 4}, {7, 5}, {7, 6}, {7, 10}, {7, 11}, {7, 12},
        {9, 4}, {9, 5}, {9, 6}, {9, 10}, {9, 11}, {9, 12},
        {10, 2}, {10, 7}, {10, 9}, {10, 14},
        {11, 2}, {11, 7}, {11, 9}, {11, 14},
        {12, 2}, {12, 7}, {12, 9}, {12, 14},
        {14, 4}, {14, 5}, {14, 6}, {14, 10}, {14, 11}, {14, 12}
};

// Hammerhead spaceship pattern
// The hammerhead spaceship is a pattern that moves
// TODO : Invert the pattern to make it move to the right
const int hammerhead_coords[][2] = {
        {1, 1}, {1, 2},{1, 3}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 2}, {2, 4},
        {4, 5}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 7}, {8, 9}, {9, 10}, {7, 10},{6, 11}, {5, 12}, {4, 12},
        {2, 13}, {1, 14}, {1, 15}, {1, 16}, {2, 16}, {3, 16}, {4, 16}, {5, 16}, {6, 15},
        {9, 5}, {10, 5}, {11, 6}, {11, 7},
        {12, 4}, {12, 5}, {13, 5}, {13, 4}, {13, 3}, {14, 3}, {14, 2}, {15, 2},
        {13, 7}, {14, 6},
        {15, 4}, {16, 4}, {16, 5}, {17, 5}, {17, 4}, {18, 4}, {18, 3}, {17, 3}, {16, 3},
        {11, 10}, {11, 11}, {10, 12}, {9, 12},
        {12, 12}, {13, 12}, {12, 13}, {13, 13}, {13, 14}, {14, 14}, {14, 15}, {15, 15},
        {13, 10}, {14, 11},
        {15, 13}, {16, 13}, {16, 12}, {17, 12}, {17, 13}, {18, 13}, {18, 14}, {17, 14}, {16, 14}
};

// Array of predefined patterns
Pattern patterns[] = {
        {"Glider", SDLK_h, glider_coords, sizeof(glider_coords)/sizeof(glider_coords[0])},
        {"Glider Gun", SDLK_g, glider_gun_coords, sizeof(glider_gun_coords)/sizeof(glider_gun_coords[0])},
        {"Pulsar", SDLK_p, pulsar_coords, sizeof(pulsar_coords)/sizeof(pulsar_coords[0])},
        {"Hammerhead", SDLK_m, hammerhead_coords, sizeof(hammerhead_coords)/sizeof(hammerhead_coords[0])}
};

// Number of patterns
const int patterns_count = sizeof(patterns) / sizeof(patterns[0]);