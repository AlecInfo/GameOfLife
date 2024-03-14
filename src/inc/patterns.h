//
// Created by ALEC PTT on 14.03.2024.
// Last update on 14.03.2024.
//

// src/inc/patterns.h
#ifndef PATTERNS_H
#define PATTERNS_H

#include <SDL2/SDL.h>

typedef struct {
    const char* name;
    const int key;
    const int (*coords)[2];
    const int n_coords;
} Pattern;

extern Pattern patterns[];
extern const int patterns_count;

#endif
