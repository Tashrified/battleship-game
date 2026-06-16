 /* 
Program Name: Project2_MoinuddinTashrif.c
Programmer: Md Moinuddin Tashrif
Class: CS 3335 
Project: 01
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void setBoard(int *arr);
void printBoard(int *arr);
void setComputerBoard(int *);
int playGame(int *, int *);

int main()
{
	srand(time(NULL));
	int arr[10] = {0};
	int arrCom[10] = {0};
	setBoard(arr);

	setComputerBoard(arrCom);
	playGame(arr, arrCom);

	return 0;
}

void setBoard(int *arr) {

	int enterPos1;
	int enterPos2;

	printf("Enter position 1: ");
	scanf("%d", &enterPos1);
	while(enterPos1< 0 || enterPos1 > 9) {
		printf("You must enter an integer from 0 to 9. Try again: ");
		scanf("%d", &enterPos1);
	}

	printf("Enter position 2: ");
	scanf("%d", &enterPos2);
	while(enterPos2 < 0 || enterPos2 > 9 || enterPos2 == enterPos1) {
		if(enterPos2 == enterPos1) {
			printf("Position 1 and position 2 cannot be the same. Try again: ");
		}
		else {
			printf("You must enter an integer from 0 to 9. Try again: ");
		}
		scanf("%d", &enterPos2);
	}

	*(arr + enterPos1) = 1;
	*(arr + enterPos2) = 1;

}

void printBoard(int *arr) {
	for(int i = 0; i< 10; i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
}

void setComputerBoard(int *arrCom) {
	int r = rand() % 10;

	*(arrCom + r) = 1;

	// do{
	//     r = rand () % 10;
	// } while(*(arrCom + r) == 1);

	int s = rand() % 10;
	while(s == r) {
		s = rand() % 10;
	}
	*(arrCom + s) = 1;
}

int playGame(int *arr, int *arrCom) {
	int rounds = 0;

	while(rounds < 4) {
		printf("Round %d:\n",rounds + 1);
		rounds++;
		int r = rand() % 10;
        printf("Computer guesses %d\n", r);
		while(*(arr + r) != 1 && *(arr + r) != 0) {
			printf("%d already done. ", r);
			r = rand() % 10;
			printf("Computer guesses %d\n", r);
		}

		if(*(arr + r) == 0) { // 0
			*(arr + r) = 2;   //Miss
			printf("MISS!\n");
		}
		else { // 1
			*(arr + r) = 3;   //Hit
			printf("HIT!\n");
		}

		int humanGuess;
		printf("Enter guess: ");
		scanf("%d", &humanGuess);
		while(humanGuess< 0 || humanGuess > 9) {
			printf("You must enter an integer from 0 to 9. Try again: ");
			scanf("%d", &humanGuess);
		}
		printf("You guessed %d\n", humanGuess);
		if(*(arrCom + humanGuess) == 1 || *(arrCom + humanGuess) == 3) { // 1, 3
			*(arrCom + humanGuess) = 3; //Hit
			printf("HIT!\n");
		}
		else { // 0, 2
			*(arrCom + humanGuess) = 2; //Miss
			printf("MISS!\n");
		}
        int humanShipsSunk = 0;
        int computerShipsSunk = 0;
		printf("Human Board: \n");
		printf("0 1 2 3 4 5 6 7 8 9\n");
		for(int i = 0; i < 10; i++) {
			if(*(arr + i) == 0) { // no ship
				printf("* ");
			}
			else if(*(arr + i) == 1) {
				printf("S ");
			}
			else if(*(arr + i) == 2) {
				printf("M ");
			}
			else {
				printf("H ");
				humanShipsSunk++;
			}
		}
		printf("\n");
		printf("Computer Board: \n");
		printf("0 1 2 3 4 5 6 7 8 9\n");
		for(int i = 0; i < 10; i++) {
			if(*(arrCom + i) == 0) { // no ship
				printf("* ");
			}
			else if(*(arrCom + i) == 1) {
				printf("* ");
			}
			else if(*(arrCom + i) == 2) {
				printf("M ");
			}
			else {
				printf("H ");
				computerShipsSunk++;
			}
		}
		printf("\n");
		if (humanShipsSunk == 2 || computerShipsSunk == 2){
		    break;
		}
	}
	int humanShipsSunk = 0;
    int computerShipsSunk = 0;
	for(int i = 0; i < 10; i++) {
		if(*(arr + i) == 3) {
			humanShipsSunk++;
		}
		if(*(arrCom + i) == 3){
	       computerShipsSunk++; 
	    }
	}
	
    if(humanShipsSunk > computerShipsSunk){
	    printf("Computer wins!");
	}
	else if(computerShipsSunk > humanShipsSunk) {
	    printf("Human wins!");
	}
	else{
	    printf("Tie!");
	}
}