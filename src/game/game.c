//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/game/game.c
#include "../inc/game.h"
#include "../inc/constants.h"

void Game_init(Game* game, const char* title, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, 0);
    game->isRunning = 1;

    // Initialize the objects ...
    Grid_init(&game->grid, width / CELL_SIZE, height / CELL_SIZE); // 10x10 pixels per cell
}

void Game_run(Game* game) {
    while (game->isRunning) {
        Game_handleEvents(game);
        Game_update(game);
        Game_render(game);
    }
}

void Game_handleEvents(Game* game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                game->isRunning = 0;
                break;
        }
    }
}

void Game_update(Game* game) {
    // Update the objects ...
    Grid_update(&game->grid);
}

void Game_render(Game* game) {
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

void Game_clean(Game* game) {
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    Grid_clean(&game->grid);
    SDL_Quit();
}

