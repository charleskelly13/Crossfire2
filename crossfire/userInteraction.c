/*
 * userInteraction.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#include <stdio.h>
#include "crossfireOperations.h"

//This function returns the board size provided as input by the user
int getBoardSize(){
	int boardSize;
	printf("Please enter the required size of the board\n");
	//asks the user to enter the desired board size
	scanf("%d", &boardSize);
	return boardSize;
}

//THis function takes as input the size of the board and the pointers
// to the integers representing the row and the column of the slot that
// the user want to retrieve
void getDesiredElement(int boardSize, int * row, int * col){
	printf("Please enter the column and the Row of the desired slot \n");
	printf("Note that size of the board is %d\n", boardSize);

		//it will cycle asking the user to insert the row
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Row: ");
			scanf("%d", row);
			printf("%d\n", *row);
			if(row < 0 && *row >= boardSize)
				printf("Error: Incorrect row dimension\n");
		} while(*row < 0 && *row >= boardSize);

		//it will cycle asking the user to insert the column
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Column: ");
			scanf("%d", col);
			printf("%d\n", *col);
			if(*col < 0 && *col >= boardSize)
				printf("Error: Incorrect column dimension\n");
		} while(*col < 0 && *col >= boardSize);
}









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

void attack(struct Players *attacker, struct Players *attacked)		//attack function
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
