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
 
    struct Slotstruct *first, *current, *last;
 
    for (int i = 0; i < *numofslots; i++)
    {
        last = malloc(sizeof (slot));
        last->data = i;
        last->next = NULL;
        if(i==0)
            first = last;
        else
            current-> next = last;
        current = last;
    }
 
    current = first;
    while (current != NULL)
    {
        current = current->next;
    }
 
 
    int rowNum=0;
 
    /*Randomly set the type of each slot:*/
    while(rowNum<*numofslots)
    {
        dice = rand() % 3; //Roll the imaginary 3 sided dice
 
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
     slot[i].full=0; //Initialize all values to 0.
    }
 
    int placed=0; //Boolean value to determine whether a player has been placed.
 
    for(i=0;i<numofplayers;i++)//Go through each player (0 to numofplayers).
    {
    while(placed == 0)//While the player has not been placed.
      {
       dice = rand() % (*numofslots); //Go to a random slot.
       printf("\nDICE=%d", dice);
 
       if (slot[dice].full==0)//If the current slot is empty.
        {
           printf("\ni=%d", i);
          slot[dice].currentplayer=i; //Assign the slot with a player POSITION (i.e. Player #1 = 0).
          players[i].currentslot=dice; //Assign the player with the slot position (not slot NUMBER!).
          slot[dice].full = 1; //Mark that this slot is full.
          placed = 1; //Placed = true
        }
 
      }
    placed = 0; //reset placed back to 0 (false).
    printf("\nPlayer #%d is on slot #%d (%s).\n",i+1, players[i].currentslot+1, slot[players[i].currentslot].slottype);
            /* The above line is a little confusing, so let's break it down:
 
              -> i+1: Since the first player (players[0]), starts with i being 0.
              -> players[i].currentslot+1: This is simply the slot NUMBER, which the player is standing on.
              -> slot[players[i].currentslot-1].slottype: players[i].currentslot will give us the slot POSITION.
                                                          Adding .slottype to the end of this will then give us
                                                          the type of slot, which the player is on.
 
             */
 
 
    }
 
 
}