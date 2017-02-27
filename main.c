/*
 * main.c
 *
 *  Created on: 26 Feb 2017
 *      Authors: Fionan, Mark
 *      Temporary main function
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h" //header file containing function prototypes

int main (void)
{
	setbuf(stdout, NULL); //for scanf to work properly
	int numofplayers=10;
	int numofslots;

	do{
	printf("How many people are playing?\n");
	scanf("%d", &numofplayers);
	}while(numofplayers<1 || numofplayers > MAXPLAYERS); //Ensures a valid input

//    int a; //Counter
//   /*Initialize the stats of each player: */
//    for(a = 0; a < numofplayers; a++)
//     {
//
//            	 strcpy(player[a].name,"bob");// The player's name
//            	 player[a].class='E'; //The player type (can be 'O', 'H', 'W' or 'E')
//            	 player[a].hp=120; //Each player's life points
//            	 player[a].smartness=100;
//            	 player[a].strength=100;
//            	 player[a].magic=100;
//            	 player[a].luck=100;
//            	 player[a].dexterity=100;
//
//
//     }


	/*Initialize the slots function: */
	slotsfunction(numofplayers, &numofslots); //Note: We are passing numofslots into the slots function by reference

	move(numofplayers, numofslots); //Note: Since numofslots is not being altered in this function, we are passing it be value this time.

	return 0;
}

