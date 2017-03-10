#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "operations.h"
 
void abilities(int numofplayers, int i)
{
    int j, count=0;
 
    //Set the initial stats for this player:
    players[i].life = 100;
    players[i].smartness = 100;
    players[i].strength = 100;
    players[i].magic = 100;
    players[i].luck = 100;
    players[i].dexterity = 100;
 
    if(players[i].class[0] == 'E')//If the player is an elf
        {
            j = 70 + rand() % 31;
            players[i].smartness = j;//Smartness >=70
 
            j = 1 + rand() % 50;
            players[i].strength = j;//Strength <= 50
 
            j = 51 + rand() % 29;
            players[i].magic = j; //50 < Magic Skills < 80
 
            j = 60 + rand() % 41;
            players[i].luck = j;//Luck >= 60
 
            j = 1 + rand() % 100;
            players[i].dexterity = j;
 
        }
 
 
        if(players[i].class[0] == 'H')//If the player is human
        {
            while(count==0)//i.e. while their total abilities does not exceed 300
            {
                j = 1 + rand() % 100;
                players[i].smartness = j;
                j = 1 + rand() % 100;
                players[i].strength = j;
                j = 1 + rand() % 100;
                players[i].magic = j;
                j = 1 + rand() % 100;
                players[i].luck = j;
                j = 1 + rand() % 100;
                players[i].dexterity = j;
 
                if(players[i].strength + players[i].smartness + players[i].magic + players[i].luck + players[i].dexterity < 300)
                {
                    count=1;
                }
            }
        }
 
 
        if(players[i].class[0] == 'O')//If the player is an Ogre
        {
            while(count==0)
            {
                j = 1 + rand() % 20;
                players[i].smartness = j;//Smartness <= 20
 
                j = 80 + rand() % 21;
                players[i].strength = j;//Strength >=80
 
                players[i].magic = 0;
 
                j = 1 + rand() % 100;
                players[i].luck = j;
 
                j = 81 + rand() % 20;
                players[i].dexterity = j;//Dexterity >=80
 
                if(players[i].smartness + players[i].luck <= 50)
                {
                    count=1;
                }
            }
        }
 
 
        if(players[i].class[0] == 'W')//If the player is a wizard
        {
 
            j = 90 + rand() % 11;
            players[i].smartness = j;//Smartness >= 90
 
            j = 1 + rand() % 20;
            players[i].strength = j;//Strength <= 20
 
            j = 80 + rand() % 21;
            players[i].magic = j;//Magic Skills >= 80
 
            j = 50 + rand() % 51;
            players[i].luck = j;//Luck >= 50
 
            j = 1 + rand() % 100;
            players[i].dexterity = j;
        }
 
    printf("\nPlayer %d's Stats:\n", i+1);
    printf("Name = %s\n", players[i].name);
    printf("Class = %s\n", players[i].class);
    printf("Life = %.0f\n", players[i].life);
    printf("Smartness = %d\n", players[i].smartness);
    printf("Strength = %d\n", players[i].strength);
    printf("Magic = %d\n", players[i].magic);
    printf("Luck = %d\n", players[i].luck);
    printf("Dexterity = %d\n\n", players[i].dexterity);
 
}