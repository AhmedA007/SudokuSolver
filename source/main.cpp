#include <iostream>
#include <vector>
#include "sudoku.h"  // Include the header file "sudoku.h" for function declarations
using namespace std;  // Using the standard namespace

int main(int argc, char** argv)
{
    // Define an unsolved Sudoku board as a 9x9 array
    int unsolvedBoard[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    int solvedBoard[9][9];
    copyArray(unsolvedBoard, solvedBoard);  // Copy the unsolved board to a solved board

    cout << "Unsolved Sudoku Board:" << endl;
    printSudoku9x9(unsolvedBoard);  // Print the initial unsolved Sudoku board

    if (solveSudoku9x9(solvedBoard, 0, 0))
    {
        cout << "Solved Sudoku Board:" << endl;
        printSudoku9x9(solvedBoard);  // Print the solved Sudoku board if a solution is found
    }
    
    return 0;  // Return 0 to indicate successful execution
}
