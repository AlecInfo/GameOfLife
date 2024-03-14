//
// Created by ALEC PTT on 14.03.2024.
// Last update on 12.03.2024.
//

// src/inc/grid.h
#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include "patterns.h"

typedef struct Grid {
    Cell** cells;
    int width;
    int height;
} Grid;

void Grid_init(Grid* grid, int width, int height);
void Grid_update(Grid* grid);
void Grid_render(Grid* grid, SDL_Renderer* renderer);
void Grid_clean(Grid* grid);
void Grid_clear(Grid* grid);
int countAliveNeighbors(Grid* grid, int x, int y);
void placePattern(Grid* grid, const Pattern* pattern);

#endif

