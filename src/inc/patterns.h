/***********************************************************************
 * Author: Alec Piette
 * Created on: 14.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: patterns.h
 * Description: Defines the Pattern structure and declares an array of
 * predefined patterns. This header facilitates the introduction of complex
 * structures into the game grid, allowing for dynamic and interesting simulations.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It catalogues various patterns that can
 * be spawned within the game, such as the Glider and the Gosper Glider Gun, enhancing
 * the visual and interactive aspects of the simulation. All rights reserved.
 ***********************************************************************/

#ifndef PATTERNS_H
#define PATTERNS_H

#include <SDL2/SDL.h>

/**
 * The Pattern structure, which includes the name of the pattern, a key for the pattern,
 * an array of coordinates for the cells in the pattern, and the number of coordinates.
 */
typedef struct {
    const char* name; // The name of the pattern
    const int key; // The key for the pattern
    const int (*const coords)[2]; // The coordinates for the cells in the pattern
    const int n_coords; // The number of coordinates
} Pattern;

/**
 * An array of predefined patterns.
 */
extern Pattern patterns[];

/**
 * The number of predefined patterns.
 */
extern const int patterns_count;

#endif