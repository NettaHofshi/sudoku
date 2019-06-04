
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


int allValid(int column, int row, char value, char board[][9][2]){
	if(columnValid(column-1, value, board)==0){
		printf("Error: value is invalid\n");
		return 0;
	}
	if(rowValid(row-1, value, board)==0){
		printf("Error: value is invalid\n");
		return 0;
	}
	if(squareValid(column-1, row-1, value, board)==0){
		printf("Error: value is invalid\n");
		return 0;
	}
	if(board[row-1][column-1][0] == '.'){
		printf("Error: cell is fixed\n");
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
int findEmptyCell (char tempBoard[][9][2],int* curRow, int* curColumn,int* prevRow, int* prevColumn){
	int k;
	for (k=0; k<9; k++){   /*findint the first empty cell*/
			for (int t=0; t<9; t++){
				if (tempBoard[k][t][0]==' '&&tempBoard[k][t][1]!='0'){
					prevRow*=k;
					prevColumn*=t;
				}
				if (tempBoard[k][t][1]=='0'){
					curRow*=k;
					curColumn*=t;
					return 0;  /*found the first empty cell*/
				}
		}
	return 1; /*board is full*/
}
}

int findSolution(char tempBoard[][9][2],int rowFirstBlank, int columnFirstBlank, int firstCall){
	int curRow,curColumn;
	int prevRow, prevColumn;
	int i;
	int lastCellValue;
	if (firstCall==0){
		if (findEmptyCell(tempBoard,*curRow, *curColumn, *prevRow, *prevColumn)==1){ /*if ==1 no empty cells- success!*/
			return 1;
		}
	}
	if(firstCall==0){
		if (rowFirstBlank==curRow && columnFirstBlank==curColumn && tempBoard[curRow][curColumn][1]=='9'){ /*no solution*/
			return 0;
		}
	}

	for (i=1; i<10; i++){   /*try to put value in empty call*/
		if(allValid(curColumn,curRow,i+'0', tempBoard)==1){
			tempBoard[curRow][curColumn][1]=i+'0';
			findSolution(tempBoard,rowFirstBlank,columnFirstBlank, 0);
		}
	}
	lastCellValue= tempBoard[prevRow][prevColumn][1]-47;
	for (; lastCellValue<10; lastCellValue++){   /*try to put a new value in the previous cell*/
		if(allValid(prevColumn,prevRow,lastCellValue+'0', tempBoard)==1){
			tempBoard[curRow][curColumn][1]=lastCellValue+'0';
			findSolution(tempBoard,rowFirstBlank,columnFirstBlank,0);
		}
	}
	tempBoard[prevRow][prevColumn][1]='0';
	findSolution(tempBoard,rowFirstBlank,columnFirstBlank,0);
return 0;
}

