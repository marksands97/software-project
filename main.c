#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h" //header file containing function prototypes
 
int main (void)
{
    setbuf(stdout, NULL); //for scanf to work properly
    int numofplayers;
    int numofslots;
    int i, choice;
 
    struct Characters *first, *current, *last;
 
    do{
    printf("How many people are playing?\n");
    scanf("%d", &numofplayers);
    }while(numofplayers<2 || numofplayers > MAXPLAYERS); //Ensures a valid input
 
 
    for (int i = 0; i < numofplayers; i++)
    {
        last = malloc (sizeof (players));
        last->data = i;
        last->next = NULL;
        if(i==0)
        {
            first = last;
        }
        else
            current-> next = last;
        current = last;
    }
 
    current = first;
    while (current != NULL)
    {
        current = current->next;
    }
 
 
    for(i=0;i<numofplayers;i++)
    {
        printf("Please enter a name for player %d: ", i+1);
        scanf("%24s", players[i].name);
    }
 
    for(i=0;i<numofplayers;i++)
        {
        do{
            printf("\nPlayer %d Type: (1)Elf (2)Human (3)Ogre (4)Wizard : ", i+1);
            scanf("%d", &choice);
           }while(choice!=1 && choice!=2 && choice!=3 && choice!=4); //Ensures a valid input
 
 
        switch(choice)
          {
            case 1:
            {
            strcpy(players[i].class, "Elf");
            break;
            }
 
            {
            case 2:
            strcpy(players[i].class, "Human");
            break;
            }
 
            {
            case 3:
            strcpy(players[i].class, "Ogre");
            break;
            }
 
            {
            case 4:
            strcpy(players[i].class, "Wizard");
            break;
            }
 
          }
        abilities(numofplayers, i);//Set the abilities for this player
        }
 
    slotsfunction(numofplayers, &numofslots); //Note: We are passing numofslots into the slots function by reference
 
    move(numofplayers, numofslots); //Note: Since numofslots is not being altered in this function, we are passing it be value this time.
 
 
    return 0;
}