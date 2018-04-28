#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randNum();
int judge(int, int);

int main(void){
	srand(time(0));
	while(1){
		int new=randNum(), guess;
		char ch;
		printf("Enter your guess:");
		scanf("%d", &guess);
		if(judge(guess, new))
			printf("You Win! Number=%d\n", new);
		else
			printf("You Lose! Number=%d\n", new);
		printf("You want to play the game again?(y/n)");
		getchar();
		scanf("%c", &ch);
		if(ch=='n'||ch=='N')
			break;
	}
	return 0;
}

int judge(int a, int b){
	int flag=0;
	for(int i=0; i<3; i++){
		if((a%10)==(b%10) || (a%10)==((b/10)%10) || (a%10)==(b/100)){
			flag=1;break;
		}
		a/=10;
	}
	return flag;
}

int randNum(){
	int num = (rand()%(900)) + 100;
	return num;
}
