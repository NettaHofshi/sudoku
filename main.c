
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SPBufferset.h"
#include "Parser.h"
#include "Game.h"
#include "MainAux.h"
#include "Solver.h"

int main(int argc, char *argv[]){
	int i,j,k, restartValue=1, l;
	int *res = &restartValue;
	int numOfCellToFill=0;
	int continueGame=0;
	Command* command;
	char gameBoard [9][9][2];
	char solvedBoard [9][9][2];
	char tempBoard[9][9][10];
	SP_BUFF_SET();
	if (argc>=1){
		srand(atoi(argv[1]));      /*the seed*/
	}

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
	/*
tempBoard[0][0][9]='1';
tempBoard[0][1][9]='2';
tempBoard[0][2][9]='3';
tempBoard[1][0][9]='4';
l=createOptions(tempBoard,1,2);
printf("%d\n%c\n", l,tempBoard[1][2][0] );
*/
while(restartValue==1){
	restartValue=0;
	continueGame=0;
	printf("Please enter the number of cells to fill [0-80]:\n");

	if(checkNumOfCellsToFill(80)==99){
		return 0;
	}

	startBoard(tempBoard,gameBoard,solvedBoard,numOfCellToFill);
	printBoard(solvedBoard);

	while (continueGame==0){
		printBoard(gameBoard);
		/*printBoard(solvedBoard);*/
		command= getNewCommand(gameBoard);
		if (command==NULL){
			return 0;
		}
		while (command->commandID==0){      /*the user wrote a non valid command*/
			command= getNewCommand(gameBoard);
		}
		switch (command->commandID){
			case 1:  /*set*/
				setMove(command->column_X,command->row_Y,command->value_Z, gameBoard);
				if(gameOver(gameBoard) == 1){
					printf("Puzzle solved successfully\n");
					continueGame=1;
				}
				break;
			case 2:   /*hint*/
				hint(command->column_X,command->row_Y, solvedBoard);
				break;
			case 3:   /*validate*/
				validate(gameBoard, solvedBoard);
				break;
			case 4:   /*restart*/
				restart(res);
				continueGame=2;
				break;
			case 5:   /*exit*/
				continueGame=3;
				break;
		}
	}


	if (continueGame==1){  /* if board solved- game over, only restart or exit is poosible*/
		command= getNewCommand(gameBoard);
		while (command->commandID==0 ||command->commandID==1||command->commandID==2||command->commandID==3){      /*only Exit and Restared are allowed*/
			if (command->commandID==1||command->commandID==2||command->commandID==3){
				printf("Error: invalid command\n");
			}
			command= getNewCommand(gameBoard);
		}

		if (command->commandID==4 ){
			restart(res);
		}

		if(command->commandID==5){
			exitGame();
			return 0;
		}
	}


	if (continueGame==2){  /* if restart*/
		restart(res);
	}
	if(continueGame==3){   /*(continueGame==3)-- if exit*/
		exitGame();
		return 0;
	}
}
return 0;
}

