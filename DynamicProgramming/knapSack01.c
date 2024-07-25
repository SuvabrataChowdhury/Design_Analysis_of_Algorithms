#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
	Problem Statement:
		Given n items each having prices pi and weights wi and a knapsack whose weightlimit is W,
		choose items such that the sum of weights do not exceed the weight limit and the selection also maximizes the total profit.
		We are not allowed to choose a fractional amount of item.
*/
/*
	Recursive Formulation:
		P(i,W)=max{P(i-1,W),pi+P(i-1,W-wi)}

		P(i,0)=0;P(0,W)=0;P(i,W)=-INF where i<0;
*/

#define INF 9999

typedef struct item{
	int profit;
	int weight;
}Item;

int max(int num1,int num2){
	return (num1>num2)?num1:num2;
}

int getProfit(int itemNo,int weight,int weightLimit,int table[][weightLimit]){
	if(weight<0)
		return -INF;
	else
		return table[itemNo][weight];
}

bool isPresent(int target,int rowNum,int cols,int profit[][cols]){
	for(int i=0;i<cols;i++){
		if(profit[rowNum][i]==target)
			return true;
	}
	return false;
}

int selectItems(Item items[],int numItems,int weightLimit,bool selection[]){
	//Construct and Initialize the lookup table.
	int profit[numItems+1][weightLimit+1];
	
	for(int i=0;i<=numItems;i++){
		for(int j=0;j<=weightLimit;j++){
			if(i==0||j==0)
				profit[i][j]=0;
			else
				profit[i][j]=-INF;
		}
	}

	for(int i=1;i<=numItems;i++){
		for(int w=1;w<=weightLimit;w++){
			profit[i][w]=max(getProfit(i-1,w,weightLimit+1,profit),getProfit(i-1,w-items[i].weight,weightLimit+1,profit)+items[i].profit);
		}
	}
	//Display table
	for(int i=0;i<=numItems;i++){
		for(int j=0;j<=weightLimit;j++){
			printf("%d ",profit[i][j]);
		}
		printf("\n");
	}
	
	int target=weightLimit;
	for(int i=numItems;i>=1 && target!=0;i--){
		if(!isPresent(profit[i][target],i-1,weightLimit+1,profit)){
			selection[i]=true;
			target-=items[i].weight;
		}
	}

	return profit[numItems][weightLimit];
}

int main(){
	int numItems,weightLimit;

	printf("Enter the number of items\n");
	scanf("%d",&numItems);
	
	printf("Enter weightLimit\n");
	scanf("%d",&weightLimit);

	Item items[numItems+1];
	bool selection[numItems+1]={false};

	printf("Enter profits and weights of the items\n");
	for(int i=1;i<=numItems;i++){
		printf("Profit[%d]: \n",i);
		scanf("%d",&items[i].profit);
		printf("Weight[%d]: \n",i);
		scanf("%d",&items[i].weight);
	}

	printf("Maximum profit earned:%d\n",selectItems(items,numItems,weightLimit,selection));
	printf("The selected items are:\n");
	for(int i=0;i<=numItems;i++){
		if(selection[i])
			printf("%d ",i);
	}
	printf("\n");

	return 0;
}
