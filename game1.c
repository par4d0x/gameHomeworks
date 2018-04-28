#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);
int randNum();
int pointCalc(int);

int main(void){
	int choice;
	while(1){
			printf("Enter 1 to generate a number.\n");
			printf("Enter 2 to exit the game\n\n");
			scanf("%d", &choice);
			switch(choice){
				case 1:{
						int n = randNum();
						int p = pointCalc(n);
						printf("Number Gen: %d\n", n);
						printf("Point : %d\n",p);
						break;}
				case 2:
					exit(0);
				default:
					printf("Invalid Entry\n");
			}
		}
	return 0;
}

int isPrime(int n){
	int i, flag=1;
	if(n==1)
		return 0;
	for(i=2; i<=sqrt(n);i++){
		if(!(n%i)){
			flag =0;
			break;
		}
	}
	return flag;
}

int randNum(){
	srand(time(NULL));
	int n= rand();
	n%=102+1;
	return n;
}

int pointCalc(int n){
	int point=0;
	if(isPrime(n))
		point++;
	if(n>50)
		point++;
	return point;
}
