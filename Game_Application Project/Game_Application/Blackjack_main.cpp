
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" 
#include "math.h" 
#include <time.h> 
#include "Game_Application_Header.h"

void Blackjack()
{
	//CARD STRUCTURES TO HOLD THE DECK AND THE PLAYER AND DEALERS CARDS
	struct card deck[52];
	struct card player[5];
	struct card dealer[5];

	//USED IN VARIOUS COUNTS AND CHECKS
	int instruct = 0;
	int standHit = 0;
	int i = 0;
	int numCards = 2;
	int choice = 0;
	int resultNum = 0;
	int error = 0;

	float yourMoney = 50;
	float yourBet = 0;
	int yourTotal = 0;
	int dealerTotal = 0;

	printf("------------------------------------------------------\n");
	printf("Enter 1 for instructions on how to play the game or enter any other number to proceed: ");
	scanf_s("%d", &instruct);

	while (instruct == 1) //TO SEE INSTRUCTIONS
	{
		instruction();
		printf("\nEnter any number except for 1 to carry on to the game: ");
		scanf_s("%d", &instruct);
	}

	printf("\n\n\n------------------------------------------------------\n\t\t  BLACKJACK\n------------------------------------------------------\n");

	while (yourMoney != 0)
	{
			printf("\n\nYou have %.2f euro at the start of this round.\nEnter how much you wish to bet this round: ", yourMoney);
			scanf_s("%f", &yourBet);


			
			while (yourBet <=0 || yourBet > yourMoney)
			{
				printf("\nERROR!\nPlease enter a positive amount less than or equal to the amount of money you have.\n");

				printf("\nYou have %.2f euro at the start of this round.\nEnter how much you wish to bet this round: ", yourMoney);
				scanf_s("%f", &yourBet);

			}


		
		populate(deck);
		shuffle(deck);

		deal(deck, player, 1, 5);
		deal(deck, dealer, 6, 5);

		
		while(standHit != 2) //ALLOWING YOU TO CHOOSE WHETHER TO STAND OR HIT
		{
			yourTotal = 0;
			printf("\n------------------------------------------------------\nYour cards are:\n");
			printDeck(player, numCards);

			for (i=0; i<numCards; i++)
			{
				if (player[i].cardValue == 1)
				{
					printf("\nDo you want the Ace to be worth 1 or 11 this turn? "); //LETS YOU CHOOSE WHAT VALUE YOU WANT THE ACE TO TAKE
					scanf("%d", &choice);

					while (choice != 1 && choice != 11)
					{
						printf("Error, invalid entry. Please try again: ");
						scanf("%d", &choice);
					}

					if (choice == 11)
					{
						player[i].cardValue = 11;
					}

					
				}

				yourTotal += player[i].cardValue;
				
			}

			printf("\nYour total card value is %d\n", yourTotal);

			printf("\nThe dealer's one visible card is:\n");
			printDeck(dealer, 1);
			
			if (yourTotal > 21) //IS THE EQUIVALENT OF STANDING, IF YOUR TOTAL IS OVER 21
			{
				standHit = 2;
				printf("\n\nYour card value is now greater than 21.\n");
			}

			else 
			{	
				printf("\nDo you wish to hit or stand?\nEnter 1 for hit or enter 2 for stand: ");
				scanf_s("%d", &standHit);

				if (standHit == 1)
				{
					numCards ++;
				}

				else if (standHit != 1 || standHit !=2)
				{
					printf("\n------------------------------------------------------\nError, please enter either one or two. Please try again.\n------------------------------------------------------\n");
				}
			}
		}

		if (yourTotal <=21)
		{
			printf("\nThe dealer draws cards according to the rules of blackjack (must draw until 17 or over).\n");
			dealerTotal = dealerDeal(dealer); //DETERMINES THE DEALER'S TOTAL
		}

		resultNum = results(yourTotal, dealerTotal);  //RETURNS 1 FOR A NATURAL, 2 FOR A DRAW, 3 FOR A DEALER WIN, 4 FOR A PLAYER WIN

		yourMoney = resultAction(resultNum, yourMoney, yourBet); //ADJUSTS YOUR MONEY ACCORDING TO RESULTS AND BETTING AMOUNTS
			
		numCards = 2; //RESETS THESE VALUES FOR THE NEXT ITERATION IF THERE IS ONE
		standHit = 0;
	
		
	}

	printf("\n\nYou are now out of money and have lost the game. \n\n");

}
