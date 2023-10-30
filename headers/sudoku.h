#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>;  // Include the vector library

// Function to print a 9x9 Sudoku grid
void printSudoku9x9(int arr[9][9]);

// Function to check if a number 'n' can be placed in a specific row and column of a Sudoku grid
bool canPlace9x9(int arr[9][9], int row, int col, int n);

// Function to find the coordinates of the next empty cell in the Sudoku grid
void nextEmpty(int arr[9][9], int row, int col, int& rowNext, int& colNext);

// Function to copy the contents of one 9x9 Sudoku grid to another
void copyArray(int arr[9][9], int arrCpy[9][9]);

// Function to find and return a vector of numbers (1-9) that can be legally placed in a specific row and column of a Sudoku grid
std::vector<int> findPlaceables(int arr[9][9], int row, int col);

// Function to solve a 9x9 Sudoku puzzle using a backtracking algorithm
bool solveSudoku9x9(int arr[9][9], int row, int col);

#endif
