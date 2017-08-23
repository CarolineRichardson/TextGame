#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Game_Application_Header.h"
#include <math.h>


//FOR DISPLAYING CAD SUITS IN EITHER WORD OR SYMBOL FORM
char suits[][10] = {"Hearts","Diamonds","Clubs","Spades"};
char suits2[4] = {3,4,5,6};		//REPRESENTS THE CARD SYMBOLS, AS SEEN IN SEMESTER ONE

//FOR DISPLAYING CARD FACES IN EITHER WORD OR CHARACTER FORM
char faces[][10] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
char faces2[15] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};



void instruction() //BLACKJACK INSTRUCTIONS
{
	printf("\n------------------------------------------------------\n\tINSTRUCTIONS: How To Play\n------------------------------------------------------\n");
	printf("The aim of the game is to accumulate a higher point total than the dealer, but without going over 21.\n");
	printf("You compute your score by adding the values of your individual cards.\n");
	printf("The cards 2 through 10 have their face value, J, Q, and K are worth 10 points each, and the Ace is worth either 1 or 11 points (player's choice).\n");
	printf("Each hand will result in either a win, a loss, a draw or a natural\n");
	printf("In the case of a win, the player wins as much as he bet. \nIn the case of a loss, the player's bet is taken by the dealer.\n");
	printf("In the case of a draw, the bet is returned to the player. \nA natural occurs when the player wins with 21 from their first cards.\n");
	printf("In this case, the player wins 1.5 times his original bet.\n");
	printf("Each turn you can choose whether to hit, meaning to draw another card, or to stand, meaning to face the dealer with your cards as they are.\n");
	printf("You must be careful not to go over 21 as this means an automatic loss.\n");
}

void populate(struct card deck[])	//FILLS THE DECK OF CARDS
{
	int i = 0;
	float j = 0;

	for(i=0; i<52; i++)
	{
		deck[i].cardFace = (i%13); //USED TO DETERMINE THE CARD FACE

		if (deck[i].cardFace <10) //ASSIGNS THE APPROPRIATE NUMBER VALUE TO ALL CARDS UP TO TEN
		{
			deck[i].cardValue = (i%13)+1;
		}

		else if (deck[i].cardFace >= 10) //ASSIGNS A VALUE OF TEN TO JACK, QUEEN, AND KING
		{
			deck[i].cardValue = 10;
		}

		j = (i/13); //THIS LINE IS USED TO PREVENT ERRORS BETWEEN INTEGERS AND FLOATS IN THE FOLLOWING LINE
		deck[i].cardSuit = (ceil(j)); //THIS BRINGS THE NUMBER UP TO THE NEXT INTEGER, ALLOWING TO DIVIDE THE 52 INTO FOUR GROUPS FOR SUITS
	}

}




void printDeck(struct card deck[], int numInDeck)	//PRINTS THE DECK OF CARDS TO A SPECIFIED NUMBER
{
	int i = 0;
	int suit;
	int face;

	for (i=0; i<numInDeck; i++)
	{
		suit = deck[i].cardSuit;
		face = deck[i].cardFace;

		printf ("\n%c%c\t%s of %s", faces2[face], suits2[suit], faces[face], suits[suit], suits2[suit]);
	}
}




void shuffle(struct card deck[])
{
	int i = 0;
	int j = 0;
	struct card temp;
	
	srand(time(NULL)); //SEEDS FOR BETTER RANDOMISATION
	
	for(i=0; i<52; i++)
	{
		j = rand()%52;
		temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}
 



void deal(struct card deck[], struct card other[], int start, int num) //FUNCTION TO DEAL CARDS INTO PLAYER/DEALER CARD STRUCTURES
{ 
   int i;
   int j = 0;

   for ( i=start-1; i<(start-1+num); i++) 
   {
	   other[j].cardFace = deck[i].cardFace; 
	   other[j].cardSuit = deck[i].cardSuit; 
	   other[j].cardValue = deck[i].cardValue;
	   j++;
	  
   } 
} 




int results(int playerT, int dealerT) //FUNCTION FOR DETERMINING RESULTS
{
	if (playerT == 21)
	{
		if (dealerT != 21)
		{
			return 1; //1 FOR A NATURAL
		}

		else if (dealerT == 21)
		{
			return 2; //2 FOR A DRAW
		}
	}

	else if (playerT < 21)
	{
		if (dealerT <=21)
		{
			if (dealerT > playerT)
			{
				return 3; //DEALER WIN
			}

			if (playerT > dealerT)
			{
				return 4; //PLAYER WIN
			}

			if (playerT == dealerT)
			{
				return 2; //DRAW
			}
		}

		else if (dealerT > 21)
		{
			return 4;
		}
	}

	else if (playerT > 21)
	{
		return 3; //DEALER WIN
	}

}



float resultAction(int num, float money, float bet) //FUNCTION FOR DETERMINING WHAT HAPPENS MONEY-WISE
{
	if (num == 1) //NATURAL
	{
		printf("\n------------------------------------------------------\n");
		printf("\n\nYou have won a natural. You get 1.5 times your bet back.\n");
		money = (money + (bet * 1.5));
	}

	if (num == 2) //DRAW
	{
		printf("\n------------------------------------------------------\n");
		printf("\n\nIt's a tie. You neither lose nor gain money.\n");
		money = money;
	}

	if (num == 3) //DEALER WIN
	{
		printf("\n------------------------------------------------------\n");
		printf("\n\nThe dealer has won this round. You lose your bet.\n");
		money = (money-bet);
	}

	if (num == 4) //PLAYER WIN
	{
		printf("\n------------------------------------------------------\n");
		printf("\n\nYou have won this round. You win the amount that you bet.\n");
		money = (money + bet);
	}

	return money;
}





int dealerDeal(struct card deck[]) //FUNCTION TO DETERMINE HOW MANY CARDS THE DEALER DRAWS
{
	int total = 0;

	if ((deck[0].cardValue == 1 || deck[1].cardValue == 1) && (deck[0].cardValue + deck[1].cardValue == 11)) 
	{
		total = 21;
		printDeck(deck, 2);
		printf("\nDealer's total card value is 21\n");
	}

	
	else if ((deck[0].cardValue + deck[1].cardValue) >= 17)
	{
		total = (deck[0].cardValue + deck[1].cardValue);
		printDeck(deck, 2);
		printf("\nDealer's total card value is %d", total);
	}

	else if ((deck[0].cardValue + deck[1].cardValue + deck[2].cardValue) >= 17)
	{
		total = (deck[0].cardValue + deck[1].cardValue + deck[2].cardValue);
		printDeck(deck, 3);
		printf("\nDealer's total card value is %d", total);
	}

	else if ((deck[0].cardValue + deck[1].cardValue + deck[2].cardValue + deck[3].cardValue) >= 17)
	{
		total = (deck[0].cardValue + deck[1].cardValue + deck[2].cardValue + deck[3].cardValue);
		printDeck(deck, 4);
		printf("\nDealer's total card value is %d", total);
	}

	else if ((deck[0].cardValue + deck[1].cardValue + deck[2].cardValue + deck[3].cardValue + deck[4].cardValue) >= 17)
	{
		total = (deck[0].cardValue + deck[1].cardValue + deck[2].cardValue + deck[3].cardValue + deck[4].cardValue);
		printDeck(deck, 4);
		printf("\nDealer's total card value is %d", total);
	}

	return total;
}