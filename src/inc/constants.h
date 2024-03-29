/***********************************************************************
 * Author: Alec Piette
 * Created on: 12.03.2024
 * Last updated on: 29.03.2024
 *
 * Project: Game of Life in C using SDL2
 * File: constants.h
 * Description: Contains all the global constants used throughout the
 * Game of Life project. This includes definitions for window dimensions,
 * cell sizes, and color codes, ensuring a centralized management of these constants.
 *
 * License: MIT License
 * Repository: https://github.com/AlecInfo/GameOfLife
 *
 * This file is a part of the Game of Life project. It serves as a repository for
 * constants, facilitating easy modifications to the game's visual and operational parameters.
 * All rights reserved.
 ***********************************************************************/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define TITLE               "Game of Life"  // The title of the window
#define SCREEN_WIDTH        800             // The width of the window
#define SCREEN_HEIGHT       600             // The height of the window

#define CELL_SIZE           10              // Pixels size of a cell

#define ALIVE_COLOR         0xFFFFFFFF      // The color of an alive cell (white)
#define DEAD_COLOR          0x000000FF      // The color of a dead cell (black)
#define BACKGROUND_COLOR    0x000000FF      // The color of the background (black)

#define PREVIEW_COLOR       0x00FF00FF      // The color of the preview cell (green)

#endif