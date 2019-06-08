#include <stdio.h>

int checkNumOfCellsToFill (int range){
	int fillCells;
	if (feof(stdin)){
		printf("Exiting...\n");
		return 99;
	}
	if(scanf("%d",&fillCells)<=0){ /*what if scanf fails???? */
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
