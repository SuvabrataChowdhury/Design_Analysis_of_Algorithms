#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"linearSearch.h"

#define SIZE 10000

clock_t start,end;

int main(){
	printf("Size,TimeTaken\n");

	srand(time(0));

	for(int size=1000;size<=SIZE;size+=10){
		int *arr=(int *) calloc(size,sizeof(int));
		
		double sumTime=0.0;

		for(int i=0;i<10;i++){
			for(int j=0;j<size;j++){
				*(arr+i)= rand()%RAND_MAX + 1 ;
			}

			int target= rand()%RAND_MAX + 1;
			
			start=clock();
			linearSearch(arr,size,target);
			end=clock();
			
			double time=((double)(end-start))/((double)CLOCKS_PER_SEC);
			sumTime+=time*1000;
		}

		free(arr);
		printf("%d,%lf\n",size,sumTime/10);
	}

	return 0;
}
