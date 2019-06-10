
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SPBufferset.h"
#include "Parser.h"
#include "Game.h"
#include "MainAux.h"
#include "Solver.h"

int main(int argc, char *argv[]){
	int restartValue=1, printTag=1;
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


while(restartValue==1){
	restartValue=0;
	continueGame=0;
	printf("Please enter the number of cells to fill [0-80]:\n");
	numOfCellToFill=checkNumOfCellsToFill(80);
	if(numOfCellToFill==99){
		return 0;
	}
	startBoard(tempBoard,gameBoard,solvedBoard,numOfCellToFill);
	while (continueGame==0){
		if (printTag==1){
			printBoard(gameBoard);
		}
		printTag=1;
		command= getNewCommand(gameBoard,0);
		if(command==NULL){
			return 0;
		}
		while (command->commandID==0){      /*the user wrote a non valid command*/
			command= getNewCommand(gameBoard,0);
		}
		switch (command->commandID){
			case 1:  /*set*/
				setMove(command->column_X,command->row_Y,command->value_Z, gameBoard);
				if(gameOver(gameBoard) == 1){
					printBoard(gameBoard);
					printf("Puzzle solved successfully\n");
					continueGame=1;
				}
				break;
			case 2:   /*hint*/
				printTag=0;
				hint(command->column_X,command->row_Y, solvedBoard);
				break;
			case 3:   /*validate*/
				printTag =0;
				validate(gameBoard, solvedBoard);
				break;
			case 4:   /*restart*/
				restart(res);
				continueGame=2;
				break;
			case 5:   /*exit*/
				continueGame=3;
				break;
			case 6:
				printTag=0;
				break;
		}
	}


	if (continueGame==1){  /* if board solved- game over, only restart or exit is poosible*/
		command= getNewCommand(gameBoard,1);
		while (command->commandID==0 ||command->commandID==1||command->commandID==2||command->commandID==3){      /*only Exit and Restared are allowed*/
			if (command->commandID==1||command->commandID==2||command->commandID==3){
				printf("Error: invalid command\n");
			}
			command= getNewCommand(gameBoard,1);
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

