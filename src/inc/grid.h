/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: grid.h
 * Description: Declares the Grid structure and associated functions for
 * initializing, updating, rendering, and cleaning up the grid. This header
 * plays a crucial role in managing the cellular automaton's environment,
 * facilitating the simulation of life cycles on the grid.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It outlines the framework for the grid where
 * cells live, die, and evolve, according to Conway's rules. The grid's management is
 * fundamental to the Game of Life's simulation. All rights reserved.
 ***********************************************************************/

#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include "patterns.h"

/**
 * The Grid structure, which includes the cells, width, and height of the grid.
 */
typedef struct Grid {
    Cell** cells; // The cells in the grid
    int width; // The width of the grid
    int height; // The height of the grid
} Grid;

/**
 * Initializes a grid with the given width and height.
 * Allocates memory for the cells and sets all cells to dead.
 *
 * @param grid A pointer to the Grid structure.
 * @param width The width of the grid.
 * @param height The height of the grid.
 */
void Grid_init(Grid* grid, int width, int height);

/**
 * Updates the state of the cells in the grid according to the game rules.
 *
 * @param grid A pointer to the Grid structure.
 */
void Grid_update(Grid* grid);

/**
 * Renders the grid on the SDL_Renderer.
 *
 * @param grid A pointer to the Grid structure.
 * @param renderer A pointer to the SDL_Renderer.
 */
void Grid_render(Grid* grid, SDL_Renderer* renderer);

/**
 * Frees the memory allocated for the cells in the grid.
 *
 * @param grid A pointer to the Grid structure.
 */
void Grid_clean(Grid* grid);

/**
 * Sets all cells in the grid to dead.
 *
 * @param grid A pointer to the Grid structure.
 */
void Grid_clear(Grid* grid);

/**
 * Counts the number of alive neighbors for a cell at the given coordinates.
 *
 * @param grid A pointer to the Grid structure.
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 * @return The number of alive neighbors.
 */
int countAliveNeighbors(Grid* grid, int x, int y);

/**
 * Places a pattern on the grid.
 *
 * @param grid A pointer to the Grid structure.
 * @param pattern A pointer to the Pattern structure.
 */
void placePattern(Grid* grid, const Pattern* pattern);

#endif