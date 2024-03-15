/***********************************************************************
 * Author: Alec Piette
 * Created on: 14.03.2024
 * Last updated on: 15.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: main.c
 * Description: Serves as the entry point for the Game of Life application.
 * This file handles the initial setup of the game environment, including
 * SDL initialization, and starts the game loop.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is part of the Game of Life project. It kicks off the simulation by setting up
 * the game window, rendering context, and entering the main game loop, demonstrating
 * Conway's Game of Life in action. All rights reserved.
 ***********************************************************************/

#include "../inc/game.h" // Include the game header file
#include "../inc/constants.h" // Include the constants header file

/**
 * The main function of the Game of Life program.
 * It initializes a new game, runs it and then cleans up after the game has ended.
 *
 * @return int Returns 0 upon successful execution of the program.
 */
int main(/* int argc, char* argv[] */) {
    Game game; // Declare a new Game object

    Game_init(&game, TITLE, SCREEN_WIDTH, SCREEN_HEIGHT); // Initialize the game with the given title and screen dimensions
    Game_run(&game); // Run the game
    Game_clean(&game); // Clean up after the game has ended

    return 0; // Return 0 upon successful execution
}