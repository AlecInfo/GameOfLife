/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: grid.c
 * Description: Implements the grid functionalities for the Game of Life,
 * including initializing the grid, updating cell states according to the
 * game rules, rendering the grid, and handling user-defined patterns.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It includes operations for
 * managing the game grid, such as cell updates and pattern placement,
 * essential for simulating Conway's Game of Life. All rights reserved.
 ***********************************************************************/

#include "../inc/grid.h"
#include "../inc/patterns.h"
#include "../inc/constants.h"
#include <stdlib.h>

/**
 * Initializes the grid with the specified width and height.
 *
 * @param grid The grid to initialize
 * @param width The width of the grid
 * @param height The height of the grid
 */
void Grid_init(Grid* grid, int width, int height) {
    grid->width = width;
    grid->height = height;

    grid->cells = malloc(sizeof(Cell*) * height);
    for (int i = 0; i < height; i++) {
        grid->cells[i] = malloc(sizeof(Cell) * width);
        for (int j = 0; j < width; j++) {
            grid->cells[i][j].isAlive = 0; // Initialize all cells to dead
        }
    }
}

/**
 * Updates the grid according to the rules of the Game of Life.
 *
 * @param grid The grid to update
 */
void Grid_update(Grid* grid) {
    // Create a new grid to store the new state of the cells
    Cell** newCells = malloc(sizeof(Cell*) * grid->height);
    for (int i = 0; i < grid->height; i++) {
        newCells[i] = malloc(sizeof(Cell) * grid->width);
        for (int j = 0; j < grid->width; j++) {
            int aliveNeighbors = countAliveNeighbors(grid, j, i);
            Cell currentCell = grid->cells[i][j];
            Cell* newCell = &newCells[i][j];
            if (currentCell.isAlive) {
                newCell->isAlive = (aliveNeighbors == 2 || aliveNeighbors == 3);
            } else {
                newCell->isAlive = (aliveNeighbors == 3);
            }
        }
    }

    // Replace the old grid with the new one
    for (int i = 0; i < grid->height; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    grid->cells = newCells;
}

/**
 * Renders the grid on the screen.
 *
 * @param grid The grid to render
 * @param renderer The SDL renderer to use
 */
void Grid_render(Grid* grid, SDL_Renderer* renderer) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            Cell_render(&grid->cells[i][j], renderer, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE); // 10x10 pixels per cell
        }
    }
}

/**
 * Cleans up the grid, freeing the memory allocated for the cells.
 *
 * @param grid The grid to clean up
 */
void Grid_clean(Grid* grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
}

/**
 * Clears the grid, setting all cells to dead.
 *
 * @param grid The grid to clear
 */
void Grid_clear(Grid* grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            grid->cells[i][j].isAlive = 0;
        }
    }
}

/**
 * Counts the number of alive neighbors around a cell.
 *
 * @param grid The grid containing the cell
 * @param x The x-coordinate of the cell
 * @param y The y-coordinate of the cell
 *
 * @return The number of alive neighbors
 */
int countAliveNeighbors(Grid* grid, int x, int y) {
    int aliveNeighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself

            int checkX = x + i;
            int checkY = y + j;

            // Check boundaries
            if (checkX >= 0 && checkX < grid->width && checkY >= 0 && checkY < grid->height) {
                Cell *neighborCell = &grid->cells[checkY][checkX];
                aliveNeighbors += neighborCell->isAlive ? 1 : 0;
            }
        }
    }
    return aliveNeighbors;
}

/**
 * Places a pattern on the grid at the specified coordinates.
 *
 * @param grid The grid to place the pattern on
 * @param pattern The pattern to place
 */
void placePattern(Grid* grid, const Pattern* pattern) {
    for (int i = 0; i < pattern->n_coords; i++) {
        int x = pattern->coords[i][0];
        int y = pattern->coords[i][1];
        if (x < grid->width && y < grid->height) {
            grid->cells[y][x].isAlive = 1;
        }
    }
}
