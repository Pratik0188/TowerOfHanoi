# Tower of Hanoi

A simple implementation of the Tower of Hanoi game in C++.

## Introduction

The Tower of Hanoi is a classic mathematical puzzle where the goal is to move a stack of disks from one rod to another, following specific rules:

1. Only one disk can be moved at a time.
2. A disk can only be placed on top of a larger disk or an empty rod.
3. All disks must be moved from the source rod to the destination rod.

This program solves the puzzle programmatically and provides a simulation of the process.

## Features

- Solves the Tower of Hanoi puzzle for any number of disks.
- Displays each move in the solution process.
- Includes modularized code for stack management and game logic.

## File Structure

- **towers.cpp**: Contains the main logic for solving the Tower of Hanoi puzzle.
- **towerofhanoi.cpp**: Entry point for the program.
- **towers.h**: Header file for the Tower of Hanoi logic.
- **mystack.h**: Header file for stack implementation used in the game.
- **CMakeLists.txt**: Build configuration for the project.
- **Instructions.txt**: Additional instructions on running the program.
- **results.txt**: Sample results generated by the program.

## Requirements

- **C++ Compiler** (e.g., GCC, Clang, or MSVC)
- **CMake** (for building the project)

## How to Compile and Run

### Using CMake

1. Clone the repository:

    ```bash
    git clone https://github.com/Pratik0188/TowerOfHanoi.git
    cd TowerOfHanoi
    ```

2. Create a build directory and navigate into it:

    ```bash
    mkdir build && cd build
    ```

3. Generate the build files:

    ```bash
    cmake ..
    ```

4. Compile the program:

    ```bash
    make
    ```

5. Run the program:

    ```bash
    ./TowerOfHanoi
    ```

## How to Play

1. Enter the number of disks when prompted.
2. The program will display the sequence of moves to solve the puzzle.
3. Observe the output to see how the puzzle is solved step by step.

## Sample Output

```text
Enter the number of disks: 3
Move disk 1 from Rod A to Rod C
Move disk 2 from Rod A to Rod B
Move disk 1 from Rod C to Rod B
Move disk 3 from Rod A to Rod C
Move disk 1 from Rod B to Rod A
Move disk 2 from Rod B to Rod C
Move disk 1 from Rod A to Rod C
