#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randNum();
int product(int);

int main(void){
	int flag=1, guess, trial=1;
	srand(time(0));
	int n = randNum();
	printf("***NUMBER GENERATED***\nHINT:(x*x*x) %d\n",product(n));
	while(flag){
		printf("\n(Trial No->%d)\n", trial++);
		printf("Enter your guess: ");
		scanf("%d", &guess);
		if(guess==n){
			printf("Right Guess! You Win!\n");
			printf("The number was %d\n",n);
			flag=0;;
		}
		else
			printf("Wrong Guess! Try Again.\n");
	}
	return 0;
}

int randNum(){
	int num = (rand()%(900)) + 100;
	return num;
}

int product(int n){
	int prod=1;
	while(n){
		prod *= n%10;
		n/=10;
	}
	return prod;
}