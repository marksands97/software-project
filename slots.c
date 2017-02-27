/*
 * slots.c
 *
 *  Created on: 23 Feb 2017
 *      Author: Fionan(16360121), Mark
 *      Function to create the slots and then assign players to the appropriate slot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"

void slotsfunction(int numofplayers, int *numofslots)
{

	int i; //Counter
	int dice; //Used when we need a random number

	setbuf(stdout, NULL);//For scanf to function properly
	srand(time(NULL)); //Seed the random number generator

	do{
	printf("Enter the number of slots (%d - %d):\n", numofplayers, MAXSLOTS);
	scanf("%d", &*numofslots);
	}while(*numofslots<numofplayers||*numofslots>MAXSLOTS); //Ensure a valid input

	int rowNum=0;


	/*Randomly set the type of each slot:*/
	while(rowNum<*numofslots)
	{
		dice = rand() % 3; //Roll the imaginary 3 sided dice (or die)

		if(dice==0)
		  strcpy(slot[rowNum].slottype,"Ground");
		else if(dice==1)
		   strcpy(slot[rowNum].slottype,"Hill");
		else if(dice==2)
		  strcpy(slot[rowNum].slottype,"City");
		printf("\nSlot %d: %s",rowNum+1, slot[rowNum].slottype);
		rowNum++;
	}


    for(i=0;i<*numofslots;i++)
    {
     slot[i].full=0; //Initialize all values to 0
    }

    int placed=0; //Boolean value to determine whether a player has been placed

    for(i=0;i<numofplayers;i++)//Go through each player (0 to numofplayers)
    {
      while(placed == 0)//While the player has not been placed
      {
    	dice = rand() % *numofslots; //Go to a random slot

       if (slot[dice].full==0)//If the current slot is empty
        {
    	  slot[dice].currentplayer=i; //Assign the slot with a player
    	  player[i].currentslot=dice; //Assign the player with a slot
    	  slot[dice].full = 1; //Mark that this slot is full
    	  placed = 1; //Placed = true
        }
      }
    placed = 0; //reset placed back to 0/false
    }

    for(i=0;i<*numofslots;i++)
     {
     if (slot[i].full==1) //If the slot has someone on it
    	printf("\nSlot #%d has player #%d on it.",i+1, slot[i].currentplayer+1);
     }

}

