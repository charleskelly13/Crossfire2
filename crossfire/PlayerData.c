
/* * Players.c
 *
 *  Created on: 31 Mar 2017
 *      Author: �rla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "crossfireOperations.h"

int move(struct Players *Player, int x, int playernumber, struct Slots *slot)	//function to move players
{
	int a=0, b=0, c=0, d=0, e=0;
	if(slot[Player->PlaceRow][column+1]!=NULL)
	{
		a=1;
	}
	if(slot[Player->PlaceRow][column-1]!=NULL)
	{
		b=1;
	}
	if(slot[Player->PlaceRow+1][column]!=NULL)
	{
		c=1;
	}
	if(slot[Player->PlaceRow-1][column]!=NULL)
	{
		d=1;
	}
	
	if(a==1 && b==0 && c==0 && d==0)
	{
		printf("You can move right. Enter 1 to move right: ");
		scanf("%d", &e);
		if(e==1)
		{
			column=column+1;
		}
	}
	else if(a==0 && b==1 && c==0 && d==0)
	{
		printf("You can move left. Enter 1 to move left: ");
		scanf("%d", &e);
	}
	else if(a==0 && b==0 && c==1 && d==0)
	{
		printf("You can move up. Enter 1 to move up: ");
		scanf("%d", &e);
		if(e==1)
		{
			Player->PlaceRow=Player->PlaceRow+1;
		}
	}
	else if(a==0 && b==0 && c==0 && d==1)
	{
		printf("You can move down. Enter 1 to move down:");
		scanf("%d", &e);
		if(e==1)
		{
			Player->PlaceRow=Player->PlaceRow+1;
		}
	}
	else if(a==1 && b==1 && c==0 && d==0)
	{
		printf("You can move right and left. Enter 1 to move right or 2 to move left: ");
		scanf("%d", &e);
		if(e==1)
		{
			
		}
		if(e==2)
		{
			
		}
	}
	else if(a==1 && b==0 && c==1 && d==0)
	{
		printf("You can move right and up. Enter 1 to move right or 2 to move up: ");
		scanf("%d", &e);
	}
	else if(a==1 && b==0 && c==0 && d==1)
	{
		printf("You can move down and right. Enter 1 to move down or 2 to right up: ");
		scanf("%d", &e);
	}
	else if(a==1 && b==1 && c==1 && d==0)
	{
		printf("You can move right, left and up. Enter 1 to move right, 2 to move left or 3 to move left: ");
		scanf("%d", &e);
	}
	else if(a==0 && b==1 && c==1 && d==0)
	{
		printf("You can move left and up. Enter 1 to move left or 2 to move up: ");
		scanf("%d", &e);
	}
	else if(a==0 && b==1 && c==1 && d==1)
	{
		printf("You can move left , up and down. Enter 1 to move left, 2 to move up or 3 to move down: ");
		scanf("%d", &e);
	}
	else if(a==1 && b==1 && c==1 && d==1)
	{
		printf("You can move down, up, left and right. Enter 1 to move down, 2 to move up or 3 to move right: ");
		scanf("%d", &e);
	}
	else if(a==0 && b==0 && c==0 && d==0)
	{
		printf("You can move nowhere");
	}
	else if(a==1 && b==0 && c==1 && d==1)
	{
		printf("You can move down, up and right. Enter 1 to move down, 2 to move up or to move right: ");
		scanf("%d", &e);
	}
	else if(a==1 && b==1 && c==0 && d==1)
	{
		printf("You can move down, right and left. Enter 1 to move down, 2 to move right or 3 to move left: ");
		scanf("%d", &e);
	}
	else if(a==0 && b==1 && c==0 && d==1)
	{
		printf("You can move down and left. Enter 1 to move down, 2 to move left: ");
		scanf("%d", &e);
	}
	else if(a==1 && b==1 && c==1 && d==1)
	{
		printf("You can move up, down, left and right. Enter 1 to move up, 2 to move down, 3 to move left or 4 to move right: ");
		scanf("%d", &e);
	}
}

void type(struct Players *Player) //player type function
{
	char cho='y';
	while(cho!='W')	//checks if the option is valid
	{
		printf("Enter W for Wizard, O for Ogre, E for Elf or H for Human: ");
		scanf("%c", &cho);
		getchar();
		if(cho =='W' || cho =='w' || cho =='H' || cho =='h' || cho =='E' || cho =='e' || cho =='O' || cho =='o')
			break;
	}

	if(cho=='W' || cho=='w')
	{
		strcpy(Player->Race, "Wizard");
	}
	if(cho=='H' || cho=='h')
	{
		strcpy(Player->Race, "Human");
	}
	if(cho=='E' || cho=='e')
	{
		strcpy(Player->Race, "Elf");
	}
	if(cho=='O' || cho=='o')
	{
		strcpy(Player->Race, "Ogre");
	}
	return;
}

void stat(struct Players *Player)		//player stat function
{
	Player->LifePoints = 100;	//all players lifepoints are set to 100

	if(strcmp(Player->Race, "Ogre")==0)		//min+rand()%(max+1-min)
	{
		Player->Strength= 80+rand()%21;				//[80,100]
		Player->MagicSkills= 0;						//0
		Player->Dexterity= 80+rand()%21;			//[80,100]
		Player->Luck= rand()%51;					//[0,50]
		Player->Smartness= rand()%21;				//[0,20]
		while(Player->Luck+Player->Smartness>=50)	//condition to check if luck + smartness is over 50
		{
			Player->Luck= rand()%51;
			Player->Smartness= rand()%21;
		}
	}

	if(strcmp(Player->Race, "Human")==0)	//all can be [1,100]
	{
		Player->Strength= 1+rand()%100;
		Player->MagicSkills= 1+rand()%100;
		Player->Dexterity= 1+rand()%100;
		Player->Luck= 1+rand()%100;
		Player->Smartness= 1+rand()%100;
		while(Player->Strength+Player->Dexterity+Player->MagicSkills+Player->Luck+Player->Smartness >=300) //check if sum total is over 300
		{
			Player->Strength= 1+rand()%100;
			Player->MagicSkills= 1+rand()%100;
			Player->Dexterity= 1+rand()%100;
			Player->Luck= 1+rand()%100;
			Player->Smartness= 1+rand()%100;
		}
	}

	if(strcmp(Player->Race, "Elf")==0)
	{
		Player->Strength= 1+rand()%50;		//[1,50]
		Player->MagicSkills=51+rand()%29;	//(50,80)
		Player->Dexterity= 1+rand()%100;	//[1,100]
		Player->Luck= 60+rand()%41;			//[60,100]
		Player->Smartness= 70+rand()%31;	//[70,100]
	}

	if(strcmp(Player->Race, "Wizard")==0)
	{
		Player->Strength= 1+rand()%20;		//[1,20]
		Player->MagicSkills= 80+rand()%21;	//[80,100]
		Player->Dexterity= 1+rand()%100;	//[1,100]
		Player->Luck= 50+rand()%51;			//[50,100]
		Player->Smartness= 90+rand()%11;	//[80,100]
	}

	return;
}

void assignPlace(const int Player_Num)
{
	srand(time(NULL));
	int i, a, b;

	for(i=0; i<Player_Num; i++)
	{
		a = rand()%BOARDSIZE;
		b = rand()%BOARDSIZE;
		Player[i].PlaceRow = a;
		Player[i].PlaceColumn = b;
		printf("\n%s"
				"Is on row=%d, "
				"column=%d ,"
				"which is %s\n",
				Player[i].Name,
				Player[i].PlaceRow,
				Player[i].PlaceColumn,
				&board[Player[i].PlaceRow][Player[i].PlaceColumn].type);
	}
}

void boost(struct Players *Player, struct slot *board)
{
	if(strcmp(&board->type, "Hill")==0)
		{
			if(Player->Dexterity >= 60)		//If Dexterity >= 60, then the player gains 10 Strength points
			{
				Player->Strength = Player->Strength + 10;
			}
			if(Player->Dexterity < 50)		//If Dexterity < 50, then the player loses 10 Strength points
			{
				Player->Strength = Player->Strength - 10;
			}
		}
		if(strcmp(&board->type, "City")==0)
		{
			if(Player->Smartness > 60)		//If Smartness > 60, then the player gains 10 Magic Skills points
			{
				Player->MagicSkills = Player->MagicSkills + 10;
			}
			if(Player->Smartness <= 50)		//If Smartness <=50, then the player loses 10 Dexterity points.
			{
				Player->Dexterity = Player->Dexterity - 10;
			}
		}
		if(Player->MagicSkills > 100)
		{
			Player->MagicSkills = 100;
		}
		if(Player->Strength > 100)
		{
			Player->Strength = 100;
		}
		if(Player->Dexterity > 100)
		{
			Player->Dexterity = 100;
		}
		if(Player->Dexterity < 0)
		{
			Player->Dexterity = 0;
		}
		if(Player->Strength < 0)
		{
			Player->Strength = 0;
		}
}

void deboost(struct Players *Player, struct slot *board)	//when moving off a slot takes away given stats and returns them to what was given at start
{
	if(strcmp(&board->type, "Hill")==0)
	{
		if(Player->Dexterity >= 60)
		{
			Player->Strength = Player->Strength - 10;
		}
		if(Player->Dexterity < 50)
		{
			Player->Strength = Player->Strength + 10;
		}
	}
	if(strcmp(&board->type, "City")==0)
	{
		if(Player->Smartness > 60)
		{
			Player->MagicSkills = Player->MagicSkills - 10;
		}
		if(Player->Smartness <= 50)
		{
			Player->Dexterity = Player->Dexterity + 10;
		}
	}
	if(Player->MagicSkills > 100)
	{
		Player->MagicSkills = 100;
	}
	if(Player->Strength > 100)
	{
		Player->Strength = 100;
	}
	if(Player->Dexterity > 100)
	{
		Player->Dexterity = 100;
	}
	if(Player->Dexterity < 0)
	{
		Player->Dexterity = 0;
	}
	if(Player->Strength < 0)
	{
		Player->Strength = 0;
	}
}
