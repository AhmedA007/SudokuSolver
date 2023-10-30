<br/>
<p align="center">
  <a href="https://github.com/AhmedA007/SudokuSolver">
    <img src="source\Sudoku_Puzzle.png"" alt="Logo" width="120" height="120">
  </a>

  <h3 align="center">Sudoku Solver</h3>

  <p align="center">
  This is a simple Sudoku solver implemented in C++. It uses a backtracking algorithm to solve a 9x9 Sudoku puzzle. You can provide your Sudoku puzzle as input, and the program will attempt to solve it.
    <br/>
    <br/>
  </p>
</p>

## Table of Contents


- [Table of Contents](#table-of-contents)
- [Sudoku Puzzle](#sudoku-puzzle)
- [Backtracking Algorithm](#backtracking-algorithm)
- [File Structure](#file-structure)
- [Usage](#usage)
- [Authors](#authors)


## Sudoku Puzzle

Sudoku is a popular number puzzle played on a 9x9 grid, divided into nine 3x3 subgrids or "regions." The goal of Sudoku is to fill the grid with digits from 1 to 9, with the following rules:

1. Each row must contain all the numbers from 1 to 9 with no repetition.
2. Each column must contain all the numbers from 1 to 9 with no repetition.
3. Each 3x3 subgrid or "region" must contain all the numbers from 1 to 9 with no repetition.

The puzzle starts with some cells pre-filled with numbers, and the challenge is to fill in the remaining cells so that the entire grid satisfies the above rules.

## Backtracking Algorithm

This Sudoku solver employs a backtracking algorithm to find a valid solution to the puzzle. Here's how it works:

1. It starts by looking for an empty cell (a cell with the value 0) from left to right, top to bottom.
2. When an empty cell is found, it checks which numbers (1-9) can be legally placed in that cell without violating the Sudoku rules.
3. If there is a number that can be legally placed, it does so and proceeds to the next empty cell.
4. If there are no legal numbers to place in the current cell, it backtracks to the previous cell and tries the next available number.
5. It repeats this process, backtracking as necessary, until it successfully fills in all the cells, solving the Sudoku puzzle.

## File Structure

The repository is organized as follows for better readability and maintainability:

**main.cpp**: The main program that showcases the Sudoku solver.

**sudoku.h**: Header file containing function prototypes for the Sudoku solver.

**sudoku.cpp**: Implementation of the Sudoku solver functions.


## Usage

1. Clone the repository
2. Compile and run the program using a C++ compiler.
3. The program will first output the unsolved Sudoku board. You can change this to your own Sudoku puzzle.
4. The program will output the solved puzzle using the algorithm mentioned

## Authors

* **Ahmed Amir** - *Comp Sci Student* - [Ahmed Amir](https://github.com/AhmedA007/) 



