#ifndef SOLVER_H_
#define SOLVER_H_

void createBoard(char gameBoard[][9][2],char solvedBoard[][9][2],int numOfCellToFill);
int findSolution(char tempBoard[][9][2],int rowFirstBlank, int columnFirstBlank);

#endif /* SOLVER_H_ */

