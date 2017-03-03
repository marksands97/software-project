/*
 * abilities.c
 *
 *  Created on: 3 Mar 2017
 *      Author: Owner
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "operations.h"

void abilities(int num_players){

	int i, j;


	for(i=0;i<num_players;i++)
	{
		struct Characters players[num_players];

		strcpy(players[i].name, "name");             // names the user inputs them
		players[i].life = 100;
		players[i].smartness = 100;
		players[i].strength = 100;
		players[i].magic = 100;
		players[i].luck = 100;
		players[i].dexterity = 100;

	}

	for(i=0;i<num_players;i++)
	{
		if(players[i].class == 'E')
		{
			while(players[i].smartness < 70 || players[i].strength > 80 || players[i].magic <= 50 || players[i].magic >= 80 || players[i].luck < 60 )
			{
				j = 71 + rand() % 30;
				players[i].smartness = j;
				j = 1 + rand() % 100;
				players[i].strength = j;
				j = 1 + rand() % 50;
				players[i].magic = j;
				j = 61 + rand() % 40;
				players[i].luck = j;
				j = 1 + rand() % 100;
				players[i].dexterity = j;
			}
		}

		if(players[i].class == 'H')
		{
			while(players[i].smartness + players[i].strength + players[i].magic + players[i].luck + players[i].dexterity > 300)
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
			}
		}

		if(players[i].class == 'O')
		{
			while(players[i].smartness > 20 || players[i].strength < 80 || players[i].magic != 0 || players[i].dexterity < 80 || (players[i].smartness + players[i].luck) > 50)
			{
				j = 1 + rand() % 20;
				players[i].smartness = j;
				j = 81 + rand() % 20;
				players[i].strength = j;
				players[i].magic = 0;
				j = 1 + rand() % 50;
				players[i].luck = j;
				j = 81 + rand() % 20;
				players[i].dexterity = j;
			}
		}

		if(players[i].class == 'W')
		{
			while(players[i].smartness < 90 || players[i].strength > 20 || players[i].magic < 80 || players[i].luck > 50)
			{
				j = 91 + rand() % 10;
				players[i].smartness = j;
				j = 1 + rand() % 20;
				players[i].strength = j;
				j = 81 + rand() % 20;
				players[i].magic = j;
				j = 51 + rand() % 50;
				players[i].luck = j;
				j = 1 + rand() % 100;
				players[i].dexterity = j;
			}
		}
	}
}
