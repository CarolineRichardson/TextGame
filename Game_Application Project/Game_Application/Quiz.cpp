

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" 
#include "math.h" 
#include <time.h> 
#include "Game_Application_Header.h"




//MAIN QUIZ FUNCTION
void Quiz()
{
	char line[150]; //FOR READING IN DATA IN EACH LINE

	quizAnswers answers[10];

	int i = 0;
	int j = 0;
	int score = 0;


	intro();

	FILE* fptr2 = fopen ("answers.txt", "r"); //OPEN ANSWERS FILE

	if (checkOpen(fptr2) != 1)
	{
		while (fgets(answers[j].answer, sizeof(answers[j].answer), fptr2)) //READ INTO ARRAY OF ANSWERS BY LINE
		{
			j++;
		}
	}


	FILE* fptr = fopen("questions.txt", "r"); //OPEN QUESTIONS FILE

	if (checkOpen(fptr) != 1)
	{
		while (fgets(line, sizeof(line), fptr)) 
		{
			printf("\n%s\n", line); //PRINT QUESTION
			printf("Enter the number of your answer: "); 
			scanf("%c", &answers[i].playerAnswer); //ADD TO ARRAY 

			fflush(stdin);


			//IF NUMBER CORRESPONDING TO ANSWER EQUALS THAT OF PLAYERS ANSWER
			if (answers[i].answer[0] == answers[i].playerAnswer)
			{ 
				printf("CORRECT\n");
				score++;
			}
			
			else
			{
				printf("INCORRECT\n");
			}

			i++;
		}

		fclose(fptr);
		fclose(fptr2);

		printf("\nYour total score is %d out of 10.\n\n", score); //SCORE
	}

} //END OF QUIZ