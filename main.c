
#include <stdio.h>
#include "SPBufferset.h"
#include "Parser.h"
#include "Game.h"

int main(){
	/*
	char board[9][9][2];
	for( int i=0; i<9; i++){
		for( int j=0; j<9; j++){
			board[i][j][0]='.';
			board[i][j][1]='2';
		}
	}
	printBoard(board*);
	*/
	SP_BUFF_SET();


	int numOfCellToFill,i,j;
	int continueGame=0;
	char * command;
	char gameBoard [9][9][2];
	for( int i=0; i<9; i++){       /*start the board with 0*/
		for( int j=0; j<9; j++){
			gameBoard[i][j][0]='.';
			gameBoard[i][j][1]='0';

	char solvedBoard [9][9][2];
		for( int i=0; i<9; i++){       /*start the board with 0*/
			for( int j=0; j<9; j++){
				solvedBoard[i][j][0]='.';
				solvedBoard[i][j][1]='0';

	printf("Please enter the number of cells to fill [0-80]:\n");

	if(checkNumOfCellsToFill(80)==99){
		return 0;
	}

	createBoard(gameBoard,solvedBoard,numOfCellToFill);

	while (continueGame==0){
		command= getNewCommand();
		/* extract values from array*/

		switch (command[0]){
			case '1':  /*set*/
				setMove(command[1],command[2],command[3], gameBoard);
				break;
			case '2':   /*hint*/
				parseHintCommand(firstLetter);
				break;
			case '3':   /*validate*/
				parseValidateCommand(firstLetter);
				break;
			case '4':   /*restart*/
				parseRestartCommand(firstLetter);
				break;
			case '5':   /*exit*/
				parseExitCommand(firstLetter);
				break;
}
		if (continueGame==1){  /* if exit*/
			return 0;
		}
		if (continueGame==2){  /* if restart*/
					main();
				}
		if (continueGame==3){  /* if board solved- game over, only restart or exit is poosible*/

				}
	}
