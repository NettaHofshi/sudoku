#include <stdio.h>
#include <string.h>

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


int allValid(int column, int row, char value, char board[][9][2], int whichFuncCalled){
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
	if(board[row-1][column-1][0] == '.'){
		if(whichFuncCalled==1){ /*parser called*/
			printf("Error: cell is fixed\n");
		}
		return 0;
	}
	return 1;
}

void createBoard(char gameBoard[][9][2],char solvedBoard[][9][2],int numOfCellToFill){

}
void emptyCells(char gameBoard[][9][2],char solvedBoard[][9][2],int numOfCellToFill){
/*for i=0 until i=81-numOfCellsToFill do
 * rand X , rand Y
 * if cell(X,Y) not empty- empty him. and replace the fixed sign "." with " "; (in both boards)
 * if already empty, rand again.
 *
 */
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

int findSolution(char tempBoard[][9][2],int rowFirstBlank, int columnFirstBlank, int q){
	int curRow,curColumn;
	int prevRow, prevColumn;
	int i;
	int lastPrevCellValue;
	if (q==1){
		printBoard(tempBoard);
	}

	if (findEmptyCell(tempBoard,&curRow, &curColumn, &prevRow, &prevColumn)==1){ /*if ==1 no empty cells- success!*/
			return 1;
		}
	for (i=1; i<10; i++){   /*try to put value in empty call*/
		if(allValid(curColumn+1,curRow+1,i+'0', tempBoard, 0)==1){
			tempBoard[curRow][curColumn][1]=i+'0';
			findSolution(tempBoard,rowFirstBlank,columnFirstBlank, q++);
		}
	}

	if (rowFirstBlank==prevRow && columnFirstBlank==prevColumn && tempBoard[prevRow][prevColumn][1]=='9'){ /*no solution*/
		return 0;
		}
	lastPrevCellValue= tempBoard[prevRow][prevColumn][1]-47;
	for (; lastPrevCellValue<10; lastPrevCellValue++){   /*try to put a new value in the previous cell*/
		if(allValid(prevColumn+1,prevRow+1,lastPrevCellValue+'0', tempBoard, 0)==1){
			tempBoard[curRow][curColumn][1]=lastPrevCellValue+'0';
			findSolution(tempBoard,rowFirstBlank,columnFirstBlank, q++);
		}
	}
	tempBoard[prevRow][prevColumn][1]='0';
	findSolution(tempBoard,rowFirstBlank,columnFirstBlank, q++);
return 1;
}

