/*
 * main.c
 *
 *  Created on: 3 Mar 2017
 *      Author: Owner
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "operations.h"

int main(void)
{
	int i, choice, num_players;
	srand(time(NULL));

	setbuf(stdout, NULL);
	printf("How many players would you like to be in the game (Max 6): ");
	scanf("%d", &num_players);

	for(i=0;i<num_players;i++)
	{
		printf("Please enter a name for player %d: ", i+1);
		scanf("%s", players[i].name);
	}

	for(i=0;i<num_players;i++)
	{
		printf("Player %d name : %s\n", i+1, players[i].name);
	}

	for(i=0;i<num_players;i++)
	{
		printf("Player %d Type: (1)Elf (2)Human (3)Orge (4)Wizard : ", i+1);
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			strcpy(players[i].class, "Elf");
			break;

			case 2:
			strcpy(players[i].class, "Human");
			break;

			case 3:
			strcpy(players[i].class, "Ogre");
			break;

			case 4:
			strcpy(players[i].class, "Wizard");
			break;
		}
	}

	i=0;

	for(i=0;i<num_players;i++)
	{
		if(players[i].class[0] == 'E')
		{
			printf("Player %d is an Elf\n", i+1);
		}

		else if(players[i].class[0] == 'H')
		{
			printf("Player %d is a Human\n", i+1);
		}

		else if(players[i].class[0] == 'O')
		{
			printf("Player %d is an Ogre\n", i+1);
		}

		else if(players[i].class[0] == 'W')
		{
			printf("Player %d is a Wizard\n", i+1);
		}
	}

	abilities(num_players);

	return 0;
}
