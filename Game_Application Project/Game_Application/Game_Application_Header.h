
//FUNCTIONS FOR THE VARIOUS GAMES

int menu();

void RockPaperScissors();

void GuessTheNumber();

void Quiz();

void Blackjack();



//FUNCTIONS FOR QUIZ, USED TO MAKE IT EASIER TO FOLLOW

void intro(); //CONTAINS THE INTRODUCTION, TO AVOID TOO MUCH BULKY TEXT IN THE MAIN

int checkOpen(FILE* fptr); //USED TWICE TO CHECK IF FILE OPENS


typedef struct //ANSWER STRUCTURE USED IN THE QUIZ TO COMPARE IF ANSWERS ARE CORRECT OR INCORRECT
{
	char answer[5];
	char playerAnswer;
} quizAnswers;

                 


//FUNCTIONS FOR BLACKJACK, USED TO MAKE IT EASIER TO FOLLOW

void instruction();		//INSTRUCTIONS ON HOW TO PLAY THE GAME, STORED SEPERATELY FOR EASE OF LOOKING THROUGH CODE

void populate(struct card deck[]);		//FILLS THE DECK OF CARDS

void printDeck(struct card deck[], int numInDeck);	//PRINTS THE DECK OF CARDS TO A SPECIFIED NUMBER

void shuffle(struct card deck[]);		//SHUFFLES THE DECK OF CARDS

void deal(struct card deck[], struct card other[], int start, int num);		//ASSIGNS A SPECIFIED NUMBER OF CARDS TO STRUCTURE, *DEALS* CARDS

int dealerDeal(struct card deck[]);		//DETERMINES WHAT CARDS THE DEALER DRAWS UP TO

int results(int playerT, int dealerT);		//DETERMINES WHO WINS AND WHO LOSES

float resultAction(int num, float money, float bet);		//SORTS OUT YOUR MONEY ACCORDINGLY



struct card //CARD STRUCTURE USED IN BLACKJACK
{ 
	int cardSuit;
	int cardFace;
	int cardValue;
}; 