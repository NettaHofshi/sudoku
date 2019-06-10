#ifndef GAME_H_
#define GAME_H_

/* setMove function:
 * updates the value in the required cell in the board if it is valid
 * if the game is over, updates the user
 *
 * parameters-
 * column- the column of the cell to insert in
 * row-the column of the cell to insert in
 * value-the value to insert
 * board- the gameboard that the move will be played at
 */
void setMove (int column, int row, int value, char board[][9][2]);

/* printBoard function:
 * prints the board of the game
 *
 * parameters-
 * board- the board we want to print
 */
void printBoard(char board[][9][2]);

/* hint function:
 * gives the user the desired hint
 * the hint is the value located in the required cell in the solved board
 *
 * parameters-
 * column- the the column of the cell to recieve
 * row- the the row of the cell to recieve
 * board- the solved board to take from
 */
char hint(int column, int row, char board[][9][2]);

/* gameOver function:
 * checks if the board of the game is full
 * returns 1 if the board is full, and 0 else
 *
 * parameters-
 * board- the game board
 */
int gameOver(char board[][9][2]);

/* exitGame function:
 * terminates the game
 */
void exitGame();

/* restart function:
 * restarts the game
 *
 * parameters-
 * restartValue- pointer to a int that tells you if to reatart the game or not
 */
void restart(int* restartValue);

/* validate function:
 * checks if the board of the game is solvable
 * prints to the user if the game is solvable or not
 *
 * parameters-
 * gameBoard- the board we need to check if is valid
 * solvedBoard- the board we need to update to the current solution
 */
void validate(char gameBoard[][9][2],char solvedBoard[][9][2]);

#endif /* GAME_H_ */

