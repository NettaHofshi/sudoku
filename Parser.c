#include <stdio.h>
#include <string.h>
#include "Parser.h"
#define longestCommand 1024


Command* getNewCommand (){
	char* firstLetter;
	Command* returnedCommand;
	char commandStr[longestCommand];
	fgets (commandStr,longestCommand, stdin );
	printf("str is: %s", commandStr );
	firstLetter= strtok(commandStr," \t\r\n"  );

	switch (firstLetter[0]){
	case 's':  /*set*/
		if (firstLetter[1]!= 'e' || firstLetter[2]!= 't'){
			printf("Error: invalid command");
			returnedCommand->commandID= 0 ;   /*0= not valid command*/
			return returnedCommand;
		}
		returnedCommand->commandID=1;                /*1= setMove*/
		returnedCommand->column_X= firstLetter[3];    /*X- column*/
		returnedCommand->row_Y= firstLetter[4];        /*Y- row*/
		returnedCommand->value_Z=firstLetter[5];            /*Z- value*/
		return returnedCommand;
		break;
	case 'h':   /*hint*/
		if (firstLetter[1]!= 'i' || firstLetter[2]!= 'n' || firstLetter[3]!= 't'){
			printf("Error: invalid command");
			returnedCommand->commandID= 0 ;   /*0= not valid command*/
			return returnedCommand;
				}
		returnedCommand->commandID=2;                /*2= hint*/
		returnedCommand->column_X= firstLetter[3];    /*X- column*/
		returnedCommand->row_Y= firstLetter[4];        /*Y- row*/
		return returnedCommand;
		break;
	case 'v':   /*validate*/
		if (firstLetter[1]!= 'a' || firstLetter[2]!= 'l' || firstLetter[3]!= 'i'|| firstLetter[4]!= 'd'|| firstLetter[5]!= 'a'|| firstLetter[6]!= 't'|| firstLetter[7]!= 'e'){
			printf("Error: invalid command");
			returnedCommand->commandID= 0 ;   /*0= not valid command*/
			return returnedCommand;
		}
		returnedCommand->commandID=3;                /*3= validate*/
		return returnedCommand;
		break;
	case 'r':   /*restart*/
		if (firstLetter[1]!= 'e' || firstLetter[2]!= 's' || firstLetter[3]!= 't'|| firstLetter[4]!= 'a'|| firstLetter[5]!= 'r'|| firstLetter[6]!= 't'){
			printf("Error: invalid command");
			returnedCommand->commandID= 0 ;   /*0= not valid command*/
			return returnedCommand;
		}
		returnedCommand->commandID=4;                /*4= restart*/
		return returnedCommand;
		break;
	case 'e':   /*exit*/
		if (firstLetter[1]!= 'x' || firstLetter[2]!= 'i' || firstLetter[3]!= 't'){
			printf("Error: invalid command");
			returnedCommand->commandID= 0 ;   /*0= not valid command*/
			return returnedCommand;
		}
		returnedCommand->commandID=5;                /*5= restart*/
		return returnedCommand;
		break;
	default:
		printf("Error: invalid command\n");
		returnedCommand->commandID= 0;
		return returnedCommand;


}
}

