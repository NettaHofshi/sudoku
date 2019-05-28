
#include <stdio.h>
#define NumOfCells 80


int main(){
	printf("Please enter the number of cells to fill [0-80]:\n");
	if (!checkNumOfCellsToFill(NumOfCells)){  /* function to main_aux */
		return 0;
	}

}
