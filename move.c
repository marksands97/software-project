#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"
 
void move(int numofplayers, int numofslots)
{
  setbuf(stdout,NULL);
 
  int i=0;
  int j,k;//Counters for finding the nearest player(s)
  int choice;
  int enemychoice,enemyposition;
  int leftclosed=0, rightclosed=0; //Boolean values to determine whether the left or right slot is impossible to move to.
 
  printf("\n\nCurrent positions:");
  printboard(numofslots);
 
  while(i<numofplayers)//Go through each of the players
  {
    printf("Player #%d, please select your option:\n", i+1);
    if(players[i].currentslot==0|| slot[players[i].currentslot-1].full == 1) //If this player is in the first position or the previous slot is full
    {
        leftclosed=1; //The left position is closed off to this player.
    }
    if(players[i].currentslot==numofslots-1 || slot[players[i].currentslot+1].full == 1) //If this player is in the last position or the next spot is full
    {
        rightclosed=1; //The right position is closed off to this player.
    }
 
    printf("\n");
 
    printf("1. Attack the nearest player\n");
 
    if(leftclosed==0) //If the left slot is open.
    {
       printf("2. Move one slot to the left\n");
    }
 
    if(rightclosed==0)//If the right slot is open
    {
     printf("3. Move one slot to the right\n");
    }
 
    scanf("%d", &choice);
 
 
     switch(choice)
     {
       case 1://Attack
       {
          leftclosed=0;
          rightclosed=0;
 
           j = players[i].currentslot; //j looks at the slots on the LEFT
           k = players[i].currentslot; //k looks at the slots on the RIGHT
           slot[players[i].currentslot].full=0;
 
          do
           {
             if(rightclosed == 0)
               j--;
             if(leftclosed==0)
               k++;
 
              if(k==numofslots)//If k has gone past the last slot
              {
                  rightclosed=1;//Then we can't attack right*
              }
              if(j==-1)//If j has gone before the first slot
              {
                  leftclosed=1;//Then we can't attack left
              }
 
              if(slot[j].full==1 && slot[k].full==1 && rightclosed==0 && leftclosed==0)
              {
                  do{
                  printf("\nTwo closest enemies found! Who do you attack?\n");
                  printf("1. Left enemy (Player %d)\n", (slot[j].currentplayer)+1);
                  printf("2. Right enemy (Player %d)\n", (slot[k].currentplayer)+1);
 
                  scanf("%d", &enemychoice);
                  }while(enemychoice <1 || enemychoice>2);
 
                  if(enemychoice==1)
                  {
                      enemyposition=j;
                  }
                  else if(enemychoice==2)
                  {
                      enemyposition=k;
                  }
              }
              else if((rightclosed==1 && slot[j].full==1) || (slot[k].full==0 && slot[j].full==1))//If closest enemy is on LHS
              {
                  enemyposition=j;
              }
              else if((leftclosed==1 && slot[k].full==1) || (slot[j].full==0 && slot[k].full==1))//If closest enemy is on RHS
              {
                  enemyposition=k;
              }
 
              slot[players[i].currentslot].full=1;
 
           }while(slot[j].full==0 && slot[k].full==0);//While the previous and next slot are empty
 
           attack(numofplayers, numofslots, enemyposition, i); //Initiliaze the attack function to calculate the new life values
 
 
           printf("%s (%s, %.0f)\n\n", players[i].name, players[i].class, players[i].life);
           break;
       }
 
       case 2://Left
       {
        if(leftclosed == 1) //If the player cannot go left.
        {
            printf("\nLeft is not a valid move for player #%d! Try again!\n", i+1);
            i--; //Ask player[i] for their choice again
        }
        else
          {
            slot[players[i].currentslot].full = 0;//The current slot will be empty now
            slot[players[i].currentslot-1].full = 1; //The previous slot will be full now
 
            players[i].currentslot--; //Move the player down one slot
            slot[players[i].currentslot].currentplayer = i; //Assign the new slot with this player
          }
 
        /*CHANGE ATTRIBUTES:*/
        if(slot[players[i].currentslot].slottype[0]=='H')//If player moved to a hill slot
        //NOTE: We just need to check what the first character of slottype is, not the whole string
            {
                if(players[i].dexterity<50)
                    players[i].strength -= 10;
                else if (players[i].dexterity>=50)
                    players[i].strength += 10;
            }
 
        else if(slot[players[i].currentslot].slottype[0]=='C')//If player moved to a city slot
            {
                if(players[i].smartness>60)
                    players[i].magic += 10;
                else if (players[i].smartness<=50)
                    players[i].dexterity -= 10;
            }
        printf("%s (%s, %.0f)\n\n", players[i].name, players[i].class, players[i].life);
        break;
       }
 
 
       case 3://Right
       {
        if(rightclosed == 1) //If the player cannot go right.
          {
            printf("\nRight is not a valid move for player #%d! Try again!\n"
                    "", i+1);
            i--; //Ask players[i] for their choice again
          }
        else
          {
            slot[players[i].currentslot].full = 0;//The current slot will be empty now
            slot[players[i].currentslot+1].full = 1; //The next slot will be full now
 
            players[i].currentslot++; //Move the player up one slot
            slot[players[i].currentslot].currentplayer = i; //Assign the new slot with this player position
          }
 
        /*CHANGE ATTRIBUTES:*/
        if(slot[players[i].currentslot].slottype[0]=='H')//If player moved to a hill slot
        //NOTE: We just need to check what the first character of slottype is, not the whole string
            {
                if(players[i].dexterity<50)
                    players[i].strength -= 10;
                else if (players[i].dexterity>=50)
                    players[i].strength += 10;
            }
 
        else if(slot[players[i].currentslot].slottype[0]=='C')//If player moved to a city slot
            {
                if(players[i].smartness>60)
                    players[i].magic += 10;
                else if (players[i].smartness<=50)
                    players[i].dexterity -= 10;
            }
        printf("%s (%s, %.0f)\n\n", players[i].name, players[i].class, players[i].life);
        break;
        }
 
       default:
           printf("\nInvalid input! Enter either 1, 2 or 3 as a choice!\n");
           i--; //Ask player[i] again for their choice
 
     }//End of switch statement
 
  leftclosed=0;//Reset the boolean values for the next player.
  rightclosed=0;
  choice=0;
 
  printboard(numofslots); //Print a visual showing the current location of each of the players
 
  i++;
 
  }//End of for loop
 
}