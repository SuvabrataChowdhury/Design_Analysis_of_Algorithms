#include<stdio.h>
#include<stdlib.h>

void hanoi(int n,char currPeg,char auxPeg,char targetPeg){
	if(n>=1){
		hanoi(n-1,currPeg,targetPeg,auxPeg);
		printf("%c -> %c\n",currPeg,targetPeg);
		hanoi(n-1,auxPeg,currPeg,targetPeg);
	}
	
	return ;
}

int main(){
	int n;
	char peg1,peg2,peg3;
	
	system("clear");
	printf("Enter number of disks\n");
	scanf("%d",&n);
	
	printf("Enter current peg\n");
	scanf(" %c",&peg1);
	printf("Enter auxiliary peg\n");
	scanf(" %c",&peg2);
	printf("Enter target peg\n");
	scanf(" %c",&peg3);
	printf("Target %c->%c\n",peg1,peg3);
	
	printf("The moves are: \n");
	
	hanoi(n,peg1,peg2,peg3);
	return 0;
}
