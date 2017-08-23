
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" 
#include "math.h" 
#include <time.h> 
#include "Game_Application_Header.h"


void intro() //INTRODUCTION HERE FOR EASE OF READING
{
	printf("------------------------------------------------------\n\n");
	printf("Welcome to our General Knowledge Quiz!\n\n");
	printf("You are about to face some of the most challenging questions\nI could find when I googled 'general knowledge questions'....\n");
	printf("Do you have what it takes to win?\n\n");
	printf("------------------------------------------------------\n\n");
}


int checkOpen(FILE* fptr) //CHECKS IF FILE OPENS
{
	if (fptr == NULL)
	{
		//IF NOTHING THEN PRINT ERROR
		printf("Error opening file! \n");
		return 1;
	}

	else
	{
		return 0;
	}

}