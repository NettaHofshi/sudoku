#ifndef GAME_H_
#define GAME_H_

void setMove (int column, int row, int value, char board[][9][2]);
void printBoard(char board[][9][2]);
char hint(int column, int row, char board[][9][2]);
int gameOver(char board[][9][2]);
void printCells(char board[][9][2], int index);
void printDashes();
void exitGame();
void restart(int* restar);
void validate(char gameBoard[][9][2],char solvedBoard[][9][2]);

#endif /* GAME_H_ */

