#include<stdio.h>
#include<stdlib.h>

int length;

void display(int arr[],int length,int pivotIndex){
	for(int i=0;i<length;i++){
		if(i==pivotIndex)
			printf("|%d| ",arr[i]);
		else
			printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int* num1,int* num2){
	int temp=*num1;
	*num1=*num2;
	*num2=temp;

	return ;
}

int partition(int arr[],int start,int end){
	int pivot=arr[start];		//Select the first element as the pivot element
	int endOfLeftArray=start;	//Indicates the last index of the left side array of pivot

	for(int i=start+1;i<=end;i++){	//Scan the array from left to right
		if(arr[i]<pivot){	//If an element appears which is lesser than pivot
			endOfLeftArray++;	//Insert the element into the left array
			swap(&arr[endOfLeftArray],&arr[i]);	//Swap is done to preserve the existing elements of the left array
		}
	}

	swap(&arr[start],&arr[endOfLeftArray]);	//swap the pivot into its original position

	printf("Pivot=%d\n",pivot);
	display(arr,length,endOfLeftArray);

	return endOfLeftArray;	//Return the last index of the left array as it now holds the pivot
}

void quickSort(int arr[],int start,int end){
	if(start<end){
		int pivotIndex=partition(arr,start,end); //Get the pivot index

		quickSort(arr,start,pivotIndex-1);	//Sort the left half
		quickSort(arr,pivotIndex+1,end);	//Sort the right half
	}

	return ;
}

int main(){
	int arr[]={2,1,10,11,5,9,7,3,6,4,8};
	length=sizeof(arr)/sizeof(arr[0]);

	printf("Before Sorting:\n");
	display(arr,length,-1);
	
	printf("Intermediate Arrays:\n");
	quickSort(arr,0,length-1);

	printf("After Sorting:\n");
	display(arr,length,-1);

	return 0;
}
