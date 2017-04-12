

#include <stdio.h>
#include <stdlib.h>
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

void move(struct Players *Player)	//function to move players
 {
 	int right=0, left=0, down=0, up=0, e;
 	if(board[Player->PlaceRow][Player->PlaceColumn].column==BOARDSIZE-1)
 	{
 		right=1;
 	}
 	if(board[Player->PlaceRow][Player->PlaceColumn].column==0)
 	{
 		left=1;
 	}
 	if(board[Player->PlaceRow][Player->PlaceColumn].row==BOARDSIZE-1)
 	{
 		down=1;
 	}
 	if(board[Player->PlaceRow][Player->PlaceColumn].up==0)
 	{
 		up=1;
 	}

 	if(right==1)
 	{
 		printf("You can't move right.\n");
 	}
 	if(left==1)
 	{
 		printf("You can't move left.\n");
 	}
 	if(down==1)
 	{
 		printf("You can't move down.\n");
 	}
 	if(up==1)
 	{
 		printf("You can't move up.\n");
 	}

 	if(right==0)
 	{
 		printf("Enter 6 to move right\n");
 	}
 	if(left==0)
 	{
 		printf("Enter 4 to move left\n");
 	}
 	if(down==0)
 	{
 		printf("Enter 2 to move down\n");
 	}
 	if(up==0)
 	{
 		printf("Enter 8 to move up\n");
 	}

 	scanf("%d", &e);
 	getchar();
 	while(e!=2 && e!=4 && e!=6 && e!=8)
 	{
 		printf("Enter a valid number");
 		scanf("%d", &e);
 		getchar();
 	}

 	if(e==4 && Player->PlaceColumn!=0)
 	{
 		Player->PlaceColumn = Player->PlaceColumn - 1;
 	}
 	if(e==6 && Player->PlaceColumn!=(BOARDSIZE-1))
 	{
 		Player->PlaceColumn = Player->PlaceColumn + 1;
 	}
 	if(e==2 && Player->PlaceRow != (BOARDSIZE-1))
 	{
 		Player->PlaceRow = Player->PlaceRow + 1;
 	}
 	if(e==8 && Player->PlaceRow != 0)
 	{
 		Player->PlaceRow = Player->PlaceRow - 1;
 	}

 	printf("\nPlayer place is now (%d,%d)", Player->PlaceRow, Player->PlaceColumn);
 }



void turns(const int Player_Num)
{
	int turn, choice, attack_choice, abl[Player_Num];
	int k, j, i, count, distance, attack_player;
	enum dead status[6];
	int death = Player_Num;
	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARDSIZE][BOARDSIZE];


	while(death>1)
	{
	for(turn=0; turn<Player_Num; turn++) //move or attack
	{
		if(status[turn]!=dead && status[turn]!=quit)
		{
			//print stats after each player
<<<<<<< HEAD
			
=======
			for(j=0; j<Player_Num; j++)
			{
				if(status[j]==dead)
				{
					printf("\nPlayer %d is dead\n", j+1);
				}
				else  if(status[j]==quit)
				{
					printf("\nPlayer %d has quit\n", j+1);
				}
				else
				{
					printf("\n\nPlayer [%d]: %s"
							"Life Points %d\n"
							"Player Type: %s\n"
							"Strength: %d\n"
							"Magic: %d\n"
							"Dexterity: %d\n"
							"Luck: %d\n"
							"Smartness: %d\n",
							j+1, Player[j].Name,
							Player[j].LifePoints,
							Player[j].Race,
							Player[j].Strength,
							Player[j].MagicSkills,
							Player[j].Dexterity,
							Player[j].Luck,
							Player[j].Smartness);
				}
			}
>>>>>>> ff6aa76fac31a1d74e475927a7b6569eed77a09d
			printf("\n");

			//player[turn] choice - move or attack
			printf("\n%sDo you want to move or attack?\n"
					"Enter 1 to move or "
					"2 to attack or "
					"3 to quit the game\n", Player[turn].Name);
			scanf("%d", &choice);
			getchar();

			while(choice!=1 && choice!=2 && choice!=3)		//checks if choice is valid
			{
				printf("\n%d\n", choice);
				printf("This is not an option!!\n"
						"Enter 1 to move or "
						"2 to attack or"
						"3 to quit the game\n");
				scanf("%d", &choice);
				getchar();
			}

			//if move -> move function
			if(choice==1)
			{
				deboost(&Player[turn], &board[Player[turn].PlaceRow][Player[turn].PlaceColumn]);		//removes change of stats before moving
				move(&Player[turn]);	//moves player
				boost(&Player[turn], &board[Player[turn].PlaceRow][Player[turn].PlaceColumn]);		//changes stats according to type of slot
			}

			//if attack -> attack function
			if(choice==2)
			{
				if(Player[turn].Smartness+Player[turn].MagicSkills>150)
				{
					printf("Enter 1 for a near attack, "
							"2 for a distant attack or "
							"3 for a magic attack:");
					scanf("%d", &attack_choice);
					while(attack_choice!=1 && attack_choice!=2 && attack_choice!=3)
					{
						printf("That is not a valid input."
								"\nEnter 1 for a near attack, "
								"2 for a distant attack or "
								"3 for a magic attack:");
						scanf("%d", &attack_choice);
					}
				}
				else
				{
					printf("Enter 1 for a near attack or "
							"2 for a distant attack:");
					scanf("%d", &attack_choice);
					while(attack_choice!=1 && attack_choice!=2)
					{
						printf("That is not a valid input."
								"\nEnter 1 for a near attack or "
								"2 for a distant attack:");
						scanf("%d", &attack_choice);
					}
				}

				//need to find out who the attacked player is
				k=0;
				int u=0, l=0;
				if(attack_choice==1)
				{
					while(k<Player_Num)
					{
						abl[k]=0;
						k=k+1;
					}

					while(k<Player_Num)		//checks for the closest player
					{
						if(k!=turn)
						{
							if(Player[k].PlaceRow==Player[turn].PlaceRow && (Player[k].PlaceColumn==Player[turn].PlaceColumn || Player[k].PlaceColumn==Player[turn].PlaceColumn +1 || Player[k].PlaceColumn==Player[turn].PlaceColumn-1))
							{
								abl[k]=1;
								u=u+1;
								
							}
							else if(Player[k].PlaceColumn==Player[turn].PlaceColumn && (Player[k].PlaceRow==Player[turn].PlaceRow || Player[k].PlaceRow==Player[turn].PlaceRow+1 || Player[k].PlaceRow==Player[turn].PlaceRow-1))
							{
								abl[k]=1;
								u=u+1;
							}
						}
						k=k+1;
					}
					k=0;
					if(u>0)
					{
						printf("Your options are ");
						while(k<Player_Num)
					{
						if(abl[k]=1)
						{
							printf("P%d ", k+1);
						}
						k=k+1;
					}
					printf("Choose which player to attack P?");
					scanf("%d", &attack_player);
					while(abl[attack_player]<1)
					{
						printf("Choose which player to attack");
						scanf("%d", &attack_player);
					}
					nearattack(&Player[turn], &Player[attack_player-1]);
					}
					else
					{
						printf("There are no players for you to attack\n");
					}
					
				}

				if(attack_choice==2)													//distance attack
				{
					for(int i=0; i<BOARDSIZE; i++)
					{
						for(int j=0; j<BOARDSIZE;j++)
						{
							explored[i][j] = false;
						}
					}

					foundSlots = malloc(BOARDSIZE * BOARDSIZE * sizeof(struct slot ));

					if(currSlot!= NULL)
					{
						//invokes function findSlots. The required distance is a constant
						//However you can reuse this function providing as input any arbitrary distance
						for(distance=MIN_DISTANCE; distance<=MAX_DISTANCE; distance++)
						{
							findSlots(distance, 0, currSlot, foundSlots, &count, explored);
						}
					}
					printf("\nPlayers available to attack!!");
					for(int i=0; i<BOARDSIZE; i++)		//find players to attack
					{
						for(j=0; j<BOARDSIZE; j++)
						{
							for(k=0; k<Player_Num; k++)
							{
								if(explored[i][j]==true)
								{
									if(i==Player[k].PlaceRow && j==Player[k].PlaceColumn)
									{
										printf("You can attack Player %d, %s", k, Player[k].Name);
									}
								}
							}
						}
					}
					printf("Select one of these players to attack Player ?\n");
					scanf("%d", &attack_player);

					disattack(&Player[turn], &Player[attack_player]);

				}

				if(attack_choice==3)		//magic attack
				{
					for(int k=0; k<Player_Num; k++)
					{
						if(k!=turn)
						{
						
							printf("Choose a player to attack: \n"
								"P%d %s", k+1, Player[k].Name);
						}
					}
					scanf("%d", &attack_player);
					while(attack_player-1==turn || attack_player-1>Player_Num || attack_player<0 || status[attack_player-1]==dead )
					{
						printf("Choose a player to attack:");
						scanf("%d", &attack_player);
					}
					magicattack(&Player[turn], &Player[attack_player-1]);
				}

				l=0;
				while(l<Player_Num)					//errors here what is l
				{
					if(Player[l].LifePoints<=0)
					{
						if(status[l]!=dead)
						{
							status[l]= dead;
							death=death-1;
						}
					}
					l=l+1;
				}
			}
			if(choice==3)
			{
				status[turn]=quit;
				death=death-1;
			}
		}
	}
	//print stats after each player
	for(j=0; j<Player_Num; j++)
	{
		if(status[j]==dead)
		{
			printf("\nPlayer %d is dead\n", j+1);
		}
		else  if(status[j]==quit)
		{
			printf("\nPlayer %d has quit\n", j+1);
		}
		else
		{
<<<<<<< HEAD
			printf("\n\nPlayer [%d]: %s\n"
=======
			printf("\n\nPlayer [%d]: %s"
>>>>>>> ff6aa76fac31a1d74e475927a7b6569eed77a09d
					"Life Points %d\n"
					"Player Type: %s\n"
					"Strength: %d\n"
					"Magic: %d\n"
					"Dexterity: %d\n"
					"Luck: %d\n"
					"Smartness: %d\n",
					j+1, Player[j].Name,
					Player[j].LifePoints,
					Player[j].Race,
					Player[j].Strength,
					Player[j].MagicSkills,
					Player[j].Dexterity,
					Player[j].Luck,
					Player[j].Smartness);
		}
	}
	printf("\n");
	for(i=0; i<BOARDSIZE; i++)
	{
		for(j=0; j<BOARDSIZE; j++)
		{
			for(k=0; k<Player_Num; k++)
			{
				if((board[i][j].row == Player[k].PlaceRow && board[i][j].column == Player[k].PlaceColumn) && (status[k]!=quit || status[k]!=dead))
				{
					printf("P%d\t", k+1);
				}
				else
				{
					printf("_\t");
				}
			}
		}
		printf("\n");
	}
}
}
