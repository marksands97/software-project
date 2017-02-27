/*
 * operations.h
 *
 *  Created on: 26 Feb 2017
 *  Author: Fionan(16360121), Mark()
 *  Header file containing function prototypes
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#define MAXNAMELEN 25//Max length of a player's name
#define MAXSLOTS 20 //Max number of slots
#define MAXPLAYERS 6//Max number of players

typedef struct Stats //Declare a new structure containing the stats for all players
{
char name[MAXNAMELEN];// The player's name
char class; //The player type (can be 'O', 'H', 'W' or 'E')
int hp; //Each player's life points
int smartness;
int strength;
int magic;
int luck;
int dexterity;
int currentslot;
}Stats;


typedef struct Slotstruct //Declare a new structure containing the stats for all players
{
  char slottype[6]; //Slot type (Ground, City or Hill) for each slot
  int full; //Boolean array to track which slot positions are full (1 = full, 0 = empty)
  int currentplayer; //The player number (between 0 and numofplayers) that is currently occupying this slot
}Slotstruct;

Stats player[MAXPLAYERS]; //Declare the players (each of which is of type Stats)
Slotstruct slot[MAXSLOTS];//Declare the slots

void slotsfunction(int numofplayers, int *numofslots);
void move(int numofplayers, int numofslots);

#endif /* OPERATIONS_H_ */
