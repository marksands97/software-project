/*
 * move.c
 *
 *  Created on: 23 Feb 2017
 *      Author: Fionan(16360121), Mark
 *      Function which will as the user whether they wish to move left, right or attack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"

void move(int numofplayers, int numofslots)
{
  int i;
  int choice;

  for (i=0; i<numofplayers; i++)//Go through each of the players
  {
	 printf("\n\nPlayer #%d, please select your option:\n", i);
	 printf("1. Move one slot to the left");
	 printf("2. Move one slot to the right");
	 printf("3. Attack the nearest player");

	 scanf("%d", &choice);

	 switch(choice)
	 {
	   case 1://Left
	   {
		if(player[i].currentslot==0|| slot[player[i].currentslot-1].full == 1) //If this player is in the first position or the previous slot is full
		{
			printf("Player #%d cannot move left! Try again", i);
			i--; //Ask player[i] for their choice again
		}
		else
		  {
			slot[player[i].currentslot].full = 0;//The current slot will be empty now
			slot[player[i].currentslot-11].full = 1; //The previous slot will be full now

			player[i].currentslot--; //Move the player down one
		  }
		break;
	   }


	   case 2://Right
	   {
		if(player[i].currentslot==numofslots-1 || slot[player[i].currentslot+1].full == 1) //If this player is in the last position or the next spot is full
		  {
			printf("Player #%d cannot move right! Try again", i);
			i--; //Ask player[i] for their choice again
		  }
		else
		  {
			slot[player[i].currentslot].full = 0;//The current slot will be empty now
			slot[player[i].currentslot+1].full = 1; //The next slot will be full now

			player[i].currentslot++; //Move the player up one
		  }
		break;
		}


	   case 3://Attack
	   {
	  	    /*<insert code for attacking here> */
	  	   break;
	   }

	   default:
		   printf("Invalid input! Enter either 1, 2 or 3 as a choice!");
		   i--; //Ask player[i] again for their choice

	 }//End of switch statement

  }//End of for loop






}




