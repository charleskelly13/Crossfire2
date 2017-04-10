
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "crossfireOperations.h"


void createBoard(struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight)
{
	int i, j;

//	struct slot ** board = malloc(BOARDSIZE * sizeof(struct slot *));
//	*board = malloc(BOARDSIZE * sizeof(struct slot *));

	for(i=0; i<BOARDSIZE; i++) //places number in row and column variable
	{
//		board[i] = malloc(BOARDSIZE * sizeof(struct slot));
		for(j=0; j<BOARDSIZE; j++)
		{
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	//adjacent slots except for outer ones
	for(i=1; i<(BOARDSIZE-1); i++)
	{
		for(j=1; j<(BOARDSIZE-1); j++)
		{
			board[i][j].up = &board[i-1][j];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
			board[i][j].right = &board[i][j+1];
		}
	}

	for(j=1; j<(BOARDSIZE-1); j++)
	{
		//adjacent slots for first row, except first + last
		board[0][j].up = NULL;
		board[0][j].down = &board[1][j];
		board[0][j].left = &board[0][j-1];
		board[0][j].right = &board[0][j+1];

		//Adjacent slots for last row, except first + last
		board[BOARDSIZE-1][j].up = &board[BOARDSIZE-2][j];
		board[BOARDSIZE-1][j].down = NULL;
		board[BOARDSIZE-1][j].left = &board[BOARDSIZE-1][j-1];
		board[BOARDSIZE-1][j].right = &board[BOARDSIZE-1][j+1];
		}

	for(i=1; i<(BOARDSIZE-1); i++)
	{
		//Adjacent slots for first column, except first + last
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];
		board[i][0].left = NULL;
		board[i][0].right = &board[i][1];

		//Adjacent slots for last row, except first + last
		board[i][BOARDSIZE-1].up = &board[i-1][BOARDSIZE-1];
		board[i][BOARDSIZE-1].down = &board[i+1][BOARDSIZE-1];
		board[i][BOARDSIZE-1].left = &board[i][BOARDSIZE-2];
		board[i][BOARDSIZE-1].right = NULL;
	}

	//It sets up the adjacent slots for the slot at position (0,0).
	//This only has only 2 adjacent slots: right and down
	board[0][0].right = &board[0][1];
	board[0][0].down = &board[1][0];

	//It sets up the adjacent slots for the slot at position (0,boardSize -1).
	//This only has only 2 adjacent slots: left and down
	board[0][BOARDSIZE-1].left = &board[0][BOARDSIZE-2];
	board[0][BOARDSIZE-1].down = &board[1][BOARDSIZE-1];

	//It sets up the adjacent slots for the slot at position (boarSize -1 ,0).
	//This only has only 2 adjacent slots: up and right
	board[BOARDSIZE-1][0].right = &board[BOARDSIZE-1][1];
	board[BOARDSIZE-1][0].up = &board[BOARDSIZE-2][0];

	//It sets up the adjacent slots for the slot at position (boarSize -1 ,boardSize-1).
	//This only has only 2 adjacent slots: up and left
	board[BOARDSIZE-1][BOARDSIZE-1].up = &board[BOARDSIZE-2][BOARDSIZE-1];
	board[BOARDSIZE-1][BOARDSIZE-1].left = &board[BOARDSIZE-1][BOARDSIZE-2];

	//assigns a pointer to slot at position (0, 0)
	*upLeft = &board[0][0];
	//assigns pointer of pointer to slot at position (0, boardSize -1)
	*upRight = &board[0][BOARDSIZE-1];
	//assigns pointer of pointer to slot at position ( boardSize -1,)
	*downLeft = &board[BOARDSIZE-1][0];
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	*downRight = &board[BOARDSIZE-1][BOARDSIZE-1];

//	BoardType(&board);

}

void BoardType()
{
	int i, j;

	printf("\n\nBoard is:\n");

	for(i=0; i<BOARDSIZE; i++)
		{
			for(j=0; j<BOARDSIZE; j++)
			{
				int random;
				random = assignSlots();
//	printf("random = %d\n", random);
//				random = 1+rand()%3;	//three possible slot types

				if(random==1)			//if random is 1 then slot type is ground
				{
					strcpy(&board[i][j].type, "Ground");
				}
				else if(random==2)		//if it's 2 then slot type is city
				{
					strcpy(&board[i][j].type, "City");
				}
				else					//if it's 3 then slot type is hill
				{
					strcpy(&board[i][j].type, "Hill");
				}
				printf("(%d,%d): %s\t", i, j, &board[i][j].type);
			}
			printf("\n");
		}

}

int assignSlots()
{

	return (1+rand()%3);
}



/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column). This function returns a pointer to the desired slot
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot * reachDesiredElement(int row, int column, struct slot * initialSlot){

	bool found = false;
	//current slot
	struct slot * currentSlot = initialSlot;

	printf("\nFunction reachDesiredElement invoked\n");

	//prints the column and the row of the initial slot from which the search starts
	printf("Initial slot (%d, %d) -> \n",initialSlot->row,initialSlot->column);


	//while the slot is not found
	while(found == false)
	{


		//if the row of the current slot is > of the row of the desired slot,
		//we move up
		if(currentSlot->row > row)
		{
			//the current slot now points to the slot one row up
			currentSlot = currentSlot->up;
			//prints the column and the row of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}

		//if the row of the current slot is < of the row of the desired slot,
		//we move down
		if(currentSlot->row < row)
		{
			//the current slot now points to the slot one row down
			currentSlot = currentSlot->down;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);

		}
		//if the column of the current slot is > of the column of the desired slot,
		//we move left
		if(currentSlot->column > column)
		{

			//the current slot now points to the slot one column left
			currentSlot = currentSlot->left;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}

		//if the column of the current slot is < of the column of the desired slot,
		//we move right
		if(currentSlot->column < column){

			//the current slot now points to the slot one column right
			currentSlot = currentSlot->right;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);

		}
		//if the current slot is at a column and a row equal to the desired column and row, respectively
		// we found the slot
		if(currentSlot->column == column && currentSlot->row == row){
			printf("Found\n");
			found = true;
		}

	}
	//returns the found slot
	return currentSlot;
}

/*
 * The recursive function that traverses the board to find the slots at a predefined
 * distance from the current slot and place them in foundSlots.
 * Parameters:
 * 	reqDist: the required distance from the starting slot
 * 	currDist: the distance of the current slot from the starting slot
 * 	currSlot: a pointer to the current slot that is traversed
 * 	foundSlots: the array of slots that are at a required distance from the starting slot
 * 	count: pointer to an integer representing the number of slots that are found to be at a required distance from the starting slot
 * 	explored: matrix indicating for each slot at row x and column y has been traversed (true) or not (false)
 */
void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[BOARDSIZE][BOARDSIZE]){



	//The base case: the current slot is at the required distance from the starting slot
	if(currDist == reqDist){
		//the current slot was not explored
		if(explored[currSlot->row][currSlot->column] == false){
			//The next availbale position (indicated by count) at foundSlots points to the current slot
			*(foundSlots + *count) = *currSlot;
			//the counter is incremented
			(*count)++;
			//the matrix of the explored slots set to true the element at the row and column of the current slot
			explored[currSlot->row][currSlot->column] = true;
		}
	}
	//The recursive call: the current slot is at a distance that is less than the required distance (more slots still have to be traversed)
	else{
		//if the current slot has the up slot != NULL (i.e. the slot is not in the first row)
		if(currSlot->up != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the up slot
			findSlots(reqDist, currDist +1,  currSlot->up, foundSlots, count, explored);
		}
		//if the current slot has the right slot != NULL (i.e. the slot is not in the last column)
		if(currSlot->right != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the right slot
			findSlots(reqDist, currDist +1,  currSlot->right, foundSlots, count, explored);
		}
		//if the current slot has the down slot != NULL (i.e. the slot is not in the last row)
		if(currSlot->down != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the down slot
			findSlots(reqDist, currDist +1,  currSlot->down, foundSlots, count, explored);
		}
		//if the current slot has the left slot != NULL (i.e. the slot is not in the first column)
		if(currSlot->left != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the left slot
			findSlots(reqDist, currDist +1,  currSlot->left, foundSlots, count, explored);
		}

	}


}

