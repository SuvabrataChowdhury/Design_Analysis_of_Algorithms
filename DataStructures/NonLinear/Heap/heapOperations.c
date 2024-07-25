#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n=0;
int heap[100];
int last=-1;

void swap(int *num1,int *num2){
	int temp=*num1;
	*num1=*num2;
	*num2=temp;
}

bool insertHeap(int item){
	if(last==n-1)
		return false;
	else{
		int i=last+1;
		last++;

		while((i!=0)&&heap[(i+1)/2-1]<item){
			heap[i]=heap[(i+1)/2-1];
			i=(i+1)/2-1;
		}

		heap[i]=item;

		return true;
	}
}

void adjustHeap(){
	if(last==-1||last==0)
		return ;
	else{
		int item=heap[0];
		int cNode=0;
		int i=1;

		while(i<=last&&item<heap[i]){
			if(i+1<=last&&heap[i+1]>heap[i]){
				i++;
			}

			heap[cNode]=heap[i];
			cNode=i;
			i*=2;
		}

		if(i>last)
			heap[i/2]=item;
		else
			heap[i]=item;
	}
}

int deleteHeap(){
	if(last==-1)
		return -1;
	else{
		int val=heap[0];
		swap(&heap[0],&heap[last]);
		last--;
		adjustHeap();

		return val;
	}
}

int printHeap(){
	if(last<0)
		printf("Heap is empty\n");
	else{	
		for(int i=0;i<=last;i++)
			printf("%d ",heap[i]);
		printf("\n");
	}
}

int main(){
	while(1){
		printf("Enter the size of the heap\n");
		scanf("%d",&n);
		
		if(n<=0)
			printf("Wrong Input\n");
		else
			break;
	}
	
	int ch;
	int val;

	while(1){
		printf("1. Insert Heap\n");
		printf("2. Delete Heap\n");
		printf("3. Print Heap\n");
		printf("4. Exit\n");

		printf("------------------------------------\n");
		scanf("%d",&ch);
		printf("------------------------------------\n");

		switch(ch){
			case 1:
				printf("Enter the value to be inserted\n");
				scanf("%d",&val);

				if(insertHeap(val))
					printf("Insersion Successfull\n");
				else
					printf("Heap Overflow\n");

				break;
			case 2:
				val=deleteHeap();

				if(val==-1)
					printf("Heap Underflow\n");
				else
					printf("%d has been deleted\n",val);
				break;
			case 3:
				printHeap();

				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Input\n");
		}
	}
}
