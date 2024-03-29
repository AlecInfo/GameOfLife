/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 29.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: game.h
 * Description: Declares the Game structure and functions related to the
 * game lifecycle, including initialization, event handling, updating, rendering,
 * and cleanup. This header centralizes the management of the game's main loop
 * and state transitions.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It defines the overarching structure
 * and functions that drive the game's execution, serving as the backbone of the
 * simulation's control flow. All rights reserved.
 ***********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "grid.h"

/**
 * The Game structure, which includes the SDL window and renderer, a flag indicating
 * whether the game is running, and the game grid.
 */
typedef struct Game {
    SDL_Window* window; // The SDL window for the game
    SDL_Renderer* renderer; // The SDL renderer for the game
    int isRunning; // A flag indicating whether the game is running
    int isPaused; // A flag indicating whether the game is paused
    Grid grid; // The game grid
    int isInPatternPlacementMode; // A flag indicating whether the game is in pattern mode
    int patternPlacementX; // The x-coordinate for pattern placement
    int patternPlacementY; // The y-coordinate for pattern placement
    const Pattern* selectedPattern; // The selected pattern for placement
} Game;

/**
 * Initializes a new game with the given title and screen dimensions.
 *
 * @param game A pointer to the Game structure.
 * @param title The title of the game.
 * @param width The width of the game screen.
 * @param height The height of the game screen.
 */
void Game_init(Game* game, const char* title, int width, int height);

/**
 * Runs the game, which includes handling events, updating the game state, and rendering the game.
 *
 * @param game A pointer to the Game structure.
 */
void Game_run(Game* game);

/**
 * Handles events for the game, such as user input.
 *
 * @param game A pointer to the Game structure.
 */
void Game_handleEvents(Game* game);

/**
 * Updates the game state, such as the state of the game grid.
 *
 * @param game A pointer to the Game structure.
 */
void Game_update(Game* game);

/**
 * Renders the game, which includes rendering the game grid.
 *
 * @param game A pointer to the Game structure.
 */
void Game_render(Game* game);

/**
 * Cleans up after the game has ended, such as freeing allocated memory.
 *
 * @param game A pointer to the Game structure.
 */
void Game_clean(Game* game);

#endif