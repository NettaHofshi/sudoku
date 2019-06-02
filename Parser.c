#include <stdio.h>
#include <string.h>
#include "Parser.h"
#include "SPBufferset.h"
#define longestCommand 1024


Command* getNewCommand (){
	int i=0;
	char* commandWord;        /*will hold the command word*/
	char* instructChar;
	char instructChars[longestCommand];     /*will hold all the chars after the command*/
	Command returnedCommand;
	Command* returnedCommand1;
	char commandStr[longestCommand];
	SP_BUFF_SET();
	fgets (commandStr,longestCommand, stdin );
	instructChar= strtok(commandStr," \t\r\n" );
	commandWord= instructChar;
	instructChar=strtok(NULL," \t\r\n" );
	while(instructChar!= NULL ){
		instructChars[i]=*instructChar;
		i++;/*put the chars in the array one by one*/
		instructChar=strtok(NULL," \t\r\n" );


		}
	returnedCommand.column_X=0;
	returnedCommand.commandID=0;
	returnedCommand.row_Y=0;
	returnedCommand.value_Z=0;

	switch (commandWord[0]){
	case 's':  /*set*/
		if (commandWord[1]!= 'e' || commandWord[2]!= 't'){
			printf("Error: invalid command");
			returnedCommand.commandID= 0 ;   /*0= not valid command*/
			break;
		}
		returnedCommand.commandID=1;                /*1= setMove*/
		returnedCommand.column_X= instructChars[0]-48;    /*X- column*/
		returnedCommand.row_Y= instructChars[1]-48;        /*Y- row*/
		returnedCommand.value_Z=instructChars[2]-48;            /*Z- value*/
		break;
	case 'h':   /*hint*/
		if (commandWord[1]!= 'i' || commandWord[2]!= 'n' || commandWord[3]!= 't'){
			printf("Error: invalid command");
			returnedCommand.commandID= 0 ;   /*0= not valid command*/
			break;
				}
		returnedCommand.commandID=2;                /*2= hint*/
		returnedCommand.column_X= instructChars[0]-48;    /*X- column*/
		returnedCommand.row_Y=instructChars[1]-48;        /*Y- row*/
		break;
	case 'v':   /*validate*/
		if (commandWord[1]!= 'a' || commandWord[2]!= 'l' || commandWord[3]!= 'i'){
			printf("Error: invalid command");
			returnedCommand.commandID= 0 ;   /*0= not valid command*/
			break;
		}
		returnedCommand.commandID=3;                /*3= validate*/

		break;
	case 'r':   /*restart*/
		if (commandWord[1]!= 'e' || commandWord[2]!= 's' || commandWord[3]!= 't'|| commandWord[4]!= 'a'|| commandWord[5]!= 'r'|| commandWord[6]!= 't'){
			printf("Error: invalid command");
			returnedCommand.commandID= 0 ;   /*0= not valid command*/
			break;
		}
		returnedCommand.commandID=4;                /*4= restart*/

		break;
	case 'e':   /*exit*/
		if (commandWord[1]!= 'x' || commandWord[2]!= 'i' || commandWord[3]!= 't'){
			printf("Error: invalid command");
			returnedCommand.commandID= 0 ;   /*0= not valid command*/
			break;
		}
		returnedCommand.commandID=5;                /*5= restart*/
		break;
	default:
		printf("Error: invalid command\n");
		returnedCommand.commandID= 0;
}

	returnedCommand1=&returnedCommand;
	return returnedCommand1;
}



