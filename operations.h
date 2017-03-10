#ifndef OPERATIONS_H_
#define OPERATIONS_H_
 
#define MAXNAMELEN 25//Max length of a player's name
#define MAXPLAYERS 6//Max number of players
#define MAXSLOTS 20 //Max number of slots
 
struct Characters //Declare a new structure containing the stats for all players
{
 
char class[MAXNAMELEN]; //The player type
float life; //Each player's life points
char name[MAXNAMELEN];// The player's name
int smartness;
int strength;
int magic;
int luck;
int dexterity;
int currentslot;
int data;
struct Characters *next;
}players[1]; //Declare the array, players (initialize as being of size 1, but then dynamically expand this size later)
 
 
struct Slotstruct //Declare a new structure containing the stats for all players
{
  char slottype[6]; //Slot type (Ground, City or Hill) for each slot
  int full; //Boolean array to track which slot positions are full (1 = full, 0 = empty)
  int currentplayer; //The player number (between 0 and numofplayers) that is currently occupying this slot
  int data;
  struct Slotstruct *next;
}slot[1];
 
 
//FUNCTION PROTOTYPES:
void slotsfunction(int numofplayers, int *numofslots);
void move(int numofplayers, int numofslots);
void printboard(int numofslots);
void attack(int numofplayers, int numofslots, int enemyposition, int attackerposition);
void abilities (int numofplayers, int i);
 
#endif /* OPERATIONS_H_ */