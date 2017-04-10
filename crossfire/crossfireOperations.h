/*
 * crossfireOperations.h
 *
 *  Created on: 31 Mar 2017
 *      Author: Órla
 */

#ifndef CROSSFIREOPERATIONS_H_
#define CROSSFIREOPERATIONS_H_
#define BOARDSIZE 7
#define REQ_DISTANCE 3

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
}board[BOARDSIZE][BOARDSIZE];

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
   int	 PlaceRow;
   int	 PlaceColumn;
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
void createBoard(struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight);
//Asks the user to insert the row and the column of the element
//she wants to find given a board of size equal to maxsize
void getDesiredElement(int maxsize, int * row, int * col);

/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column)
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot *  reachDesiredElement(int row, int column, struct slot * initialSlot);

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
void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[7][7]);



int PlayerData();
void boost(struct Players *Player, struct slot *board);		//changing stats depending on slot type
void deboost();	//removing stats when player moves off some slot types
void type(struct Players *Player);		//give player a type
void stat(struct Players *Player);		//give player stats
void selectNumSlots(int *slot_noPtr, int PlayerNumber);		//select number of slots
int assignSlots();				//put ground type on slots
void attack(struct Players *attacker, struct Players *attacked);			//attack function
int move(struct Players *Player, int x, int playernumber, int slotnum);		//function to move players
void assignPlace(const int Player_Num);	//place players on slots

void BoardType();
void magicattack(struct Players *attacker, struct Players *attacked);
void disattack(struct Players *attacker, struct Players *attacked);

