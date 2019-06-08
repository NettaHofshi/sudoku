#ifndef SOLVER_H_
#define SOLVER_H_

void startBoard(char tempBoard[][9][10],char gameBoard[][9][2],char solvedBoard[][9][2],int numOfCellToFill);
int findSolution(char tempBoard[][9][2]);
int allValid(int column, int row, char value, char board[][9][2], int whichFuncCalled);
int createOptions(char tempBoard[][9][10], int row, int col);



#endif /* SOLVER_H_ */

