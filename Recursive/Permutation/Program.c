#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;

void swap(char *ch1,char *ch2){
	char temp=*ch1;
	*ch1=*ch2;
	*ch2=temp;
	
	return ;
}

void permutation(char *arr,int size,int beg){
	if(beg==size-1)
		printf("%d. %s",++count,arr);
	else{
		for(int i=beg;i<size;i++){
			swap(arr+i,arr+beg);
			permutation(arr,size,beg+1);
			swap(arr+i,arr+beg);
		}
	}
	
	return ;
}

int main(){
	system("clear");
	
	char arr[100];
	printf("Enter permutation string\n");
	fgets(arr,100,stdin);
	
	//printf("%d\n",(int)strlen(arr));
	printf("The permutations are-\n");
	permutation(arr,(int)strlen(arr)-1,0);
	
	return 0;
}
