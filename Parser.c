#include <stdio.h>
#include <string.h>
#define longestCommand 1024
void parseSetCommand(char* firstLetter){
printf("ok");
}

void parseHintCommand(char* firstLetter){

}
void parseValidateCommand(char* firstLetter){

}
void parseRestartCommand(char* firstLetter){

}

void parseExitCommand(char* firstLetter){

}
void getNewCommand (){
	char* firstLetter;
	char commandStr[longestCommand];
	fgets (commandStr,longestCommand, stdin );
	printf("str is: %s", commandStr );

	firstLetter= strtok(commandStr," \t\r\n"  );

	switch (firstLetter[0]){
	case 's':  /*set*/
		parseSetCommand(firstLetter);
		break;
	case 'h':   /*hint*/
		parseHintCommand(firstLetter);
		break;
	case 'v':   /*validate*/
		parseValidateCommand(firstLetter);
		break;
	case 'r':   /*restart*/
		parseRestartCommand(firstLetter);
		break;
	case 'e':   /*exit*/
		parseExitCommand(firstLetter);
		break;

}
}

