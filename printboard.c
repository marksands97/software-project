/*
 * printboard.c
 *
 *      Author: Fionan(16360121), Mark
 *      Function which prints the current state of the board
 *      (i.e. Player positions and number of slots)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"

void printboard(int numofslots)
{
  int i;

  printf("\n**");
  for(i=0;i<=numofslots;i++)
  {
	  printf("****");
  }

  printf("\n{ ");


  i=0;

  while(i<numofslots)
  {
	  printf("[");
	  if(slot[i].full==1)//If this slot is full
	  {
		  printf("%d", (slot[i].currentplayer)+1); //Print out the player on slot[a]
	  }
	  else
	  {
		  printf(" "); //If there is no one on the slot
	  }
	  printf("] ");

	  i++;
  }

  printf("}\n**");
  for(i=0;i<=numofslots;i++)
  {
	  printf("****");
  }
  printf("\n\n");

}




