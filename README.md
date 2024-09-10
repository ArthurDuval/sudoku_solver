# sudoku_solver

## Overview

This is a C-based Sudoku solver that reads, solves, and displays Sudoku puzzles. The project features:

- **Grid Input**: Accepts Sudoku grids from text files or command-line input (in progress).
- **Puzzle Solving**: Uses a backtracking algorithm to solve Sudoku puzzles.
- **Grid Display**: Visually displays Sudoku grids with color-coded output to indicate progress and solutions.

## Features

- Interactive command-line interface for inputting and displaying Sudoku grids.
- Options for different solving speeds and display delays.
- Clear and organized code structure with modular functions.

## Installation

To compile and run the Sudoku solver, follow these steps:

1. **Clone the Repository**

   ```sh
   git clone https://github.com/yourusername/sudoku_solver.git
   cd sudoku_solver
2. **Compile the Code**

   ```sh
   cc -o sudoku_solver header.h *.c

## Usage

Run the compiled program with the following command:

   ```sh
   ./sudoku_solver [option]
