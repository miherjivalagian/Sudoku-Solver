#include <iostream>
#include <string>
#include "Sudoku.h"

using namespace std;


int main()
{
	Sudoku* puzzleA = new Sudoku;
	int gridArray[ROWS][COLUMNS] =
	{
		{5, 3, 4, _, 7, _, 9, 1, 2},
		{6, _, _, 1, 9, 5, _, _, 8},
		{_, 9, 8, _, _, _, _, 6, _},
		{8, _, _, _, 6, _, _, _, 3},
		{4, _, _, 8, _, 3, _, _, 1},
		{7, _, _, _, 2, _, _, _, 6},
		{_, 6, _, _, _, _, 2, 8, 4},
		{2, _, 7, 4, 1, 9, _, _, 5},
		{3, 4, 5, _, 8, _, _, 7, 9}
	};

	cout << "Sudoku Solver through Cross Hatching technique.." << endl;
	cout << "Below is the puzzle that needs to be solved: " << endl << endl;
	puzzleA->displaySudoku(gridArray);

	cout << endl << endl;

	cout << "Solving puzzle through cross-hatching method, please wait..." << endl << endl;
	puzzleA->solveSodukoPuzzle(gridArray);

	cout << endl;
	cout << endl;
	cout << "Puzzle Solved!" << endl << endl;
	puzzleA->displaySudoku(gridArray);

	cout << endl << endl;

	system("pause");
	return 0;
}