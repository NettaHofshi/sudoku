
#ifndef PARSER_H_
#define PARSER_H_



typedef struct {
	int commandID;    /*0=not valid, 1=set,  2=hint,  3=validate ,  4= restart,  5= exit*/
	int column_X;
	int row_Y;
	char value_Z;
}Command;

Command* getNewCommand ();

#endif /* PARSER_H_ */
