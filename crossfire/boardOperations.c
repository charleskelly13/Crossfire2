
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "crossfireOperations.h"


void createBoard(struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot *board)
{
	int i, j;

	struct slot ** board = malloc(BOARDSIZE * sizeof(struct slot *));

	for(i=0; i<BOARDSIZE; i++) //places number in row and column variable
	{
		board[i] = malloc(BOARDSIZE * sizeof(struct slot));
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

void BoardType(struct slot ***board)
{
	int i, j=0;
	for(i=0; i<BOARDSIZE; i++)
		{
			for(j=0; j<BOARDSIZE; j++)
			{
				int random;
				random = assignSlots();
	printf("random = %d\n", random);
//				random = 1+rand()%3;	//three possible slot types

				if(random==1)			//if random is 1 then slot type is ground
				{
					printf("1 %d\n", random);
					strcpy(&board[i][j]->type, "Ground");
				}
				else if(random==2)		//if it's 2 then slot type is city
				{
					printf("2 %d\n", random);
					strcpy(&board[i][j]->type, "City");
				}
				else					//if it's 3 then slot type is hill
				{
					printf("3 %d\n", random);
					strcpy(&board[i][j]->type, "Hill");
				}
//				printf("%d %d: %s\n", i, j, &board[i][j]->type);
			}
		}

}

int assignSlots()
{
	srand(time(NULL));
	return (1+rand()%3);
}
