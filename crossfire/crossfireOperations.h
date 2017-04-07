/*
 * crossfireOperations.h
 *
 *  Created on: 31 Mar 2017
 *      Author: Órla
 */

#ifndef CROSSFIREOPERATIONS_H_
#define CROSSFIREOPERATIONS_H_



#endif /* CROSSFIREOPERATIONS_H_ */


/*
 * Definition of boolean types
 * This avoids using <stdbool.h>
 */
typedef int bool;
enum { false, true };

struct slot{
	//row number
	int row;
	//column number
	int column;
	//type of slot city, ground, hill
	char type;

	// adjacent left slot
	struct slot *left;
	// adjacent right slot
	struct slot *right;
	// adjacent up slot
	struct slot *up;
	// adjacent down slot
	struct slot *down;
}slot[7][7];

struct Players	//struct for players
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
}Player[6];

/*
 * FUNCTIONS PROTOTYPES
 */

/*
 * This function creates the board
 * Parameters:
 * 	boardSize: the size of the board
 * 	upLeft: pointer of pointer to slot at position (0, 0)
 * 	upRight: pointer of pointer to slot at position (0, size -1)
 * 	downLeft: pointer of pointer to slot at position (size -1, 0)
 * 	upLeft: pointer of pointer to slot at position (size - 1, size -1)
 */
void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight);


void PlayerData();
void boost(struct Players *Player, struct slot *slot);		//changing stats depending on slot type
void deboost(struct Players *Player, struct slot *slot);	//removing stats when player moves off some slot types
void type(struct Players *Player);		//give player a type
void stat(struct Players *Player);		//give player stats
void selectNumSlots(int *slot_noPtr, int PlayerNumber);		//select number of slots
void assignSlots(struct slot *slot, int i, int j);				//put ground type on slots
void attack(struct Players *attacker, struct Players *attacked);			//attack function
int move(struct Players *Player, int x, int playernumber, int slotnum);		//function to move players
void assignPlace(struct Players *Player, int SlotNumber);	//place players on slots

void BoardType(const int boardSize, struct slot *slot);

