#include<stdio.h>

int binarySearchRecursive(int *arr,int low,int high,int target){
	if(low > high)
		return -1;
	
	int mid=(low+high)/2;

	if(target == *(arr+mid))
		return mid;
	
	return (target < *(arr+mid))?binarySearchRecursive(arr,low,mid-1,target):binarySearchRecursive(arr,mid+1,high,target);
}

/*
//Driver Code
int main(){
	int arr[]={1,5,7,8,9,10,11,13,14,15};
	int target=15;

	int index=binarySearchRecursive(arr,0,9,target);

	if(index==-1)
		printf("Target not found\n");
	else
		printf("Target Found at: %d\n",index);
}
*/
