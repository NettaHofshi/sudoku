
#ifndef MAINAUX_H_
#define MAINAUX_H_

/*
 * checkNumOfCellsToFill function:
 * checks if the the number the user entred is legal (in the right range)
 *
 * parameters
 * range- the range it needs to be in
 *
 */
int checkNumOfCellsToFill (int range);

/*
 * initAllBoards function:
 * initialize all the board that will be used during the game, to '0' and ' '
 *
 * parameters-
 * gameBoard
 * solvedBoard
 * tempBoard
 */
void initAllBoards(char gameBoard [][9][2],char solvedBoard [][9][2],char tempBoard[9][9][10]);


#endif /* MAINAUX_H_ */

