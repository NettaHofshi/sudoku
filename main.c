
#include <stdio.h>
#include "SPBufferset.h"
#include "Parser.h"
#include "Game.h"
#include "MainAux.h"
#include "Solver.h"

int main(){
	int i,j;
	int numOfCellToFill=0;
	int continueGame=0;
	Command* command;
	char gameBoard [9][9][2];
	char solvedBoard [9][9][2];

	SP_BUFF_SET();

	for( i=0; i<9; i++){       /*start the board with .0*/
		for( j=0; j<9; j++){
			solvedBoard[i][j][0]='.';
			solvedBoard[i][j][1]='0';
			gameBoard[i][j][0]='.';
			gameBoard[i][j][1]='0';
			}
		}

	printf("Please enter the number of cells to fill [0-80]:\n");

	if(checkNumOfCellsToFill(80)==99){
		return 0;
	}

	createBoard(gameBoard,solvedBoard,numOfCellToFill);

	while (continueGame==0){
		printBoard(gameBoard);        /*???*/
		command= getNewCommand();
		while (command->commandID==0){      /*the user wrote a non valid command*/
			command= getNewCommand();
		}
		switch (command->commandID){
			case 1:  /*set*/
				setMove(command->column_X,command->row_Y,command->value_Z, gameBoard);
				break;
			case 2:   /*hint*/
				hint(command->column_X,command->row_Y, gameBoard);
				break;
			case 3:   /*validate*/
				/*validate(gameBoard);*/
				break;
			case 4:   /*restart*/
				/*restart();*/
				break;
			case 5:   /*exit*/
				/*exitGame();*/
				break;
		}
	}

	if (continueGame==1){  /* if board solved- game over, only restart or exit is poosible*/
		command= getNewCommand();
		while (command->commandID==0 ||command->commandID==1||command->commandID==2||command->commandID==3){      /*only Exit and Restared are allowed*/
			command= getNewCommand();
		}
		/*
		if (command->commandID==4 ){
			restart();
		}
		if(command->commandID==5){
			exitGame();
		}
		*/
	if (continueGame==2){  /* if restart*/
		main();
	}
	else{  /*(continueGame==3)-- if exit*/
		return 0;
	}
	}
return 0;
}

