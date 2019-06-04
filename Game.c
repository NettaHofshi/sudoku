#include <stdio.h>

void printDashes(){
	int i;
	for(i=0; i<34; i++){
			printf("-");
		}
		printf("\n");
}

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

int columnValid(int column, char value, char board[][9][2]){
	int i;
	for(i=0; i<9; i++){
		if(board[i][column][1] == value){
			return 0;
		}
	}
	return 1;
}

int rowValid(int row, char value, char board[][9][2]){
	int i;
	for(i=0; i<9; i++){
		if(board[row][i][1] == value){
			return 0;
		}
	}
	return 1;
}

int squareCheck(int column, int row){
	if(row<4){
		if(column<4){
			return 1;
		}
		else if(column<7){
			return 2;
		}
		return 3;
	}
	else if(row<7){
		if(column<4){
			return 4;
		}
		else if(column<7){
			return 5;
		}
		return 6;
	}
	else{
		if(column<4){
			return 7;
		}
		else if(column<7){
			return 8;
		}
		return 9;
	}
}

int squareValid(int column, int row, char value, char board[][9][2]){
	int square = squareCheck(column,row);
	int i,j,row1,row2,column1,column2;
	if(square==1){
		row1=0;
		column1=0;
	}
	else if(square==2){
		row1=0;
		column1=3;
	}
	else if(square==3){
		row1=0;
		column1=6;
	}
	else if(square==4){
		row1=3;
		column1=0;
	}
	else if(square==5){
		row1=3;
		column1=3;
	}
	else if(square==6){
		row1=3;
		column1=6;
	}
	else if(square==7){
		row1=6;
		column1=0;
	}
	else if(square==8){
		row1=6;
		column1=3;
	}
	else{
		row1=6;
		column1=6;
	}
	row2=row1+3;
	column2= column1+3;
	for(i=row1; i<row2; i++){
		for(j=column1; j<column2; j++){
			if(i!=(row-1) && j!=(column-1)){
				if(value == board[i][j][1]){
					return 0;
				}
			}
		}
	}
	return 1;
}

int gameOver(char board[][9][2]){
	int i,j;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			if(board[i][j][1] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

void setMove (int column, int row, char value, char board[][9][2]){
	if(board[row-1][column-1][0] == '.'){
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
	else if(value!='0'){
		board[row-1][column-1][1]=value;
	}
	else{
		board[row-1][column-1][1] = ' ';
	}
	if(gameOver(board) == 1){
		printf("Puzzle solved successfully\n");
	}
}

void hint(int column, int row, char board[][9][2]){
	printf("%c\n", board[row-1][column-1][1]);
}

void restart (int *restartValue){
	*restartValue = 1;
}

void exitGame(){
	printf("Exiting...\n");
}


