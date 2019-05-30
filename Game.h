#ifndef GAME_H_
#define GAME_H_

void SetMove (int column, int row, int value, char board[][9][2]);
void printBoard(char board[][9][2]);
char hint(int column, int row, char board[][9][2]);
int gameOver(char board[][9][2]);
int squareValid(int column, int row, int value, char board[][9][2]);
int rowValid(int row, int value, char board[][9][2]);
int columnValid(int column, int value, char board[][9][2]);
void printCells(char board[][9][2], int index);
void printDashes();


#endif /* GAME_H_ */

