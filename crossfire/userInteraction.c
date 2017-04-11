/*
 * userInteraction.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#include <stdio.h>
#include "crossfireOperations.h"

int InputPlayers()
{
	int PlayerNum, j;

	printf("Enter the number of players you want, between 2 and 6:"); //gives number of players
	scanf("%d", &PlayerNum);
	getchar();

	while(PlayerNum<2 || PlayerNum>6)	//if the correct number isn't chosen
		{
			printf("\nEnter a number between 2 and 6: "); //gives number of players
			scanf("%d", &PlayerNum);
			getchar();		//so it reads in the new line char
		}

		for(j=0; j<PlayerNum; j++)	//player name/type/stat
		{
			printf("\n\nEnter player name: ");
			fgets (Player[j].Name, 25, stdin);		//to read in second names
			type(&Player[j]);		//assign type
			stat(&Player[j]);		//assign stats
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
					Player[j].Smartness);
		}
		return PlayerNum;
}

int move(struct Players *Player, int x, int playernumber, int column, int row)	//function to move players
 {
 	int right=0, left=0, down=0, up=0, e=0;
 	if(board[row][column+1].right!=NULL)
 	{
 		right=1;
 	}
 	if(board[row][column-1].left!=NULL)
 	{
 		left=1;
 	}
 	if(board[row+1][column].down!=NULL)
 	{
 		down=1;
 	}
 	if(board[row-1][column].up!=NULL)
 	{
 		up=1;
 	}

 	if(right==1 && left==0 && down==0 && up==0)
 	{
 		printf("You can move right. Enter 1 to move right: ");
 		scanf("%d", &e);
 	}
 	else if(right==0 && left==1 && down==0 && up==0)
 	{
 		printf("You can move left. Enter 1 to move left: ");
 		scanf("%d", &e);
 	}
 	else if(right==0 && left==0 && down==1 && up==0)
 	{
 		printf("You can move up. Enter 1 to move up: ");
 		scanf("%d", &e);
 	}
 	else if(right==0 && left==0 && down==0 && up==1)
 	{
 		printf("You can move down. Enter 1 to move down:");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==1 && down==0 && up==0)
 	{
 		printf("You can move right and left. Enter 1 to move right or 2 to move left: ");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==0 && down==1 && up==0)
 	{
 		printf("You can move right and up. Enter 1 to move right or 2 to move up: ");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==0 && down==0 && up==1)
 	{
 		printf("You can move down and right. Enter 1 to move down or 2 to right up: ");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==1 && down==1 && up==0)
 	{
 		printf("You can move right, left and up. Enter 1 to move right, 2 to move left or 3 to move left: ");
 		scanf("%d", &e);
 	}
 	else if(right==0 && left==1 && down==1 && up==0)
 	{
		printf("You can move left and up. Enter 1 to move left or 2 to move up: ");
		scanf("%d", &e);
 	}
 	else if(right==0 && left==1 && down==1 && up==1)
 	{
 		printf("You can move left , up and down. Enter 1 to move left, 2 to move up or 3 to move down: ");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==1 && down==1 && up==1)
 	{
 		printf("You can move down, up, left and right. Enter 1 to move down, 2 to move up or 3 to move right: ");
 		scanf("%d", &e);
 	}
 	else if(right==0 && left==0 && down==0 && up==0)
 	{
 		printf("You can move nowhere");
 	}
 	else if(right==1 && left==0 && down==1 && up==1)
 	{
 		printf("You can move down, up and right. Enter 1 to move down, 2 to move up or to move right: ");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==1 && down==0 && up==1)
 	{
 		printf("You can move down, right and left. Enter 1 to move down, 2 to move right or 3 to move left: ");
 		scanf("%d", &e);
 	}
 	else if(right==0 && left==1 && down==0 && up==1)
 	{
 		printf("You can move down and left. Enter 1 to move down, 2 to move left: ");
 		scanf("%d", &e);
 	}
 	else if(right==1 && left==1 && down==1 && up==1)
 	{
 		printf("You can move up, down, left and right. Enter 1 to move up, 2 to move down, 3 to move left or 4 to move right: ");
 		scanf("%d", &e);
 	}

 	return e;
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








