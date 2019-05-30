#include <stdio.h>

int checkNumOfCellsToFill (int range){
	int fillCells;
	if (feof(stdin)){
		printf("Exiting...\n");
		return 99;
	}
	scanf("%d",&fillCells); /*what if scanf fails???? */
	while (fillCells<0 || fillCells>range){
		printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
		printf("Please enter the number of cells to fill [0-80]:\n");
		scanf("%d",&fillCells);
	}

return fillCells;
}
