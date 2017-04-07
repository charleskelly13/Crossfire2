
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "crossfireOperations.h"



/*
 * This function creates the board
 * Parameters:
 * 	size: the size of the board
 * 	upLeft: pointer of pointer to slot at position (0, 0)
 * 	upRight: pointer of pointer to slot at position (0, boardSize -1)
 * 	downLeft: pointer of pointer to slot at position (boardSsize -1, 0)
 * 	upLeft: pointer of pointer to slot at position (boardSize - 1, boardSize -1)
 */
/*
void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight)
{

	//The board is represented as a pointer of pointer to slots
	//This allocates in memory the space for the pointers to each row of the board
//	struct slot ** board = malloc(boardSize * sizeof(struct slot *));


	for(int i=0; i< boardSize; i++)
	{
		//For each slot it sets up the row and column number
		for(int j=0; j < boardSize; j++)
		{
			slot[i][j].row = i;
			slot[i][j].column = j;
		}
	}

	//It sets up the adjacent slots for the slots that are
	//not at the borders. These slots have 4 adjacent elements
	for(int i =1; i< boardSize-1; i++)
	{
		for(int j=1;j < boardSize-1; j++)
		{
			slot[i][j].up = &slot[i-1][j];
			slot[i][j].right = &slot[i][j+1];
			slot[i][j].down = &slot[i+1][j];
			slot[i][j].left = &slot[i][j-1];
		}
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last row, except the slots at the edges.
	//
	for(int j = 1; j < boardSize-1; j++){
		//It sets up the adjacent slots for the slots that are in the first row.
		//These slots don't have an adjacent element on top of them
		// because they are on the first row of the board
		slot[0][j].right = &slot[0][j+1];
		slot[0][j].left = &slot[0][j-1];
		slot[0][j].down = &slot[1][j];

		//It sets up the adjacent slots for the slots that are in the last row.
		//These slots don't have an adjacent element on down them
		// because they are on the last row of the board
		slot[boardSize - 1][j].right = &slot[boardSize - 1][j+1];
		slot[boardSize -1][j].left = &slot[boardSize - 1][j-1];
		slot[boardSize - 1][j].up = &slot[boardSize - 2][j];
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last column, except the slots at the edges.
	//
	for(int i = 1; i < boardSize -1; i++)
	{
		//It sets up the adjacent slots for the slots that are in the first row.
		//These slots don't have an adjacent element on the left
		// because they are on the first column of the board
		slot[i][0].right = &slot[i][1];
		slot[i][0].up = &slot[i-1][0];
		slot[i][0].down = &slot[i+1][0];

		//It sets up the adjacent slots for the slots that are in the last row.
		//These slots don't have an adjacent element on the right
		// because they are on the last column of the board
		slot[i][boardSize-1].left = &slot[boardSize - 1][boardSize-2];
		slot[i][boardSize -1].up = &slot[i -1][boardSize-1];
		slot[i][boardSize -1].down = &slot[i+1][boardSize -1];
	}


	//It sets up the adjacent slots for the slot at position (0,0).
	//This only has only 2 adjacent slots: right and down
	slot[0][0].right = &slot[0][1];
	slot[0][0].down = &slot[1][0];

	//It sets up the adjacent slots for the slot at position (0,boardSize -1).
	//This only has only 2 adjacent slots: left and down
	slot[0][boardSize-1].left = &slot[0][boardSize-2];
	slot[0][boardSize -1].down = &slot[1][boardSize -1];

	//It sets up the adjacent slots for the slot at position (boarSize -1 ,0).
	//This only has only 2 adjacent slots: up and right
	slot[boardSize -1][0].right = &slot[boardSize -1][1];
	slot[boardSize -1][0].up = &slot[boardSize -2][0];

	//It sets up the adjacent slots for the slot at position (boarSize -1 ,boardSize-1).
	//This only has only 2 adjacent slots: up and left
	slot[boardSize - 1][boardSize-1].up = &slot[boardSize-2][boardSize-1];
	slot[boardSize - 1][boardSize -1].left = &slot[boardSize -1][boardSize -2];


	//assigns a pointer to slot at position (0, 0)
	*upLeft = &slot[0][0];
	//assigns pointer of pointer to slot at position (0, boardSize -1)
	*upRight = &slot[0][boardSize -1];
	//assigns pointer of pointer to slot at position ( boardSize -1,)
	*downLeft = &slot[boardSize -1][0];
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	*downRight = &slot[boardSize -1][boardSize -1];


	BoardType(boardSize, &slot);

}
*/
void BoardType(const int boardSize, struct slot *slot)
{
	int i, j=0;

	for(i=0; i<boardSize; i++)
	{
		while(j<boardSize)
		{
			assignSlots(&slot, i, j);
			printf("%d %d: %s\n", i, j, slot[i][j].type);
			j++;
		}
		j=0;
	}
}

void assignSlots(struct slot *slot)		//slot ground type function
{
	int random=0;
	srand(time(NULL));

	random = 1+rand()%3;	//three possible slot types
	if(random==1)			//if random is 1 then slot type is ground
	{
		strcpy(slot->type, "Ground");
	}
	else if(random==2)		//if it's 2 then slot type is city
	{
		strcpy(slot->type, "City");
	}
	else					//if it's 3 then slot type is hill
	{
		strcpy(slot->type, "Hill");
	}

	return;
}


