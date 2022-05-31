/** --------------------------- 
* @file		knightsTour.cpp
* @author	Masaki Nishi
* @version	1.0
*
* CS162-01 - Assignment 5
*	The Knight's Tour assignment
*
* --------------------------- */

#include <iostream>
#include <iomanip>

const int BOARD_SIZE = 5;

struct Board {
	int array[BOARD_SIZE][BOARD_SIZE] = { {0} };
};

int solveKnightsTour(Board board, int row, int col, int currentMoveNum = 1);

void printBoard(Board board);

int main() {
	Board board;
	std::cout << "Welcome to the Knight's Tour solver!" << std::endl << std::endl;
	std::cout << "Board size :" << BOARD_SIZE << std::endl;
	std::cout << "Starting position(row, col) : 2, 2" << std::endl << std::endl;
	std::cout << "Thinking...." << std::endl << std::endl;
	std::cout << "Total Solutions: " << solveKnightsTour(board, 2, 2) << std::endl;
}

/** ================================================================
 * Recursively solves the knights tour using brute force
 * Prints any solutions it finds.
 *
 * @param board - the board we’re working with (contains all moves-to-date)
 * @param row   - row we’re going to attempt to place the knight on this move.
 * @param col   - column we’re going to attempt to place the knight on this move.
 * @param currentMoveNumber - the move# we’re making (1=first move)
 *
 * @return The number of solutions the given board and move leads to
 * =================================================================
 */
int solveKnightsTour(Board board, int row, int col, int currentMoveNum) {
	const int startCol = col;
	const int startRow = row;
	bool isCol = false;
	int solutions = 0;

	// Validate row and col (on board and spot not occupied?)
	if (row >= BOARD_SIZE ||
		row < 0 ||
		col >= BOARD_SIZE ||
		col < 0) {
		return 0;
	}

	// Place knight on board
	board.array[row][col] = currentMoveNum;

	// Determine if board is full
	if (currentMoveNum != BOARD_SIZE * BOARD_SIZE) {
		// Make 8 recursive calls
		for (int rotation = 0; rotation < 4; rotation++) {
			switch (rotation) {
			case 0:
				col = startCol + 2;
				isCol = true;
				break;
			case 1:
				row = startRow + 2;
				isCol = false;
				break;
			case 2:
				col = startCol - 2;
				isCol = true;
				break;
			case 3:
				row = startRow - 2;
				isCol = false;
				break;
			}

			for (int direction = 0; direction < 2; direction++) {
				if (isCol) {
					switch (direction) {
					case 0:
						row = startRow - 1;
						break;
					case 1:
						row = startRow + 1;
						break;
					}
				}
				else {
					switch (direction) {
					case 0:
						col = startCol - 1;
						break;
					case 1:
						col = startCol + 1;
						break;
					}
				}
				// if next possible move
				if (
					row < BOARD_SIZE &&
					row >= 0 &&
					col < BOARD_SIZE &&
					col >= 0 &&
					board.array[row][col] == 0
					) {
					solutions = solutions + solveKnightsTour(board, row, col, currentMoveNum + 1);
				}
			}
		}
	}
	else {
		// If full, print solution and return 1 (valid solution!)
		printBoard(board);
		solutions = 1;
	}

	return solutions;
}

/** ================================================================
*	Prints a Board object.
*
*	@param board - the board with the move numbers
* ================================================================
*/
void printBoard(Board board) {
	for (int col = 0; col < BOARD_SIZE; col++) {
		for (int row = 0; row < BOARD_SIZE; row++) {
			std::cout << std::setfill('0') << std::setw(2) << board.array[row][col] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
