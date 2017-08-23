// Game_Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" 
#include "math.h" 
#include <time.h> 
#include "Game_Application_Header.h"


//MAIN
void main()
{

    int gameChoice = 1;
    
    do
    {
        gameChoice = menu();

        if (gameChoice == 1) RockPaperScissors();
        if (gameChoice == 2) Quiz();
        if (gameChoice == 3) GuessTheNumber();
		if (gameChoice == 4) Blackjack();
		else if (gameChoice != 1 && gameChoice != 2 && gameChoice != 3 && gameChoice != 4 && gameChoice != 0)
		{
			printf("\n------------------------------------------------------\n");
			printf("Error, please make a valid choice");
			printf("\n------------------------------------------------------\n");
		}


    } while (gameChoice != 0);


}//END OF MAIN