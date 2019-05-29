#ifndef GAME_H_
#define GAME_H_

void SetMove (int column, int row, int value, char board[][][]);
void printBoard(char board[][][]);
char hint(int column, int row, char board[][][]);
int gameOver(char board[][][]);
int squareValid(int column, int row, int value, char board[][][]);
int rowValid(int row, int value, char board[][][]);
int columnValid(int column, int value, char board[][][]);
void printCells(char board[][][], int index);
void printDashes();


#endif /* GAME_H_ */

