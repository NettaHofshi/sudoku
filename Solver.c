
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

void solveBoard(char gameBoard[][9][2],char solvedBoard[][9][2]){

}

