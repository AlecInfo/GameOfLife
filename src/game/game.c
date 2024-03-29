/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 15.03.2024
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

void Game_init(Game *game, const char *title, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, 0);
    game->isRunning = 1;

    // Initialize the objects ...
    Grid_init(&game->grid, width / CELL_SIZE, height / CELL_SIZE); // 10x10 pixels per cell

    // Print the instructions
    printf("Press the following keys to spawn patterns:\n");
    for (int i = 0; i < patterns_count; i++) {
        printf("Press '%c' for %s\n", patterns[i].key, patterns[i].name);
    }
}

void Game_run(Game *game) {
    while (game->isRunning) {
        Game_handleEvents(game);
        Game_update(game);
        Game_render(game);
    }
}

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

            for (int i = 0; i < patterns_count; i++) {
                if (event.key.keysym.sym == patterns[i].key) {
                    //Grid_clear(&game->grid); // Uncomment this line to clear the grid before placing a pattern
                    placePattern(&game->grid, &patterns[i]);
                    break;
                }
            }
        }
    }
}

void Game_update(Game *game) {
    // Update the objects ...
    Grid_update(&game->grid);
}

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

void Game_clean(Game *game) {
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    Grid_clean(&game->grid);
    SDL_Quit();
}

