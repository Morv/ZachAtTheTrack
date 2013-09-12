/* ZACH AT THE TRACK
Created by: 
Date:
Purpose: odds program.

1. add/remove money from an account
2. select a horse
4. bet on a horse
5. run a race and payout odds
6. keep track of horses that won and amount of times won.

*/
#include <stdio.h>
#include <stdlib.h>
#define flush fflush(stdin)
#define pause system("pause")
#define clr system("cls")

//FUNCTION PROTOTYPES 
int getUserChoice();
void drawMenu(); //1. place bet 2. select horse 3. account options 4. quit
int accountOptions(double *balance); //1. Add money 2. Cash out 3.Main menu 4. quit
int addMoney();
int cashOut();
void placeBet (double *balance);
void runTheRace();
int pickHorse(int *horse);
void drawHorseMenu();
void calculateWinnings (double *balance);
void displayResults(int winner);

main() 
{
	int userChoice = 0;
	
	do{
		getUserChoice();

	}while (userChoice != 4);

system("pause");
}//end main
int getUserChoice(){
	int userChoice = 0;
	drawMenu();
	scanf("%i", &userChoice);
	//make function to verify user's input matches selection in drawMenu function

	flush;
	clr;
	return userChoice;
}//end get user choice
void drawMenu(){
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Welcome to Zack's Track\n");
	printf("1. Place a bet\n2. Select a horse\n3. Account options\n4. Quit");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("Enter your choice (1-4):");
}//end drawMenu
