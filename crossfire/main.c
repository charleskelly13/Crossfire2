
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crossfireOperations.h"



int main()
{
	srand(time(NULL));
	int Player_Num, i;
	setvbuf(stdout, 0, _IONBF, 0);
	Player_Num = InputPlayers();

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
	assignPlace(Player_Num);

	for(i=0; i<Player_Num; i++)
	{
		boost(&Player[i], &board[Player->PlaceRow][Player->PlaceColumn]);
	}

	turns(Player_Num);

	return 0;
}
