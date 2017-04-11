/*
 * attack.c
 *
 *  Created on: 10 Apr 2017
 *      Author: Órla
 */

#include <stdio.h>
#include "crossfireOperations.h"



void disattack(struct Players *attacker, struct Players *attacked)		//distant attack function
{
	if(attacked->Dexterity>=attacker->Dexterity)
	{
	}
	else if(attacker->Dexterity>attacked->Dexterity)	//If the dexterity points of the attacked player are greater than the attacked players dexterity
	{								//the attacker life points = life points - 0.3 * (attacker player’s strength points).
		attacked->LifePoints=attacked->LifePoints - (0.3*attacker->Strength);
	}
}

void magicattack(struct Players *attacker, struct Players *attacked)		//magic attack function
{
	attacked->LifePoints=attacked->LifePoints - ((0.3*attacker->MagicSkills)+(0.2*attacker->Smartness));
}

void nearattack(struct Players *attacker, struct Players *attacked)		//attack function
{
	if(attacked->Strength>70)//If the Strength points of the attacked player are <=70,
	{						//then attacked player life points = life points - 0.5 * his/her Strength points.
		attacker->LifePoints=attacker->LifePoints - (0.3*attacked->Strength);
	}
	else if(attacked->Strength<=70)	//If the strength points of the attacked player are > 70,
	{								//the attacker life points = life points - 0.3 * (attacked player’s strength points).
		attacked->LifePoints=attacked->LifePoints - (0.5*attacked->Strength);
	}
}





/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column). This function returns a pointer to the desired slot
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot * reachDesiredElement(int row, int column, struct slot * initialSlot)
{
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
		if(currentSlot->column < column)
		{
			//the current slot now points to the slot one column right
			currentSlot = currentSlot->right;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}
		//if the current slot is at a column and a row equal to the desired column and row, respectively
		// we found the slot
		if(currentSlot->column == column && currentSlot->row == row)
		{
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
void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[BOARDSIZE][BOARDSIZE])
{
	//The base case: the current slot is at the required distance from the starting slot
	if(currDist == reqDist)
	{
		//the current slot was not explored
		if(explored[currSlot->row][currSlot->column] == false)
		{
			//The next availbale position (indicated by count) at foundSlots points to the current slot
			*(foundSlots + *count) = *currSlot;
			//the counter is incremented
			(*count)++;
			//the matrix of the explored slots set to true the element at the row and column of the current slot
			explored[currSlot->row][currSlot->column] = true;
		}
	}
	//The recursive call: the current slot is at a distance that is less than the required distance (more slots still have to be traversed)
	else
	{
		//if the current slot has the up slot != NULL (i.e. the slot is not in the first row)
		if(currSlot->up != NULL)
		{
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the up slot
			findSlots(reqDist, currDist +1,  currSlot->up, foundSlots, count, explored);
		}
		//if the current slot has the right slot != NULL (i.e. the slot is not in the last column)
		if(currSlot->right != NULL)
		{
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the right slot
			findSlots(reqDist, currDist +1,  currSlot->right, foundSlots, count, explored);
		}
		//if the current slot has the down slot != NULL (i.e. the slot is not in the last row)
		if(currSlot->down != NULL)
		{
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the down slot
			findSlots(reqDist, currDist +1,  currSlot->down, foundSlots, count, explored);
		}
		//if the current slot has the left slot != NULL (i.e. the slot is not in the first column)
		if(currSlot->left != NULL)
		{
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the left slot
			findSlots(reqDist, currDist +1,  currSlot->left, foundSlots, count, explored);
		}
	}
}
