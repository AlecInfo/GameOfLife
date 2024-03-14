//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "grid.h"

typedef struct Game {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int isRunning;
    Grid grid;
} Game;

void Game_init(Game* game, const char* title, int width, int height);
void Game_run(Game* game);
void Game_handleEvents(Game* game);
void Game_update(Game* game);
void Game_render(Game* game);
void Game_clean(Game* game);

#endif

