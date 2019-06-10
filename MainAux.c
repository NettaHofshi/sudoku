#include <stdio.h>

void initAllBoards(char gameBoard [][9][2],char solvedBoard [][9][2],char tempBoard[9][9][10]){
	int i=0,j=0,k=0;
	for( i=0; i<9; i++){       /*start the board with .0--- need to delete this*/
		for( j=0; j<9; j++){
			solvedBoard[i][j][0]=' ';
			solvedBoard[i][j][1]='0';
			gameBoard[i][j][0]=' ';
			gameBoard[i][j][1]='0';
			for(k=0;k<10;k++){
				tempBoard[i][j][k]='0';
			}
		}
		}
}

int checkNumOfCellsToFill (int range){
	int fillCells;

	if(scanf("%d",&fillCells)<=0){ /*what if scanf fails???? */
		if (feof(stdin)){
				printf("Exiting...\n");
				return 99;
		}
		printf("Error: <scanf> has failed\n");
		return 99;

	}
	while (fillCells<0 || fillCells>range){
		printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
		printf("Please enter the number of cells to fill [0-80]:\n");
		if(scanf("%d",&fillCells)<=0){
			printf("Error: <scanf> has failed\n");
			return 99;
		}
	}

return fillCells;
}
