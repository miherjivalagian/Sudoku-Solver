#include <iostream>
#include <string>
#include "Sudoku.h"

using namespace std;


void Sudoku::solveSodukoPuzzle(int mainGridArray[ROWS][COLUMNS]) {

	int counter = 0;
	bool puzzleComplete = false; // Initial Puzzle is not complete

	while (!puzzleComplete) { // While there are still blank spaces, continue
		for (int rowCounter = 0; rowCounter < ROWS; rowCounter++) {
			for (int columnCounter = 0; columnCounter < COLUMNS; columnCounter++) {
				if (mainGridArray[rowCounter][columnCounter] == _) {
					puzzleComplete = false; // If you encounter empty spaces puzzle is still not complete continue
					for (int x = 1; x < 9 + 1; x++) {
						crossHatchMarker(mainGridArray, x);
						counter++;
						cout << "Solving...";
					}
				}
				else if (rowCounter + 1 == ROWS && columnCounter + 1 == COLUMNS && mainGridArray[rowCounter][columnCounter] != _) {
					puzzleComplete = true; // Puzzle has been solved
				}
			}
		}
	}
}

void Sudoku::crossHatchMarker(int mainGridArray[ROWS][COLUMNS], int numPar) {

	int tempGridArray[ROWS][COLUMNS] =
	{
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _},
		{_, _, _, _, _, _, _, _, _}
	};

	// Search for spots already taken by other numbers and mark them
	for (int rowCounter = 0; rowCounter < ROWS; rowCounter++) {
		for (int columnCounter = 0; columnCounter < COLUMNS; columnCounter++) {
			if (mainGridArray[rowCounter][columnCounter] != _) {
				tempGridArray[rowCounter][columnCounter] = 1;
			}
		}
	}

	// Mark Parallel columns and Perpendicular Rows to the number we are searching for when an instance is found
	for (int rowCounter = 0; rowCounter < ROWS; rowCounter++) {
		for (int columnCounter = 0; columnCounter < COLUMNS; columnCounter++) {
			if (mainGridArray[rowCounter][columnCounter] == numPar) {
				for (int markerPosition = 0; markerPosition < ROWS; markerPosition++) {
					tempGridArray[markerPosition][columnCounter] = 1;
				}
				for (int markerPosition = 0; markerPosition < COLUMNS; markerPosition++) {
					tempGridArray[rowCounter][markerPosition] = 1;
				}
			}
		}
	}

	cout << endl;

	// Search for empty spaces and place number in position
	for (int rowCounter = 0; rowCounter < ROWS; rowCounter++) {
		for (int columnCounter = 0; columnCounter < COLUMNS; columnCounter++) {
			if (tempGridArray[rowCounter][columnCounter] == _) {
				searchingInnerGrid(tempGridArray, mainGridArray, numPar, rowCounter, columnCounter);
			}
		}
	}
}

void Sudoku::searchingInnerGrid(int tempGridArray[ROWS][COLUMNS], int mainGridArray[ROWS][COLUMNS], int numPar, int rowPosition, int columnPosition)
{
	// Check each 3x3 grid from left to right and top to bottom for copys

	if (0 <= rowPosition && rowPosition <= 2 && 0 <= columnPosition && columnPosition <= 2) { // Top Left Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 0, 2, 0, 2, rowPosition, columnPosition);
	}
	else if (0 <= rowPosition && rowPosition <= 2 && 3 <= columnPosition && columnPosition <= 5) { // Top Middle Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 0, 2, 3, 5, rowPosition, columnPosition);
	}
	else if (0 <= rowPosition && rowPosition <= 2 && 6 <= columnPosition && columnPosition <= 8) { // Top Right Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 0, 2, 6, 8, rowPosition, columnPosition);
	}
	else if (3 <= rowPosition && rowPosition <= 5 && 0 <= columnPosition && columnPosition <= 2) { // Middle Left Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 3, 5, 0, 2, rowPosition, columnPosition);
	}
	else if (3 <= rowPosition && rowPosition <= 5 && 3 <= columnPosition && columnPosition <= 5) { // Middle Middle Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 3, 5, 3, 5, rowPosition, columnPosition);
	}
	else if (3 <= rowPosition && rowPosition <= 5 && 6 <= columnPosition && columnPosition <= 8) { // Middle Right Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 3, 5, 6, 8, rowPosition, columnPosition);
	}
	else if (6 <= rowPosition && rowPosition <= 8 && 0 <= columnPosition && columnPosition <= 2) { // Bottom Left Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 6, 8, 0, 2, rowPosition, columnPosition);
	}
	else if (6 <= rowPosition && rowPosition <= 8 && 3 <= columnPosition && columnPosition <= 5) { // Bottom Middle Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 6, 8, 3, 5, rowPosition, columnPosition);
	}
	else if (6 <= rowPosition && rowPosition <= 8 && 6 <= columnPosition && columnPosition <= 8) { // Bottom Right Subgrid
		searchingForCopy(tempGridArray, mainGridArray, numPar, 6, 8, 6, 8, rowPosition, columnPosition);
	}
}

void Sudoku::searchingForCopy(int tempGridArray[ROWS][COLUMNS], int mainGridArray[ROWS][COLUMNS], int numPar, int rowLowerLimit, int rowUpperLimit, int columnLowerLimit, int columnUpperLimit, int rowPosition, int columnPosition) {

	//Search main rows and columns to make sure there is no copy
	int emptySpace = 0;
	bool copy = false;
	for (int i = rowLowerLimit; i < (rowUpperLimit + 1); i++) {
		for (int j = columnLowerLimit; j < (columnUpperLimit + 1); j++) {
			if (tempGridArray[i][j] == _) {
				emptySpace += 1;

			}

			if (mainGridArray[i][j] == numPar) {
				copy = true;
			}
		}
	}

	if (!copy && tempGridArray[rowPosition][columnPosition] != 1 && emptySpace == 1) { // If there is not a copy, good to go for our numPar to be placed there
		safeToAssignNumber(tempGridArray, mainGridArray, numPar, rowPosition, columnPosition);
	}


}

void Sudoku::safeToAssignNumber(int tempGridArray[ROWS][COLUMNS], int mainGridArray[ROWS][COLUMNS], int numPar, int rowPosition, int columnPosition) {
	mainGridArray[rowPosition][columnPosition] = numPar;
}

void Sudoku::displaySudoku(int mainGridArray[ROWS][COLUMNS]) {

	for (int rowCounter = 0; rowCounter < ROWS; rowCounter++)
	{
		for (int columnCounter = 0; columnCounter < COLUMNS; columnCounter++)
		{
			cout << " " << mainGridArray[rowCounter][columnCounter];
		}
		cout << endl;
	}
}