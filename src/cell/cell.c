//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/cell/cell.c
#include "../inc/cell.h"
#include "../inc/constants.h"

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

