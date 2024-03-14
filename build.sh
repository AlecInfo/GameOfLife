#!/bin/bash

# ----------------------------
#
#  Compilation of the GameOfLife project
#
#      File:    build.sh
#   Project:    GameOfLife
#    Author:    Alec Piette
#   Created:    14/03/2024
#
# ----------------------------


# Directory where source files are located
SRC_DIR="src"
# Directory where object files will be placed
OBJ_DIR="obj"
# Name of the final executable
EXECUTABLE="game_of_life"
# Compiler command
CC=gcc
# Compiler flags
CFLAGS="-Wall -Wextra -pedantic -std=c99 -I$SRC_DIR   -I/usr/include/SDL2"
# SDL2 libraries and the math library
LIBS="-lm -lSDL2 -lSDL2main -lSDL2_ttf"

# Test flag
RUN_TESTS=0

# Check if the first argument is to run tests
if [ "$1" == "test" ]; then
    RUN_TESTS=1
    EXECUTABLE="game_test"
    CFLAGS="$CFLAGS -DUNIT_TESTS" # Define UNIT_TESTS for conditional compilation
fi

# Create the object directory if it doesn't exist
mkdir -p $OBJ_DIR

# Compile each source file into an object file
for file in $SRC_DIR/**/*.c; do
    obj_file="$OBJ_DIR/$(basename "${file%.c}.o")"
    $CC $CFLAGS -c $file -o $obj_file
    if [ $? -ne 0 ]; then
        echo "Compilation failed: $file"
        exit 1
    fi
done

# Link all object files into the executable
$CC $CFLAGS $OBJ_DIR/*.o -o $EXECUTABLE $LIBS
if [ $? -ne 0 ]; then
    echo "Linking failed"
    exit 1
fi

echo "Compilation successful - Executable: ./$EXECUTABLE"

# Execute tests if RUN_TESTS is set to 1
if [ $RUN_TESTS -eq 1 ]; then
    ./$EXECUTABLE
    if [ $? -ne 0 ]; then
        echo "Tests failed"
        exit 1
    else
        echo "All tests passed successfully"
    fi
fi

