
/* * Players.c
 *
 *  Created on: 31 Mar 2017
 *      Author: Órla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crossfireOperations.h"

void PlayerData()
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
		return;
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

