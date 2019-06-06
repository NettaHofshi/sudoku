#include <stdio.h>
#include "solver.h"

/*
 * prints 34 '-' and '\n' in the end
 */
void printDashes(){
	int i;
	for(i=0; i<34; i++){
			printf("-");
		}
		printf("\n");
}

/*
 * prints three blocks of the board of the game
 * the three blocks are in the same rows
 */
void printCells(char board[][9][2], int index){
	int k,j,i;
	for(k=0; k<3; k++){
		printf("|");
		for(j=0; j<9; j++){
			printf(" ");
			for(i=0; i<2; i++){
				if(board[index][j][i] == '0'){
					printf(" ");
				}
				else{
					printf("%c",board[index][j][i]);
				}
			}
			if(j%3 == 2){
				printf(" |");
			}
		}
		printf("\n");
		index++;
	}
	printDashes();
}

void printBoard(char board[][9][2]){
	printDashes();
	printCells(board, 0);
	printCells(board, 3);
	printCells(board, 6);
}


int gameOver(char board[][9][2]){
	int i,j;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			if(board[i][j][1] == '0'){
				return 0;
			}
		}
	}
	return 1;
}

void setMove (int column, int row, char value, char board[][9][2]){
	if(value!='0'){
		board[row-1][column-1][1]=value;
	}
	else{
		/*if we put '0' when delete, then this is useless*/
		board[row-1][column-1][1] = '0';
	}
	if(gameOver(board) == 1){
		printf("Puzzle solved successfully\n");
	}
}

void hint(int column, int row, char board[][9][2]){
	printf("Hint: set cell to %c\n", board[row-1][column-1][1]);
}

void restart (int *restartValue){
	*restartValue = 1;
}

void exitGame(){
	printf("Exiting...\n");
}

void validate(char gameBoard[][9][2],char solvedBoard[][9][2]){
	int i,j;
	char tempBoard [9][9][2];
	int firstEmptyRow=99,firstEmptyColumn=99;
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			tempBoard [i][j][1]= gameBoard[i][j][1];
			if(tempBoard [i][j][1]!='0'){
				tempBoard [i][j][0]='.';
			}
			else{
				tempBoard [i][j][0]=' ';
				if (firstEmptyRow==99 && firstEmptyColumn==99){
					firstEmptyRow=i;
					firstEmptyColumn=j;
				}
				}
			}
		}
	if(findSolution(tempBoard)==1){
		for (i=0; i<9; i++){
				for (j=0; j<9; j++){
					solvedBoard [i][j][1]= tempBoard[i][j][1];
				}
		}
		printf("Validation passed: board is solvable\n");
	}
	else{
		printf("Validation failed: board is unsolvable\n");
	}
}
