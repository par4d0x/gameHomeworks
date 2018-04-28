#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int p1=0,p2=0;
int p11=0, p22=0;
int randNum();
void point(int, int);
int digRep(int);

int main(void){
	srand(time(NULL));
	for(int i=1; i<=3; i++){
		printf("***ROUND %d***\n",i);
		int player1=randNum();
		int player2=randNum();
		printf("Number generated for Player:%d\n",player1);
		printf("Number generated for Computer: %d\n",player2);
		printf("+++POINTS+++\n");
		point(player1, player2);
		printf("Player: %d\tComputer: %d\n",p1, p2);
		p11+=p1, p22+=p2, p1=0, p2=0;
	}

	if(p11>p22)
		printf("\n\nYou Win!\n");
	else if(p11<p22)
		printf("\n\nYou Lose!\n");
	else if(p11==p22)
		printf("\n\nTie!\n");
	return 0;
}

int isPrime(int n){
	int flag=1;
	if(n==1)
		return 0;
	for(int i=2; i<=sqrt(n); i++){
		if(!(n%i)){
			flag=0;
			break;
		}
	}
	return flag;
}

void point(int pl1, int pl2){
	if(pl1>pl2)
		p1++;
	if(pl2>pl1)
		p2++;
	if(isPrime(p1))
		p1++;
	if(isPrime(p2))
		p2++;
	if(digRep(pl1))
		p1++;
	if(digRep(pl2))
		p2++;
}
int digRep(int n){
	int flag=0;
	if((n%10)==((n/10)%10) || (n%10)==(n/100))
		flag=1;
	n/=10;
	if((n%10)==(n/10))
		flag=1;
	return flag;
}
int randNum(){
	int num = (rand()%(900)) + 100;
	return num;
}
