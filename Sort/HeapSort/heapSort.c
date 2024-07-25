#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int length){
	for(int i=0;i<length;i++){
		printf("%d ",arr[i]);
	}

	printf("\n");
}

void swap(int *num1,int *num2){
	int temp=*num1;
	*num1=*num2;
	*num2=temp;

	return ;
}

/*
	adjust():
		Input: an array arr, the root Index of the subtree to be adjusted and the length of the array
		Output: a heap in the subtree of arr rooted at rootIndex
	
	Complexity: O(log (n))
*/
void adjust(int arr[],int rootIndex,int length){
	int childIndex=2*rootIndex;	//go to the child of the root node

	while(childIndex<=length){ //loop until the heap property is no longer violated
		if(childIndex<length && arr[childIndex-1]<arr[childIndex]){	//if right child is greater than left child
			childIndex++;	//access right child
		}

		if(arr[childIndex-1]>arr[rootIndex-1]){	//if the largest child is greater than it's parent then
			swap(&arr[childIndex-1],&arr[rootIndex-1]);	//swap them
			rootIndex=childIndex;	//follow where the node went
			childIndex*=2;	//go to the current node's children
		}
		else	//else if heap property is intact
			break;	//get out of the loop
	}

	return ;
}

/*
	delete():
		Input: an array arr, the index deleteIndex of the node to be deleted and a pointer to the length of the array
		Output: Item at deleteIndex and length-1
	Complexity: O(log (n)) [Same as adjust]
*/

int delete(int arr[],int deleteIndex,int* length){
	int deletedItem=arr[deleteIndex-1];	//store the item to be deleted in a variable

	swap(&arr[deleteIndex-1],&arr[*length-1]);	//swap the element to be deleted with the last element of the heap
	*length=*length-1;	//decrement length to signify the deletion of the last element

	adjust(arr,deleteIndex,*length);	//adjust the heap as the new root may violate the heap property

	return deletedItem;	//return the deleted item.
}

/*
	heapify():
		Input: an array arr and it's length
		Output: arr as a heap
	
	Complexity: O(n * log(n))
*/
void heapify(int arr[],int length){
	int i=length/2;	//go to the node right before the leaf level
	while(i>0){
		adjust(arr,i,length);//adjust the subtree rooted at i so that the subtree becomes a heap
		i--;	//access the previous parent node
	}

	return ;
}

/*
	heapSort():
		Input: an array arr and its length
		Output: the sorted arr
	Complexity: O(n * log(n))
*/
void heapSort(int arr[],int length){
	heapify(arr,length); //Transform the given array into a max heap
	
	int max=-1;
	while(length>1){
		max=delete(arr,1,&length); //delete the root of the heap i.e. the max element
		arr[length]=max;	// place the max element in the last position of the array
	}

	return ;
}

int main(){
	int arr[]={40,80,35,90,45,50,70};
	int length=sizeof(arr)/sizeof(arr[0]);

	printf("Before sorting:\n");
	display(arr,length);

	heapSort(arr,length);

	printf("After sorting:\n");
	display(arr,length);

	return 0;
}
