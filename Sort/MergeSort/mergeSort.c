#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	merge function:
		Input: two sorted arrays (arr1,arr2) and their lengths.
		Output: a sorted merged array stored in the location occupied by arr1 and arr2 
			(As in memory arr1 and arr2 are arrays stored in consecutive location).
*/
void merge(int* arr1,int length1,int* arr2,int length2){
	//ptr1 and ptr2 are pointers to the elements of arr1 and arr2 respectively
	int ptr1=0;
	int ptr2=0;
	
	/*
		A result array has been declared to store the intermediate merged results.
		resultPtr points to the last location of result for appending purpose.
	*/
	int* result=(int*) calloc(length1+length2,sizeof(int));
	int resultPtr=0;
	
	//Loop until we have exhausted all the elements of either arr1 or arr2
	while(ptr1<length1 && ptr2<length2){
		//If arr1[ptr1] <= arr2[ptr2] then
		if(*(arr1+ptr1) <= *(arr2+ptr2)){
			*(result+resultPtr)=*(arr1+ptr1); //Append arr1[ptr1] at the end of result
			ptr1++;	//Increment ptr1 to signify that we have used the current element
		}
		else{
			*(result+resultPtr)=*(arr2+ptr2); //Append arr1[ptr1] at the end of result
			ptr2++;	//Increment ptr1 to signify that we have used the current element
		}

		resultPtr++; //increment resultPtr as one element has been used either from arr1 or from arr2
	}
	
	//Append leftover elements of arr2 to result (if any)
	while(ptr1>=length1 && ptr2<length2){
		*(result+resultPtr)=*(arr2+ptr2);
		ptr2++;
		resultPtr++;
	}

	//Append leftover elements of arr1 to result (if any)
	while(ptr1<length1 && ptr2>=length2){
		*(result+resultPtr)=*(arr1+ptr1);
		ptr1++;
		resultPtr++;
	}
	
	/*
		As result is a seperate array, the merged elements will not be reflected in the original array.
		Therefore, the elements needs to be copied from results to original array.
		
		arr1 and arr2 are to consecutive array in memory i.e. arr2 begins just after arr1 in memory.
		Thus, arr1[length1]=arr2[0] (This works as merge function is called from the mergeSort function)
	*/

	for(int i=0;i<length1+length2;i++){
		*(arr1+i)=*(result+i);
	}

	free(result); //Deallocate memory contained by result

	return ; //return nothing as merge function has been called with the reference to original array
}
//End of merge function

/*
	mergeSort function:
		Input: An array (arr1) and it's length.
		Output: Pointer to the first element of a sorted array
*/
int* mergeSort(int* arr,int length){
	//If array contains more than one elements
	if(length>1){
		int mid=(length-1)/2; //Find the middle position

		int* leftArray = mergeSort(arr,mid+1); //Sort the first half of the array i.e. from index 0 to mid
		int* rightArray = mergeSort(arr+mid+1,length-mid-1); //Sort the other half of the array i.e.
								// from index mid+1 to (length-1)-(mid+1)+1 = length-mid-1

		merge(leftArray,mid+1,rightArray,length-mid-1);	//merge the sorted left half and the right half of the array
	}

	return arr; //return array as array is now sorted
}
//End of mergeSort function

//Used for display
void display(int* arr,int length){
	for(int i=0;i<length;i++){
		printf("%d ",*(arr+i));
	}
	printf("\n");

	return ;
}
//End of display

//Driver function
int main(){
	int arr[]={7,5,3,1,9,2,4,6,10,8};
	int length=10;

	printf("Before sorting:\n");
	display(arr,length);
	
	mergeSort(arr,length); //need not to catch the returned value from margeSort as its been called with refrence to arr

	printf("After sorting:\n");
	display(arr,length);

	return 0;
}
//End of Driver function
