/****************************************************
Written by: Josh, Justin, Kyle, Morvan
Date Written: September 12, 2013
Purpose: Assignment 4: Zach At The Track

1. add/remove money from account
2. select and bet on a horse
3. run a random race and payout odds
4. keep track of horses that won and number of wins
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush (stdin)
#define SIZE 9 //number of horses to choose from


// FUNCTION PROTOTYPES
	int getUserChoice(); //returns 1-4
	void drawMenu();
	int verifyChoice(int userChoice, int maxChoice);//for a 4 option menu, enter 4 to verify that user's choice is between 1 and 4.
	int getHorse(); //returns horse number 1-SIZE (9)
	void horseMenu();
	void accountOptions(int *account);
	void accountMenu(int balance);
	int eligibility(int horse, int acct);
	int placeBet(int *account);
	int randomNum();
	int horseWin(int randomNum);
	int payout(int winner, int bet);
	void results(int winner, int standings[]);

// MAIN FUNCTION
main () {
	int userChoice = 0, myHorse = 0, account = 0, winner = 0, bet = 0, standings[SIZE]={0};

	do{ 
		userChoice= getUserChoice();
		
		switch (userChoice){
			case 1: //Choose your horse
				myHorse = getHorse();
				break;
			case 2: // Race
				if (eligibility(myHorse, account) == 0) //checks for a horse chosen and money.
					{ break; }
				
				bet = placeBet(&account);
				winner = horseWin(randomNum()); //finds a winning horse.
		
				cls;
				if (myHorse == winner)
				{
					account = (account + payout(winner, bet));
					printf("Congratulations your horse, Horse %i won...you have just won $%i dollars.\n", winner, payout(winner, bet));
					pause;
				} else {
					printf("Horse %i won the race you lost %i dollars.\n", winner, bet);
					pause;
				}
					results(winner, standings);
					
				break;
			case 3:  // Account Options
				accountOptions(&account);
				break;
		}
	} while (userChoice != 4);
}//end of main
int getUserChoice(){
	int userChoice = 0;
	drawMenu();
	scanf_s("%i", &userChoice);
	flush;
	userChoice = verifyChoice(userChoice, 4);

	cls;
	return userChoice;
}//end get user choice
void drawMenu(){
	cls;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Welcome to Zack's Track\n");
	printf("1. Choose your horse\n2. Race\n3. Account options\n4. Quit\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("Enter your choice (1-4):");
}//end drawMenu
int verifyChoice(int userChoice, int maxChoice)
{
	int result = userChoice;
	while (result > maxChoice || result < 1) //1 is set to be the lowest choice option.
	{
		printf("\nEnter a number between 1 and %i: ", maxChoice);
		scanf_s("%i", &result);
		flush;
	}//end if statement

	return result;
}//end verifyChoice range
int getHorse()
{
	int userChoice = 0;

	horseMenu();
		scanf_s("%i", &userChoice);
	userChoice = verifyChoice(userChoice, SIZE);
	
	flush;
	cls;
	return userChoice;
}
void horseMenu()
{
	cls;
	printf("~~~~~~~~~~~~~~~~~~\n");
	printf("Choose your horse\n");
	printf("~~~~~~~~~~~~~~~~~~\n");
	printf("Horse Payout Odds\n");
	printf("_____ ______ ____\n");
	printf("  1    2-1    35%%\n");
	printf("  2    5-1    12%%\n");
	printf("  3    10-1   8%%\n");
	printf("  4    15-1   6%%\n");
	printf("  5    50-1   1%%\n");
	printf("  6    20-1   4%%\n");
	printf("  7    10-1   8%%\n");
	printf("  8    5-1    12%%\n");
	printf("  9    3-1    14%%\n");
	printf("~~~~~~~~~~~~~~~~~~\n\n");
	printf("Enter your choice (1-9):");
}
void accountOptions(int* account)
{
	int acctChoice = 0, amount=0, acct= *account;
	do{
		acct = *account;
		accountMenu(acct);
			scanf_s("%i", &acctChoice);
			flush;
		acctChoice = verifyChoice(acctChoice, 3);		
		
		cls;
		printf("Current Balance: %i\n", *account); 

		switch(acctChoice){
		case 1:
				printf("How much do you want to add? $");
					scanf_s("%i", &amount);

				*account = (*account + amount);

				printf("\nNew account balance: %i\n", *account);

			break;
		case 2:
				printf("How much do you want to withdraw? $");
					scanf_s("%i", &amount);

				if (amount >= *account){
					printf("\nCashing out: $%i", *account);
					*account = 0;
				} else {
					printf("\nCashing out: $%i", amount);
					*account =( *account - amount);
				}//end if-else statement

			break;
		};//end switch
	}while (acctChoice != 3);//end do-while
} // end account options
void accountMenu(int balance)
{
	cls;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("ACCOUNT MENU\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Current Balance: %i\n", balance);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("1. Add Money\n");
	printf("2. Cash Out\n");
	printf("3. Main Menu\n\n");
	printf("Choice (1-3):");
} // end account menu
int placeBet(int* account)
{
	int bet = 0;
	
	cls;
	printf("Place your bet: $");
		scanf_s("%i", &bet);
	
		while (bet > *account)
		{
			printf("\nBet cannot exceed $%i.\n Place your bet: $", *account);
			scanf_s("%i", &bet);
		}
		if (bet == 0)
		{
			printf("\nYou did not place a bet.  ");
			pause;
			return 0;
		}

		*account = (*account - bet);

	return bet;
}
int eligibility(int horse, int acct)
{
	if (horse == 0 || acct == 0)
	{
		if (horse == 0)
		{
			printf("You much choose a horse.\n");
		}
		if(acct == 0)
		{
			printf("You must add money to your account.\n");
		}
		pause;
		return 0;
	}
	return 1;
}
int randomNum()//generates the random number
{   
	int i=0, number=0;
	
	srand(time(0)); 
	
	for (i = 0; i < 1; i++)
	number = 1 + rand() % 100;
		
	return number;
}
int horseWin(int randomNum)//matches the random number with the corresponding horse
{	
	int winningHorse = 0, number = randomNum;
	if (number <= 35)//35%
	{
		winningHorse = 1;//horse 1
	}
	else if (number >= 36 & number <= 47)//12%
	{
		winningHorse = 2;//horse 2
	}
	else if (number >= 48 & number <= 55)//8%
	{
		winningHorse = 3;//horse 3
	}
	else if (number >= 56 & number <= 61)//6%
	{
		winningHorse = 4;//horse 4
	}
	else if (number == 62)//1%
	{
		winningHorse = 5;//horse 5
	}
	else if (number >= 63 & number <= 66)//4%
	{
		winningHorse = 6;//horse 6
	}
	else if (number >= 67 & number <= 74)//8%
	{
		winningHorse = 7;//horse 7
	}
	else if (number >= 75 & number <= 86)//12%
	{
		winningHorse = 8;//horse 8
	}
	else//14%
	{
		winningHorse = 9;//horse 9
	}
	return winningHorse;
}
int payout (int winner, int bet)
{
	int result = bet;

	if (winner == 1) { result = (result*2);  }
	if (winner == 2) { result = (result*5);  }
	if (winner == 3) { result = (result*10); }
	if (winner == 4) { result = (result*15); }
	if (winner == 5) { result = (result*50); }
	if (winner == 6) { result = (result*20); }
	if (winner == 7) { result = (result*10); }
	if (winner == 8) { result = (result*5);  }
	if (winner == 9) { result = (result*3);  }

	return result;
}
void results (int winner, int standings[])
{
	int i=0;
	
	standings[winner-1]++;

	cls;
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("  CURRENT STANDINGS\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("  Name\t\tWins\n");
	printf("_______\t\t____\n");

		for (i; i<SIZE ;i++)
		{
			printf("Horse %i\t\t %i\n", i+1, standings[i]);
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		pause;
	return;
}
