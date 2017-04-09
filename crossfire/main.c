
#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"



int main()
{

	setvbuf(stdout, 0, _IONBF, 0);
	PlayerData();

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;


	//Creates the board

	createBoard(&upLeft, &upRight, &downLeft, &downRight);
	BoardType();


	for(int i=0; i<BOARDSIZE; i++)
	{
		for(int j=0; j<BOARDSIZE; j++)
		{
			printf("slots[%d][%d] is [%d][%d]\n", i, j, board[i][j].row, board[i][j].column);
		}
	}

	return 0;
}
