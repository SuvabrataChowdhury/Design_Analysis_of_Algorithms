#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
	Problem Statement:
		Given the profits and weights of n objects and a knapsack, having weightlimit W, 
		the goal is to find an optimal selection of the objects such that it maximizes the 
		profit and the total weight does not exceed the weightlimit W.

		So the goal is to maximize
			sum i=1 to n(pi * xi) where xi=0 or 1, pi is the profit of ith object and 
			sum i=1 to n(wi * xi) where xi=0 or 1,wi is the weight of ith object, does not exceed weightLimt W.
*/
/*
	Recursive Formulation:
		P(i,W)=max{P(i-1,W),pi+P(i-1,W-wi)} ;
		P(0,W)=0 and P(i,0)=0 and P(i,W)=-INF where W<0
*/

#define INF 9999

typedef struct Item{
	int profit;
	int weight;
}Item;

int profit[100][100]={{0}};

int max(int num1,int num2){
	return (num1>num2)?num1:num2;
}

int getProfit(int numItems,int weightLimit){
	if(weightLimit<0)
		return -INF;
	return profit[numItems][weightLimit];
}

bool isPresent(int arr[],int length,int target){
	for(int i=length-1;i>=0;i--){
		if(arr[i]==target)
			return true;
	}

	return false;
}

int findProfit(Item items[],int numItems,int weightLimit,bool selection[]){
	for(int i=1;i<numItems+1;i++){
		for(int w=1;w<weightLimit+1;w++){
			profit[i][w]=max(getProfit(i-1,w),items[i].profit+getProfit(i-1,w-items[i].weight));
		}
	}

/*
	for(int i=0;i<numItems+1;i++){
		for(int j=0;j<weightLimit+1;j++){
			printf("%d ",profit[i][j]);
		}

		printf("\n");
	}
*/
	int maxProfit=profit[numItems][weightLimit];

	for(int i=numItems;i>=0;i--){
		if(isPresent(profit[i],weightLimit+1,maxProfit)){
			if(!isPresent(profit[i-1],weightLimit+1,maxProfit)){
				selection[i]=true;
				maxProfit-=items[i].profit;
			}
		}
	}

	return profit[numItems][weightLimit];
}

int main(){
	int numItems,weightLimit;
	
	printf("Enter the weightLimit\n");
	scanf("%d",&weightLimit);

	printf("Enter the number of items\n");
	scanf("%d",&numItems);

	Item items[numItems+1];
	items[0].profit=-1;
	items[0].weight=-1;

	for(int i=1;i<=numItems;i++){
		printf("Profit[%d]: ",i);
		scanf("%d",&items[i].profit);
		printf("Weight[%d]: ",i);
		scanf("%d",&items[i].weight);
	}

	bool selection[100]={false};

	printf("Total profit earned: %d\n",findProfit(items,numItems,weightLimit,selection));
	printf("The selected items are:\n");
	for(int i=0;i<numItems+1;i++){
		if(selection[i])
			printf("%d ",i);
	}
	printf("\n");

	return 0;
}
