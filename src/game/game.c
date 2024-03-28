/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 29.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: game.c
 * Description: Manages the main game lifecycle including initialization,
 * event handling, updating game state, rendering, and cleanup. It orchestrates
 * the game loop and processes user input to control the game.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It serves as the core controller
 * for the game, handling the primary game functions and SDL interactions.
 * All rights reserved.
 ***********************************************************************/

#include "../inc/patterns.h"
#include "../inc/game.h"
#include "../inc/constants.h"

/**
 * Initializes a new game with the given title and screen dimensions.
 *
 * @param game A pointer to the Game structure.
 * @param title The title of the game.
 * @param width The width of the game screen.
 * @param height The height of the game screen.
 */
void Game_init(Game *game, const char *title, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, 0);
    game->isRunning = 1;
    game->isPaused = 0;

    // Initialize the objects ...
    Grid_init(&game->grid, width / CELL_SIZE, height / CELL_SIZE); // 10x10 pixels per cell

    // Print the instructions
    printf("Press the following keys to spawn patterns:\n");
    for (int i = 0; i < patterns_count; i++) {
        printf("Press '%c' for %s\n", patterns[i].key, patterns[i].name);
    }
}

/**
 * Runs the game, which includes handling events, updating the game state, and rendering the game.
 *
 * @param game A pointer to the Game structure.
 */
void Game_run(Game *game) {
    while (game->isRunning) {
        Game_handleEvents(game);
        if (!game->isPaused)
            Game_update(game);
        Game_render(game);
    }
}

/**
 * Handles events for the game, such as user input.
 *
 * @param game A pointer to the Game structure.
 */
void Game_handleEvents(Game *game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            game->isRunning = 0; // Quit the game
        } else if (event.type == SDL_KEYDOWN) {

            // Quit the game
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                game->isRunning = 0;
            }

            // Clear the grid
            if (event.key.keysym.sym == SDLK_c) {
                Grid_clear(&game->grid);
            }

            // Pause the game
            if (event.key.keysym.sym == SDLK_SPACE) {
                game->isPaused = !game->isPaused;
            }

            for (int i = 0; i < patterns_count; i++) {
                if (event.key.keysym.sym == patterns[i].key) {
                    //Grid_clear(&game->grid); // Uncomment this line to clear the grid before placing a pattern

                    // Place the pattern on the grid
                    placePattern(&game->grid, &patterns[i]);
                    break;
                }
            }
        }
    }
}

/**
 * Updates the game state, such as the state of the game grid.
 *
 * @param game A pointer to the Game structure.
 */
void Game_update(Game *game) {
    // Update the objects ...
    Grid_update(&game->grid);
}

/**
 * Renders the game, which includes rendering the game grid.
 *
 * @param game A pointer to the Game structure.
 */
void Game_render(Game *game) {
    int red = (BACKGROUND_COLOR >> 24) & 0xFF; // Shift by 24 bits to get RR
    int green = (BACKGROUND_COLOR >> 16) & 0xFF; // Shift by 16 bits to get GG
    int blue = (BACKGROUND_COLOR >> 8) & 0xFF; // Shift by 8 bits to get BB
    int alpha = BACKGROUND_COLOR & 0xFF; // No shift needed to get AA

    SDL_SetRenderDrawColor(game->renderer, red, green, blue, alpha);
    SDL_RenderClear(game->renderer);

    // Render the objects ...
    Grid_render(&game->grid, game->renderer);

    SDL_RenderPresent(game->renderer);
}

/**
 * Cleans up after the game has ended, such as freeing allocated memory.
 *
 * @param game A pointer to the Game structure.
 */
void Game_clean(Game *game) {
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    Grid_clean(&game->grid);
    SDL_Quit();
}

