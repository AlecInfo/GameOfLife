//
// Created by ALEC PTT on 12.03.2024.
// Last update on 12.03.2024.
//

// src/main/main.c
#include "../inc/game.h"
#include "../inc/constants.h"

int main(int argc, char* argv[]) {
    Game game;

    Game_init(&game, TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    Game_run(&game);
    Game_clean(&game);

    return 0;
}

