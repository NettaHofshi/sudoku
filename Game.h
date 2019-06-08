#ifndef GAME_H_
#define GAME_H_

/*
 * updates the value in the required cell in the board if it is valid
 * if the game is over, updates the user
 */
void setMove (int column, int row, int value, char board[][9][2]);

/*
 * prints the board of the game
 */
void printBoard(char board[][9][2]);

/*
 * gives the user the desired hint
 * the hint is the value located in the required cell in the solved board
 */
char hint(int column, int row, char board[][9][2]);

/*
 * checks if the board of the game is full
 * returns 1 if the board is full, and 0 else
 */
int gameOver(char board[][9][2]);

/*
 * terminates the game
 */
void exitGame();

/*
 * restarts the game
 */
void restart(int* restar);

/*
 * checks if the board of the game is solvable
 * prints to the user if the game is solvable or not
 */
void validate(char gameBoard[][9][2],char solvedBoard[][9][2]);

#endif /* GAME_H_ */

