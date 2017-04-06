#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Slots
{
	int place;
	char type[7];
};

struct Players
{
   char  Name[25];
   char  Race[7];
   int   Strength;
   int   MagicSkills;
   int	 Dexterity;
   int   Luck;
   int	 Smartness;
   int	 LifePoints;
   int	 Place;
};

void boost(struct Players *Player, struct Slots *slot);		//changing stats depending on slot type
void deboost(struct Players *Player, struct Slots *slot);	//removing stats when player moves off some slot types
void type(struct Players *Player);		//give player a type
void stat(struct Players *Player);		//give player stats
void selectNumSlots(int *slot_noPtr, int PlayerNumber);		//select number of slots
void assignSlots(struct Slots *slot, int i);				//put ground type on slots
void attack(struct Players *attacker, struct Players *attacked);			//attack function
int move(struct Players *Player, int x, int playernumber, int slotnum);		//function to move players
void assignPlace(struct Players *Player, int SlotNumber);	//place players on slots

int main(void)
{
	srand(time(NULL));

	int PlayerNum, j, slot_no, i, choice, max, v=0, second, r=0, k, l, dif, counter=0, atk=0;
	struct Players Player[6];
	struct Slots slot[7][7];

	//pick between 2 and 6
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
		printf( "\nPlayer [%d]: %sPlayer Type: %s\nStrength: %d\nMagic: %d\nDexterity: %d\nLuck: %d\nSmartness: %d\n", j+1, Player[j].Name, Player[j].Race, Player[j].Strength, Player[j].MagicSkills, Player[j].Dexterity, Player[j].Luck, Player[j].Smartness);
	}
	printf("\n");
	
	//calls function for placing random types on slots
	i=0;
	while( i<7)
	{ j=0;
		while(j<7)
		{
		assignSlots(&slot[i][j], i);
		printf("%d %d: %s\n", i, j, slot[i][j].type);
		j=j+1;
		}
		i=i+1;
	}


	/*for(i=0; i<PlayerNum; i++)	//assign players to slots
	{
		assignPlace(&Player[i], slot_no); 
		for(j=0; j<i; j++)			//if there is already a player in this place i decrements and slot is assigned again
		{
			if(Player[i].Place==Player[j].Place)
			{
				i--;
			}
		}
		//boost(&Player[i], &slot[Player[i].Place-1]);		//boosts are assigned to players if they are on hill or city, it's player.Place-1 because
	}														//display starts at 1 while the struct arrays start at 0

	/*for(j=0; j<slot_no; j++)	//prints out player positions
	{
		for(k=0; k<PlayerNum; k++)
		{
			if(slot[j].place==Player[k].Place)
			{
				printf("P%d   ", k+1);
			}
			else
			{
				counter++;
			}
			if(counter==PlayerNum)
			{
				printf("_   ");
			}
		}
		counter=0;
	}*/

	/*for(i=0; i<PlayerNum; i++) //move or attack
	{
		//player[i] choice - move or attack
		printf("\n%sDo you want to move or attack?\nEnter 1 to move or 2 to attack\n", Player[i].Name);
		scanf("%d", &choice);
		getchar();
		
		while(choice!=1 && choice!=2)		//checks if choice is valid
		{
			printf("\n%d\n", choice);
			printf("This is not an option!!\nEnter 1 to move or 2 to attack");
			scanf("%d", &choice);
			getchar();
		}

		//if move -> move function
		/*if(choice==1)
		{
			deboost(&Player[i], &slot[Player[i].Place-1]);		//removes change of stats before moving
			choice = move(&Player[0], i, PlayerNum, slot_no);	//moves player
			boost(&Player[i], &slot[Player[i].Place-1]);		//changes stats according to type of slot
		}*/

		//if attack -> attack function
		/*if(choice==2)
		{
			if(Player[i].Smartness+Player[i].MagicSkills>150)
			{
				printf("Enter 1 for a near attack, 2 for a distant attack or 3 for a magic attack:");
				scanf("%d", &atk);
				while(atk!=1 || atk!=2 || atk!=3)
				{
					printf("That is not a valid input. \nEnter 1 for a near attack, 2 for a distant attack or 3 for a magic attack:");
					scanf("%d", &attack);
				}
			}
			else
			{
				printf("Enter 1 for a near attack or 2 for a distant attack:");
				scanf("%d", &atk);
				while(atk!=1 || atk!=2)
				{
					printf("That is not a valid input. \nEnter 1 for a near attack or 2 for a distant attack:");
					scanf("%d", &atk);
				}
			}
			//need to find out who the attacked player is
			max=100, second=99, k=0;
			if(atk==1)
			{
			while(k<PlayerNum)		//checks for the closest player
			{
				dif=Player[i].Place-Player[k].Place;
				if(dif<0)
				{
					dif=-(dif);
				}

				if(dif<max && dif>0)
				{
					v=k;
					max=dif;
				}
				else if(dif==max)
				{
					second=max;
					r=k;
				}
				k=k+1;
			}

			if(max!=second)		//calls attack function if there is one closest player
			{
				attack(&Player[i], &Player[v]);
			}
			if(max==second)		//if there is two players near by this gives the option of which to choose
			{
				printf("\nEnter:\n1 to attack %s2 to attack %s", Player[r].Name, Player[v].Name);
				scanf("%d", &l);
				getchar();
				
				while(l!=1 && l!=2)	//check if user entered a given option
				{
					printf("Please enter a valid number: \n");
					scanf("%d", &l);
					getchar();
				}
				if(l==1)
				{
					attack(&Player[i], &Player[r]);
				}
				if(l==2)
				{
					attack(&Player[i], &Player[v]);
				}
			}
		}
		}
		//print stats after each player
		for(j=0; j<PlayerNum; j++)
		{
			printf("\nP%d:%s(%s, %d)\n", j+1, Player[j].Name, Player[j].Race, Player[j].LifePoints);
		}
		printf("\n");
		
		/*for(j=0; j<slot_no; j++)
		{
			for(k=0; k<PlayerNum; k++)
			{
				if(slot[j].place==Player[k].Place)
				{
					printf("P%d   ", k+1);
				}
				else
				{
					counter++;
				}
				if(counter==PlayerNum)
				{
					printf("_   ");
				}
			}
			counter=0;
		}*/
	//}
	return 0;
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

void selectNumSlots(int *slot_noPtr, int PlayerNumber)	//function to select the number of slots
{

	printf("\nSelect the amount of slots in the game\nThis number must be between %d and 20: ", PlayerNumber);
	scanf("%d", &*slot_noPtr);
	getchar();
	return;
}

void assignSlots(struct Slots *slot, int i)		//slot ground type function
{
	int random=0;
	
	slot->place=1;		//give value of 1 to slot number on slots for display
	
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

void assignPlace(struct Players *Player, int SlotNumber)	//assign players to slots
{
	int random;

	//places players on slots
	random=1+rand()%SlotNumber; //gives a random number between 1 and slotnumber
	
	Player->Place = random;
}

int move(struct Players *Player, int x, int playernumber, int slotnum)		//move function
{
	int l=0, right=0, left=0, c;
	while(l<playernumber)	//cycles through other players
	{

		if((Player[x].Place+1==Player[l].Place || Player[x].Place==slotnum) && right==0)	//checks, if a player is to the right and if its the end of 
		{																				//the slots also only lets this if statement to run once
			printf("You can't move forward.\n");
			right++;
		}
		if((Player[x].Place-1==Player[l].Place || Player[x].Place==1) && left==0)		//checks if a player is to the left, if it's the starting slot
		{																				// will also only let this if statement to run once
			printf("You can't move backwards.\n");
			left++;
		}
		l++;
	}
	if(right<1&&left<1)		//if a player can move either way
	{
		printf("Enter 1 to move backwards or 2 to move forwards: ");
		scanf("%d", &c);
		getchar();

		if(c==1)	//if they choose to move back a slot
		{
			Player[x].Place=Player[x].Place-1;
		}
		if(c==2)	//if they choose to move forward a slot
		{
			Player[x].Place=Player[x].Place+1;
		}
		return 1;		//they get to move so choice stays the same
	}
	else if(right<1 && left>0)	//if there is a player or no slot behind the player
	{
		printf("Enter 2 to move forward: ");
		scanf("%d", &c);
		getchar();

		if(c==2)
		{
			Player[x].Place=Player[x].Place+1;
		}
		return 1;		//they get to move so choice stays the same
	}
	else if(right>0 && left<1)	//if there is a player or end of slots infront of the player
	{
		printf("Enter 1 to move backwards: ");
		scanf("%d", &c);
		getchar();

		if(c==1)
		{
			Player[x].Place=Player[x].Place-1;
		}
		return 1;		//choice stays the same
	}
	else if(right>0 && left>0) //if they are unable to move
	{
		printf("You are unable to move\nYou can still attack!!!");
		printf("\nDo you want to attack?\nEnter 1 for no 2 for yes: ");	//they have a choice attack or skip their turn
		scanf("%d", &c);
		getchar();

		if(c==1)	//if c is 1 then skip their turn and return 1
		{
			return 1;
		}
		if(c==2)	//if c is 2 then they want to attack and 2 is returned to choice
		{
			return 2;
		}
	}
}

 void boost(struct Players *Player, struct Slots *slot)	//gives extra stats depending on slot type (hill and city)
{
	if(strcmp(slot->type, "Hill")==0)
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
	if(strcmp(slot->type, "City")==0)
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

void deboost(struct Players *Player, struct Slots *slot)	//when moving off a slot takes away given stats and returns them to what was given at start
{
	if(strcmp(slot->type, "Hill")==0)
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
	if(strcmp(slot->type, "City")==0)
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
void magattack(struct Players *attacker, struct Players *attacked)		//magic attack function
{
	attacked->LifePoints=attacked->LifePoints - ((0.3*attacker->MagicSkills)+(0.2*attacker->Smartness));
}