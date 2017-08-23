
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" 
#include "math.h" 
#include <time.h> 



int menu()
{

        int gameChoice = 0;


        printf("------------------------------------------------------\n");
        printf("Welcome to Caroline & Catherine's Game Application\n");
        printf("------------------------------------------------------\n\n");


        printf("GAMES:\n");
        printf("1 - Rock, Paper, Scissors\n");
        printf("2 - Quiz\n");
        printf("3 - Guess The Number\n");
		printf("4 - Blackjack\n\n");

        printf("------------------------------------------------------\n");
        printf("0 - Quit Program\n");
        printf("------------------------------------------------------\n");


        printf("Enter corresponding number: ");
        scanf("%d",&gameChoice);
    
        fflush(stdin);

        return gameChoice;


}//END OF SELECTION MENU









//ROCK PAPER SCISSORS
void RockPaperScissors()
{


        printf("------------------------------------------------------\n\n");
        printf("Welcome to Rock, Paper, Scissors!\n\n");


        int playerMove; //NUMBER CORRESPONDING TO PLAYERS MOVE

        
        srand(time(NULL)); //SETTING TO TIME
        int computerMove = rand() % 3 + 1; //NUMBER CORRESPONDING TO COMPUTER'S MOVE, BETWEEN 1 & 3

		do
		{
			printf("1 - Rock\n");
			printf("2 - Paper\n");
			printf("3 - Scissors\n\n");

			printf("Selection: ");
			scanf("%d",&playerMove);
			
			if (playerMove != 1 && playerMove != 2 && playerMove != 3)
			{
				printf("\n\nInvalid entry. Please try again.\n\n");
			}

		} while (playerMove != 1 && playerMove != 2 && playerMove != 3);



            //POSSIBLE PLAYER MOVES

            if (playerMove == 1)//PLAYER PICKS ROCK
            {
                printf("\nYou picked Rock\n");
            }


            else if (playerMove == 2)//PLAYER PICKS PAPER
            {
                printf("\nYou picked Paper\n");
            }


            else if (playerMove == 3)//PLAYER PICKS SCISSORS
            {
                printf("\nYou picked Scissors\n");
			}





            //POSSIBLE COMPUTER MOVES


            if (computerMove == 1)//COMPUTER PICKS ROCK
            {
                printf("Computer picked Rock\n");
            }


            if (computerMove == 2)//COMPUTER PICKS PAPER
            {
                printf("Computer picked Paper\n");
            }


            if (computerMove == 3)//COMPUTER PICKS SCISSORS
            {
                printf("Computer picked Scissors\n");
            }

                


                //LOGIC FOR WIN LOSE OR TIE

                if (playerMove == computerMove)//SAME SELECTION
                {
                    printf("TIE\n\n");

                }


                if (playerMove == 1)//PLAYER ROCK

                {

                    if (computerMove == 2)//COMPUTER PAPER
                    {
                        printf("LOSER!\n\n");
                    }


                    if (computerMove == 3)//COMPUTER SCISSORS
                    {
                        printf("WINNER!\n\n");
                    }

                }


                if (playerMove == 2)//PLAYER PAPER
                {

                    if (computerMove == 1)//COMPUTER ROCK
                    {
                        printf("WINNER!\n\n");

                    }

                    if (computerMove == 3)//COMPUTER SCISSORS
                    {
                        printf("LOSER!\n\n");

                    }
                }


                if (playerMove == 3)//PLAYER SCISSORS
                {

                    if (computerMove == 1)//COMPUTER ROCK
                    {
                        printf("LOSER!\n\n");
                    }

                    if (computerMove == 2)//COMPUTER PAPER
                    { 
                        printf("WINNER!\n\n");
                    }

                }



} //END OF ROCK,PAPER,SCISSORS






//GUESS THE NUMBER
void GuessTheNumber()
{


        srand(time(NULL)); //SETTING TO TIME 
        int number = rand() % 15 + 1; //NUMBER TO GUESS BETWEEN 1 & 15

        int tries=0; //TO HOLD ATTEMPTS TO GUESS NUMBER 
        int guess=0; //TO HOLD PLAYER'S GUESS
        

        printf("------------------------------------------------------\n\n");
        printf("Welcome to Guess the Number!\n\n");



        //GUESSING LOOP

            while(guess != number)//LOOP WHILE GUESS IS NOT EQUAL TO THE ACTUAL NUMBER
            {

                printf("Enter a guess (1-15): "); 
                scanf("%d", &guess); 


                    if (guess > number) //IF PLAYER'S GUESS IS BIGGER THAN ACTUAL NUMBER
                    {
                        printf("Too high... Guess Again!\n\n");
                        tries++;
                    }


                    if (guess < number) //IF PLAYER'S GUESS IS LOWER THAN ACTUAL NUMBER
                    {
                        printf("Too low... Guess Again!\n\n"); 
                        tries++;
                    }


                    if(guess == number) //IF PLAYER'S GUESS EQUALS THE ACTUAL NUMBER
                    {
                        tries++;
                        printf("\nDING DING DING\nWE HAVE A WINNER!\nYou got it in %d guesses!\n", tries);
                        printf("------------------------------------------------------\n\n\n");
                    }


            
            }//END OF GUESSING LOOP

}//END OF GUESS THE NUMBER