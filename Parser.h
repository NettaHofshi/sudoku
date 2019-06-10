
#ifndef PARSER_H_
#define PARSER_H_

/*
 * Command stuct:
 * Describes a new command, and the parameters it holds.
 * if a command doesnt have all of the parameters, then it will hold garbish.
 *
 * commandID- to know which command it is: 0-not valid 1- set 2-hint 3-validate 4-restart 5-exit
 * column_X- will hold the cell column if it is necessary
 * int row_Y-will hold the cell row if it is necessary
 * value_Z- only relevant in set command. holds the value the user want to put in the cell.
 */

typedef struct {
	int commandID;
	int column_X;
	int row_Y;
	char value_Z;
}Command;

/*
 * getNewCommand function:
 * gets a new command from the user and parse it so the program could use it.
 * board= the game board
 *
 * the function reads the users input and parse it to chars.
 * according to the firts letter it checks which command it is (or if its not a valid command)
 * then according to the command format, it puts the parameters in a new Command and returns it to the Caller.
 *
 * parameters-
 * board- the game board
 * status- determines if it is needed to check if is set value is valid (0) or not(1)
 */

Command* getNewCommand (char board[][9][2], int status);

#endif /* PARSER_H_ */
