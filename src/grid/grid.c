//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/grid/grid.c
#include "../inc/grid.h"
#include "../inc/constants.h"
#include <stdlib.h>

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

    // The glider gun pattern
    int gun[][2] = {
            {5, 1}, {5, 2}, {6, 1}, {6, 2},
            {5, 11}, {6, 11}, {7, 11}, {4, 12}, {8, 12},
            {3, 13}, {9, 13}, {3, 14}, {9, 14},
            {6, 15}, {4, 16}, {8, 16}, {5, 17}, {6, 17}, {7, 17},
            {6, 18}, {3, 21}, {4, 21}, {5, 21}, {3, 22}, {4, 22},
            {5, 22}, {2, 23}, {6, 23}, {1, 25}, {2, 25}, {6, 25},
            {7, 25}, {3, 35}, {4, 35}, {3, 36}, {4, 36}
    };

    // Set the cells of the glider gun pattern to alive
    for (int i = 0; i < sizeof(gun)/sizeof(gun[0]); i++) {
        int x = gun[i][0], y = gun[i][1];
        if (x < width && y < height) {
            grid->cells[y][x].isAlive = 1;
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
