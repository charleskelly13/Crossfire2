
#include <stdio.h>
#include "crossfireOperations.h"


int main()
{
	setvbuf(stdout, 0, _IONBF, 0);
	int /*row, column,*/ boardSize = 7;

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
//	createBoard(boardSize,&upLeft, &upRight, &downLeft, &downRight);
	BoardType(boardSize, &slot);

	return 0;
}
