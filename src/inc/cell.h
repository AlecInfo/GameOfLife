//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/inc/cell.h
#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>

typedef struct Cell {
    int isAlive;
} Cell;

void Cell_render(Cell* cell, SDL_Renderer* renderer, int x, int y, int cellSize);

#endif

