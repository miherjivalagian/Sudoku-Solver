#ifndef _SUDOKU
#define _SUDOKU

#include<iostream>
#include<string>


using namespace std;

enum UNASSIGNEDPOSITION { _ = 0 };

const int ROWS = 9; //Overall Sudoku grid is a 9x9 grid where rows and columns have same value
const int COLUMNS = 9;

class Sudoku {
private:
	int row, column, numPar, rowLowerLimit, rowUpperLimit, columnLowerLimit, columnUpperLimit, rowPosition, columnPosition;
	int gridArray[ROWS][COLUMNS];

public:

	void crossHatchMarker(int mainGridArray[ROWS][COLUMNS], int numPar);
	void searchingInnerGrid(int tempGridArray[ROWS][COLUMNS], int mainGridArray[ROWS][COLUMNS], int numPar, int rowPosition, int columnPosition);
	void safeToAssignNumber(int tempGridArray[ROWS][COLUMNS], int mainGridArray[ROWS][COLUMNS], int numPar, int rowPosition, int columnPosition);
	void searchingForCopy(int tempGridArray[ROWS][COLUMNS], int mainGridArray[ROWS][COLUMNS], int numPar, int rowLowerLimit, int rowUpperLimit, int columnLowerLimit, int columnUpperLimit, int rowPosition, int columnPosition);
	void solveSodukoPuzzle(int mainGridArray[ROWS][COLUMNS]);
	void displaySudoku(int mainGridArray[ROWS][COLUMNS]);

};
#endif