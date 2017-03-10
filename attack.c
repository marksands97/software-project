#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"
 
void attack(int numofplayers, int numofslots, int enemyposition, int attackerposition)
{
 
/*If the Strength points of the attacked player are <=70,
 then ATTACKED player life points = life points - 0.5 * his/her Strength points.*/
    if(players[enemyposition].strength<=70)
    {
        players[enemyposition].life -= (players[enemyposition].strength * 0.5);
    }
 
/*Else, if the strength points of the attacked player are > 70,
  the ATTACKER life points = life points - 0.3 * (attacked player’s strength points).*/
    else if(players[enemyposition].strength>70)
    {
        players[attackerposition].life -= (0.3 * players[enemyposition].strength);
    }
 
 
    printf("Player %d attacked Player %d!\n", attackerposition+1, enemyposition+1);
 
}