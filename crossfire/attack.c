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
