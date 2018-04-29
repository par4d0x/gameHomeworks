#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randNum();
int sum(int);
int hint(int, int);

int main(){
	int trial=10, choice;
	srand(time(0));
	int n = randNum();
	// printf("NUMBER : %d\n", n);
	printf("***NUMBER GENERATED***\nHINT:(x+x+x+x) %d\n",sum(n));
	while(trial--){
		printf("\n(TRIAL LEFT:%d)\n",trial+1);
		printf("Enter a guess:");
		scanf("%d", &choice);
		if(choice == n){
			printf("You guessed it right!\n");
			break;
		}
		printf("HINT: %d digits are correct\n", hint(choice, n));
		if(trial>0)
			printf("Try Again!\n");
		
	}
	if(trial<0)
		printf("Alas! You ran out of trials!\nTry again later\n");
	return 0;
}

int randNum(){
	int num = rand()%(9000)+1000;
	return num;
}

int sum(int n){
	int sum=0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
 
int hint(int a, int b){
	int num=0;
	while(a){
		if(a%10 == b%10)
			num++;
		a/=10, b/=10;
	}
	return num;
}