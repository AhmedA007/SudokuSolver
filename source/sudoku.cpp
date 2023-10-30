#include "sudoku.h"  // Include the header file "sudoku.h" that contains function prototypes

#include <iostream>
#include <vector>  // Include the vector library for using vectors

using namespace std;  // Using the standard namespace

// Function to print a 9x9 Sudoku grid
void printSudoku9x9(int arr[9][9]) {
	cout << "-------------------------" << endl;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++)
			cout << arr[y][x] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;
}

// Function to check if a number 'n' can be placed in a specific row and column of a Sudoku grid
bool canPlace9x9(int arr[9][9], int row, int col, int n) {
	if (arr[row][col] != 0) return false;  // If the cell is not empty, return false
	bool status = true;
	int gridx = (col / 3) * 3;
	int gridy = (row / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (arr[row][i] == n) { status = false; break; }  // Check the row for repetition of 'n'
		if (arr[i][col] == n) { status = false; break; }  // Check the column for repetition of 'n'
		if (arr[gridy + i / 3][gridx + i % 3] == n) { status = false; break; }  // Check the 3x3 region for repetition of 'n'
	}
	return status;
}

// Function to find the coordinates of the next empty cell in the Sudoku grid
void nextEmpty(int arr[9][9], int row, int col, int& rowNext, int& colNext) {
	int indexNext = 9 * 9 + 1;
	for (int i = row * 9 + col + 1; i < 9 * 9; i++) {
		if (arr[i / 9][i % 9] == 0) {
			indexNext = i;
			break;
		}
	}
	rowNext = indexNext / 9;
	colNext = indexNext % 9;
}

// Function to copy the contents of one 9x9 Sudoku grid to another
void copyArray(int arr[9][9], int arrCpy[9][9]) {
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			arrCpy[y][x] = arr[y][x];
}

// Function to find and return a vector of numbers (1-9) that can be legally placed in a specific row and column of a Sudoku grid
std::vector<int> findPlaceables(int arr[9][9], int row, int col) {
	vector<int> placebles = {};
	for (int n = 1; n <= 9; n++)
		if (canPlace9x9(arr, row, col, n)) placebles.push_back(n);  // Check if 'n' can be legally placed and add it to the vector
	return placebles;
}

// Function to solve a 9x9 Sudoku puzzle using a backtracking algorithm
bool solveSudoku9x9(int arr[9][9], int row, int col) {
	if (row > 8) return true;  // If we've reached the end of the grid, the Sudoku is solved
	if (arr[row][col] != 0) {
		int rowNext, colNext;
		nextEmpty(arr, row, col, rowNext, colNext);
		return solveSudoku9x9(arr, rowNext, colNext);  // Move to the next empty cell
	}

	std::vector<int> placebles = findPlaceables(arr, row, col);

	if (placebles.size() == 0) {
		return false;  // If there are no legal numbers to place, the puzzle has no solution
	};

	bool status = false;
	for (int i = 0; i < placebles.size(); i++) {
		int n = placebles[i];
		int arrCpy[9][9];
		copyArray(arr, arrCpy);
		arrCpy[row][col] = n;
		int rowNext = row;
		int colNext = col;
		nextEmpty(arrCpy, row, col, rowNext, colNext);
		if (solveSudoku9x9(arrCpy, rowNext, colNext)) {
			copyArray(arrCpy, arr);
			status = true;
			break;
		}
	}
	return status;
}
