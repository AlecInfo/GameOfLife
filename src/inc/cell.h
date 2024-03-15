/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: cell.h
 * Description: Defines the Cell structure and declares the function
 * for rendering a cell. This header file provides the interface for
 * cell manipulation within the grid, contributing to the game's core mechanics.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It outlines the cell's
 * properties and behavior, pivotal for the simulation's visualization and
 * dynamics. All rights reserved.
 ***********************************************************************/

#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>

/**
 * The Cell structure, which includes a flag indicating whether the cell is alive.
 */
typedef struct Cell {
    int isAlive; // A flag indicating whether the cell is alive
} Cell;

/**
 * Renders a cell on the SDL_Renderer at the given coordinates and with the given size.
 *
 * @param cell A pointer to the Cell structure.
 * @param renderer A pointer to the SDL_Renderer.
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 * @param cellSize The size of the cell.
 */
void Cell_render(Cell* cell, SDL_Renderer* renderer, int x, int y, int cellSize);

#endif