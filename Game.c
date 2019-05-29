#include <stdio.h>

void printDashes(){
	for(int i=0; i<34; i++){
			printf("-");
		}
		printf("\n");
}

void printCells(char board[][][], int index){
	printf("|");
	for(int k=0; k<3; k++){
		for(int j=0; j<9; j++){
			printf(" ");
			for(int i=0; i<2; i++){
				if(board[index][j][i] == null){ /*need to fix*/
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

void printBoard(char board[][][]){
	printDashes();
	printCells(board, 0);
	printCells(board, 3);
	printCells(board, 6);
}

int columnValid(int column, int value, char board[][][]){
	for(int i=0; i<9; i++){
		if(board[i][column][1] == value){
			return 0;
		}
	}
	return 1;
}

int rowValid(int row, int value, char board[][][]){
	for(int i=0; i<9; i++){
		if(board[row][i][1] == value){
			return 0;
		}
	}
	return 1;
}

int squareValid(int column, int row, int value, char board[][][]){
	/*need to implement*/
	return 1;
}

int gameOver(char board[][][]){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(board[i][j][1] == null){
				return 0;
			}
		}
	}
	return 1;
}

void SetMove (int column, int row, int value, char board[][][]){
	if(board[row-1][column-1][0] == "."){
		printf("Error: cell is fixed\n");
	}
	else if(columnValid(column-1, value, board)==0){
		printf("Error: value is invalid\n");
	}
	/* call set again? */
	else if(rowValid(row-1, value, board)==0){
		printf("Error: value is invalid\n");
	}
	else if(squareValid(column-1, row-1, value, board)==0){
		printf("Error: value is invalid\n");
	}
	else if(value!=0){
		board[row-1][column-1][1]=value;
	}
	else{
		board[row-1][column-1][1] = null;
	}
	if(gameOver(board) == 1){
		printf("Puzzle solved successfully\n");
	}
}

char hint(int column, int row, char board[][][]){
	return board[row-1][column-1][1];
}


