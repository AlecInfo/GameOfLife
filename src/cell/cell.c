/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: cell.c
 * Description: This file contains the implementation of the cell behavior
 * within the Game of Life project. It defines the rendering logic for each
 * cell in the grid, determining its color based on its current state.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It encapsulates the logic
 * required to render a cell on the grid. All rights reserved.
 ***********************************************************************/

#include "../inc/cell.h"
#include "../inc/constants.h"

/**
 * Renders a cell at the specified position with the given size.
 *
 * @param cell The cell to render
 * @param renderer The renderer to use
 * @param x The x position of the cell
 * @param y The y position of the cell
 * @param cellSize The size of the cell
 */
void Cell_render(Cell* cell, SDL_Renderer* renderer, int x, int y, int cellSize) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = cellSize;
    rect.h = cellSize;

    // Choose the color of the cell depending on its state (alive or dead)
    if (cell->isAlive) {
        int red = (ALIVE_COLOR >> 24) & 0xFF; // Shift by 24 bits to get RR
        int green = (ALIVE_COLOR >> 16) & 0xFF; // Shift by 16 bits to get GG
        int blue = (ALIVE_COLOR >> 8) & 0xFF; // Shift by 8 bits to get BB
        int alpha = ALIVE_COLOR & 0xFF; // No shift needed to get AA

        SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    } else {
        int red = (DEAD_COLOR >> 24) & 0xFF; // Shift by 24 bits to get RR
        int green = (DEAD_COLOR >> 16) & 0xFF; // Shift by 16 bits to get GG
        int blue = (DEAD_COLOR >> 8) & 0xFF; // Shift by 8 bits to get BB
        int alpha = DEAD_COLOR & 0xFF; // No shift needed to get AA

        SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    }

    SDL_RenderFillRect(renderer, &rect);
}

