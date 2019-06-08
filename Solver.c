#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "MainAux.h"

int columnValid(int column,int row, char value, char board[][9][2]){
	int i;
	for(i=0; i<9; i++){
		if(i!=row){
				if(board[i][column][1] == value){
					return 0;
				}
		}
	}
	return 1;
}

int rowValid(int column, int row, char value, char board[][9][2]){
	int i;
	for(i=0; i<9; i++){
		if(i!=column){
			if(board[row][i][1] == value){
				return 0;
			}
		}
	}
	return 1;
}

int squareCheck(int column, int row){
	if(row<3){
		if(column<3){
			return 1;
		}
		else if(column<6){
			return 2;
		}
		return 3;
	}
	else if(row<6){
		if(column<3){
			return 4;
		}
		else if(column<6){
			return 5;
		}
		return 6;
	}
	else{
		if(column<3){
			return 7;
		}
		else if(column<6){
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
			if(i!=(row) || j!=(column)){
				if(value == board[i][j][1]){
					return 0;
				}
			}
		}
	}
	return 1;
}


int allValid(int column, int row, char value, char board[][9][2], int whichFuncCalled){
	if(board[row-1][column-1][0] == '.'){
		if(whichFuncCalled==1){ /*parser called*/
			printf("Error: cell is fixed\n");
		}
		return 0;
	}
	if(value=='0'){
		return 1;
	}
	if(columnValid(column-1,row-1, value, board)==0){
		if(whichFuncCalled==1){ /*parser called*/
			printf("Error: value is invalid\n");
		}
		return 0;
	}
	if(rowValid(column-1, row-1, value, board)==0){
		if(whichFuncCalled==1){ /*parser called*/
			printf("Error: value is invalid\n");
		}
		return 0;
	}
	if(squareValid(column-1, row-1, value, board)==0){
		if(whichFuncCalled==1){ /*parser called*/
			printf("Error: value is invalid\n");
		}
		return 0;
	}
	return 1;
}

int createOptions(char tempBoard[][9][10], int row, int col){
	int i=0, j=0, index=0;
	char boardForValid[9][9][2];
	for(i=0; i<9; i++){
			for(j=0; j<9; j++){
				boardForValid[i][j][1]='0';
			}
	}
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){

			boardForValid[i][j][1] = tempBoard[i][j][9];
		}
	}
	for(i=1;i<10;i++){
		if(allValid(col+1, row+1, i+'0', boardForValid, 0)==1){
			tempBoard[row][col][index]=i+'0';
			index++;
		}
	}
	return index;
}



int createBoard(char tempBoard[][9][10]){
	int row=0, col=0, randomIndex=0, numOfOptions=0, i=0, j=0, temp=0,k=0;
	char val;
	if(tempBoard[8][8][9]!='0' ){
		return 1;
	}
	for (;row<9; row++){
		for(col=0; col<9; col++){
			if(tempBoard[row][col][9]=='0'){
				numOfOptions= createOptions(tempBoard, row, col);
				temp = numOfOptions;

				for(j=0;j<temp;j++){
					if (numOfOptions==1){
						randomIndex=0;
					}
					else{
					randomIndex= rand()%numOfOptions;
					}
					val=tempBoard[row][col][randomIndex];
					tempBoard[row][col][9]=val;
					if(createBoard(tempBoard)==1){
						return 1;
					}
					for(i=0;i<9;i++){/*updates array*/
						if(tempBoard[row][col][i]==tempBoard[row][col][9]){
							for(k=i;k<9;k++){
								tempBoard[row][col][k]=tempBoard[row][col][k+1];
							}
							tempBoard[row][col][8]='0';
						}
					}
					numOfOptions =numOfOptions-1;

					}

				for(i=0;i<10;i++){
					tempBoard[row][col][i]='0';
				}
				return 0;
			}
		}
	}

	return 1;
}



void fillGameBoardCells(char gameBoard[][9][2],char solvedBoard[][9][2],int numOfCellToFill){
	int i=0,x=0,y=0,tag=0;
	for (i=0 ; i<numOfCellToFill; i++) {
		tag=0;
		while(tag==0){
			x= rand()%9;
			y= rand()%9;
			if (gameBoard[x][y][0]!='.'){
				gameBoard[x][y][0]='.';
				gameBoard[x][y][1]= solvedBoard[x][y][1];
				tag=1;
			}
		}
}
}

void startBoard (char tempBoard[][9][10],char gameBoard[][9][2],char solvedBoard[][9][2], int numOfCellToFill){
	int i=0,j=0;
	initAllBoards(gameBoard,solvedBoard,tempBoard);
	createBoard(tempBoard);
	for (i=0; i<9;i++){
		for (j=0; j<9;j++){
			solvedBoard[i][j][1]=tempBoard[i][j][9];

		}
	}

	fillGameBoardCells(gameBoard,solvedBoard,numOfCellToFill);
}

int findEmptyCell (char tempBoard[][9][2],int *curRow, int *curColumn,int *prevRow, int *prevColumn){
	int k,t;
	for (k=0; k<9; k++){   /*findint the first empty cell*/
			for (t=0; t<9; t++){
				if (tempBoard[k][t][0]==' '&& tempBoard[k][t][1]!='0'){
					*prevRow=k;
					*prevColumn=t;
				}
				if (tempBoard[k][t][1]=='0'){
					*curRow=k;
					*curColumn=t;
					return 0;  /*found the first empty cell*/
				}
		}
	}
	return 1; /*board is full*/
}

int findSolution(char tempBoard[][9][2] ) {
	int value = 1;
	int row = 0, col = 0;

	if (gameOver(tempBoard) == 1)
		return 1;

	for (; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (tempBoard[row][col][1] == '0' && tempBoard[row][col][0]== ' ') {
				for (value = 1; value <= 9; value++) {
					if (allValid(col+1,row+1,value+'0',tempBoard,0)==1) {
						tempBoard[row][col][1] = value+'0';
						if (findSolution(tempBoard))
							return 1;
					}
				}
				tempBoard[row][col][1] = '0';
				return 0;
			}
		}
	}
	return 1;
}

