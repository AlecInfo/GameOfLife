//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/grid/grid.c
#include "../inc/grid.h"
#include "../inc/patterns.h"
#include "../inc/constants.h"
#include <stdlib.h>

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


void Grid_render(Grid* grid, SDL_Renderer* renderer) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            Cell_render(&grid->cells[i][j], renderer, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE); // 10x10 pixels per cell
        }
    }
}

void Grid_clean(Grid* grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
}

void Grid_clear(Grid* grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            grid->cells[i][j].isAlive = 0;
        }
    }
}

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

void placePattern(Grid* grid, const Pattern* pattern) {
    for (int i = 0; i < pattern->n_coords; i++) {
        int x = pattern->coords[i][0];
        int y = pattern->coords[i][1];
        if (x < grid->width && y < grid->height) {
            grid->cells[y][x].isAlive = 1;
        }
    }
}
