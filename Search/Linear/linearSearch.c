#include<stdio.h>

//Pointer is used as the array to be supplied may change size for experimental complexity calculation purpose.
int linearSearch(int *arr,int length,int key){
	for(int i=0;i<length;i++){
		if(*(arr+i)==key)
			return i;
	}

	return -1;
}

//Dummy driver function
/*
int main(){
	int arr[]={7,8,5,6,4,10,5};
	int length=7,key=4;

	int index=linearSearch(arr,length,key);
	if(index==-1)
		printf("Not Found\n");
	else
		printf("Found at: %d\n",index);
}
*/
