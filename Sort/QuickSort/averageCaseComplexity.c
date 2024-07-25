#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define START_SIZE 1000
#define SIZE 100000
#define INCR 50

clock_t start,end;

void swap(int* num1,int* num2){
	int temp=*num1;
	*num1=*num2;
	*num2=temp;

	return ;
}

int partition(int arr[],int start,int end){
	int pivot=arr[start];
	int endOfLeftArray=start;

	for(int i=start+1;i<=end;i++){
		if(arr[i]<pivot){
			endOfLeftArray++;
			swap(&arr[endOfLeftArray],&arr[i]);
		}
	}

	swap(&arr[start],&arr[endOfLeftArray]);

	return endOfLeftArray;
}

void quickSort(int arr[],int start,int end){
	if(start<end){
		int pivotIndex=partition(arr,start,end);

		quickSort(arr,start,pivotIndex-1);
		quickSort(arr,pivotIndex+1,end);
	}

	return ;
}

int main(){
	srand(time(0));

	int arr[SIZE];
	
	printf("Size,Time Taken\n");
	for(int size=START_SIZE;size<=SIZE;size+=INCR){
		for(int i=0;i<size;i++)
			arr[i]=rand()%RAND_MAX+1;

		start=clock();
		quickSort(arr,0,size-1);
		end=clock();

		printf("%d,%lf\n",size,(double)(end-start)/(double)CLOCKS_PER_SEC);
	}

	return 0;
}
