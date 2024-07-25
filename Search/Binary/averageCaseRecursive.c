#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"binarySearchRecursive.h"

#define SIZE 100000
#define START_SIZE 1000
#define INCR 5

clock_t start,end;

int main(){
	srand(time(0));

	int target=0;
	double sumTime=0.0;

	printf("Size,AC\n");
	for(int size=START_SIZE;size<=SIZE;size+=INCR){
		int *arr=(int *)calloc(size,sizeof(int));
	
		for(int i=0;i<size;i++){
			*(arr+i)=i+1;
		}
		
		target=*(arr+rand()%(size+1));
		sumTime=0.0;
		for(int i=0;i<5;i++){
			start=clock();
			binarySearchRecursive(arr,0,size-1,target);
			end=clock();

			sumTime+=((double)(end-start)/(double)CLOCKS_PER_SEC);
		}

		free(arr);

		printf("%d,%0.10lf\n",size,sumTime/5.0);
	}

	return 0;
}
