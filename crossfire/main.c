
#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"



int main()
{
	int Player_Num;
	setvbuf(stdout, 0, _IONBF, 0);
	Player_Num = PlayerData();

	int row, column;

	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARDSIZE][BOARDSIZE];
	int count = 0;

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


	/*	Asks the user the row and the column of the slot
		s/he wants to retrieve from the board.
		Note that the user needs to know the size of the board to input
		the correct row and column of the slot s/he wants to retrieve */
		getDesiredElement(BOARDSIZE, &row,&column);

		//Finds the slot


		/*If the the required slot is closer to the down-right
		 * corner of the board the search starts from downRight,
		 * which points to slot at position (boardSize-1, boarSize -1)*/
		if(row >= BOARDSIZE/2)
		{
			if(column >= BOARDSIZE/2)
			{
				currSlot = reachDesiredElement(row,column,downRight);
			}
			else
			{
				/*If the the required slot is closer to the down-left
				 * corner of the board the search starts from downLeft,
				 * which points to slot at position (boardSize-1, 0)*/
				currSlot = reachDesiredElement(row,column,downLeft);
			}
		}
		else
		{
			/*If the the required slot is closer to the up-right
			* corner of the board the search starts from upRight,
			* which points to slot at position (0, boarSize -1)*/
			if(column >= BOARDSIZE/2)
			{
				currSlot = reachDesiredElement(row,column, upRight);
			/*If the the required slot is closer to the up-left
			* corner of the board the search starts from upLeft,
			* which points to slot at position (0, 0)*/
			}
			else
				{
				currSlot = reachDesiredElement(row,column,upLeft);
				}
		}

		for(int i=0; i<BOARDSIZE; i++)
		{
			for(int j=0; j<BOARDSIZE;j++)
			{
				explored[i][j] = false;
			}
		}

		foundSlots = malloc(BOARDSIZE * BOARDSIZE * sizeof(struct slot ));
		printf("\n\nFunction findSlotsinvoked:\n");

		if(currSlot!= NULL)
		{
			//invokes function findSlots. The required distance is a constant
			//However you can reuse this function providing as input any arbitrary distance
			findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
			for(int i=0; i<count; i++)
			{
				printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
			}
		}


	return 0;
}
