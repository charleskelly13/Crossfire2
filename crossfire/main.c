
#include <stdio.h>
#include "crossfireOperations.h"



int main()
{

	setvbuf(stdout, 0, _IONBF, 0);

	PlayerData();
for(int j=0; j<2; j++){
	printf("\nPlayer [%d]: %s"
						"Player Type: %s\n"
						"Strength: %d\n"
						"Magic: %d\n"
						"Dexterity: %d\n"
						"Luck: %d\n"
						"Smartness: %d\n",
						j+1, Player[j].Name,
						Player[j].Race,
						Player[j].Strength,
						Player[j].MagicSkills,
						Player[j].Dexterity,
						Player[j].Luck,
						Player[j].Smartness);}

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;


	//Creates the board

	createBoard(&upLeft, &upRight, &downLeft, &downRight, &board);
//	BoardType(&slots);


	for(int i=0; i<BOARDSIZE; i++)
	{
		for(int j=0; j<BOARDSIZE; j++)
		{
			printf("slots[%d][%d] is [%d][%d]\n", i, j, board.row, board.column);
		}
	}

	return 0;
}
