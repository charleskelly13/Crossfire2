
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crossfireOperations.h"



int main()
{
	srand(time(NULL));
	int Player_Num, count=0, i, j, choice, max, v=0, second, r=0, k, l, dif, counter=0, atk;
	enum dead status[6];
	setvbuf(stdout, 0, _IONBF, 0);
	Player_Num = InputPlayers();
	int death = Player_Num;

	int row, column;

	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARDSIZE][BOARDSIZE];

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;


	//Creates the board

	createBoard(&upLeft, &upRight, &downLeft, &downRight);
	BoardType();
	assignPlace(Player_Num);

	for(i=0; i<Player_Num; i++)
	{
		boost(&Player[i], &board[Player->PlaceRow][Player->PlaceColumn]);
	}

	//turns
	//	->call attack
	//			->which attack
	//	->move
	//	->quit
	for(i=0; i<Player_Num && death>1 ; i++) //move or attack
		{
			if(status[i]!=dead && status[i]!=quit)
			{


			//player[i] choice - move or attack
			printf("\n%sDo you want to move or attack?\n"
					"Enter 1 to move or "
					"2 to attack or "
					"3 to quit the game\n", Player[i].Name);
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
				deboost();		//removes change of stats before moving
				choice = move();	//moves player
				boost();		//changes stats according to type of slot
			}

			//if attack -> attack function
			if(choice==2)
			{
				if(Player[i].Smartness+Player[i].MagicSkills>150)
				{
					printf("Enter 1 for a near attack, 2 for a distant attack or 3 for a magic attack:");
					scanf("%d", &atk);
					while(atk!=1 && atk!=2 && atk!=3)
					{
						printf("That is not a valid input. \nEnter 1 for a near attack, 2 for a distant attack or 3 for a magic attack:");
						scanf("%d", &atk);
					}
				}
				else
				{
					printf("Enter 1 for a near attack or 2 for a distant attack:");
					scanf("%d", &atk);
					while(atk!=1 && atk!=2)
					{
						printf("That is not a valid input. \nEnter 1 for a near attack or 2 for a distant attack:");
						scanf("%d", &atk);
					}
				}
				//need to find out who the attacked player is
				max=100, second=99, k=0;
				if(atk==1)
				{
				while(k<Player_Num)		//checks for the closest player
				{
					if(status[k]!=dead)
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
					}
					k=k+1;
				}

				if(max!=second)		//calls attack function if there is one closest player
				{
					nearattack(&Player[i], &Player[v]);
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
			if(atk==3)		//magic attack
				{
					int p=0;
					printf("Choose a player to attack:");
					scanf("%d", &p);
					while(p-1==i || p-1>Player_Num || p<0 || status[p-1]==dead)
					{
						printf("Choose a player to attack:");
						scanf("%d", &p);
					}
					magicattack(&Player[i], &Player[p-1]);
				}
				l=0;
				while(l<Player_Num)
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
			}
			if(choice==3)
			{
				status[i]=quit;
				death=death-1;
			}
			//print stats after each player
			for(j=0; j<Player_Num; j++)
			{
				if(status[j]==dead)
				{
					printf("\n Player %d is dead\n", j+1);
				}
				else  if(status[j]==quit)
				{
					printf("\n Player %d has quit\n", j+1);
				}
				else
				{
				printf("\nP%d:%s(%s, %d)\n", j+1, Player[j].Name, Player[j].Race, Player[j].LifePoints);
				}
			}
			printf("\n");


/*			for(j=0; j<slot_no; j++)
			{
				for(k=0; k<PlayerNum; k++)
				{
					if(slot[j].place==Player[k].Place && status[k]!=quit && status[k]!=dead)
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
		}







	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= BOARDSIZE/2)
	{
		if(column >= BOARDSIZE/2)													//forget about downright etc
		{																			//starts in player position
			currSlot = reachDesiredElement(row,column,downRight);					//
		}
		else
		{
			/*If the the required slot is closer to the down-left
			 * corner of the board the search starts from downLeft,
			 * which points to slot at position (boardSize-1, 0)*/
			currSlot = reachDesiredElement(row,column,downLeft);
		}
	}
	else
	{
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (0, boarSize -1)*/
		if(column >= BOARDSIZE/2)
		{
			currSlot = reachDesiredElement(row,column, upRight);
			/*If the the required slot is closer to the up-left
			* corner of the board the search starts from upLeft,
			* which points to slot at position (0, 0)*/
		}
		else
		{
			currSlot = reachDesiredElement(row,column,upLeft);
		}
	}

	for(int i=0; i<BOARDSIZE; i++)
	{
		for(int j=0; j<BOARDSIZE;j++)
		{
			explored[i][j] = false;
		}
	}

	foundSlots = malloc(BOARDSIZE * BOARDSIZE * sizeof(struct slot ));
	printf("\n\nFunction findSlotsinvoked:\n");

	if(currSlot!= NULL)
	{
		//invokes function findSlots. The required distance is a constant
		//However you can reuse this function providing as input any arbitrary distance
		findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
		for(int i=0; i<count; i++)
		{
			printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
		}
	}

	return 0;
}
