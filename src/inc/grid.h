//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/inc/grid.h
#ifndef GRID_H
#define GRID_H

#include "cell.h"

typedef struct Grid {
    Cell** cells;
    int width;
    int height;
} Grid;

void Grid_init(Grid* grid, int width, int height);
void Grid_update(Grid* grid);
void Grid_render(Grid* grid, SDL_Renderer* renderer);
void Grid_clean(Grid* grid);

#endif

