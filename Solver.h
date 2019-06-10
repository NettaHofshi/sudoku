#ifndef SOLVER_H_
#define SOLVER_H_

/* startBoard function:
 * create a new Soduko board (gameBoard) and a new full solved boared.
 *
 * parameters-
 * tempBoard- an empty board the function will work on
 * gameBoard- the board the function will fill with fixed cells and leave empty cells for the game.
 * solvedBoard- the board that the function will fill with a solved board
 * numOfCellToFill- the number of fixed cells the user entered.
 *
 */
void startBoard(char tempBoard[][9][10],char gameBoard[][9][2],char solvedBoard[][9][2],int numOfCellToFill);

/* findSolution function:
 * uses the determenistic backtacking algorithm to determine if the given board has a valid solution
 * returns 1 if there is a valid solution, and 0 if not.
 * if there is a solution, the given board (tempBoard) id filled and solved.
 *
 * parameters-
 * tempBoard- a copy of the current game board, to check if there is a solution to its current status.
 *
 */
int findSolution(char tempBoard[][9][2]);

/*
 * allValid function:
 * checks if a certain value is valid in a specific cell.
 * it is valid if it is not already in the same row, column or square.
 * returns 0 if it is not valid for some reason, and 1 if it is valid.
 *
 * parameters-
 * column- the column to check
 * row- the row to check
 * value- the value wanted to insert to the board
 * board- the gameBoard
 * whichFuncCalled- to determine if it is needed to print an error massage(1) or not(0).
 */
int allValid(int column, int row, char value, char board[][9][2], int whichFuncCalled);





#endif /* SOLVER_H_ */

