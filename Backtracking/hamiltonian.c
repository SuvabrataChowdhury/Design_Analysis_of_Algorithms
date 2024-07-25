#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 999

int path[MAX];
int numVertices;
int Graph[MAX][MAX];

bool contains(int arr[],int length, int target){
	for(int i=0;i<length;i++){
		if(arr[i]==target)
			return true;
	}

	return false;
}

bool canBeVisited( int currentNode, int indexPath){
	if(!contains( path, indexPath, currentNode)){
		if(indexPath==numVertices-1){
			return Graph[currentNode][path[0]]==1 && Graph[currentNode][path[indexPath-1]];
		}
		return Graph[currentNode][path[indexPath-1]];
	}
	return false;
}

void writePath(int path[], int length){
	for(int i=0;i<length;i++){
		if(i!=length-1)
			printf("%d -> ",path[i]);
		else
			printf("%d ",path[i]);
	}

	printf("\n");
}

void printPath(int path[],int numVertices,int index){
	for(int i=0;i<numVertices;i++){
		printf("%d ",path[i]);
	}
	printf(", %d\n",index);
}

void Hamiltonian(int numVertices,int indexPath){

	if(indexPath<numVertices){
		for(int i=1;i<=numVertices;i++){
			
			if(canBeVisited(i,indexPath)){
				path[indexPath]=i;
				Hamiltonian(numVertices,indexPath+1);
			}
		}
	}
	else{
		writePath(path,numVertices);
	}
}

int main(){
	printf("Enter the number of vertices:\n");
	scanf("%d",&numVertices);

	for(int i=1;i<=numVertices;i++){
		for(int j=1;j<=numVertices;j++){
			if(i==j)
				Graph[i][j]=0;
			if(i<j){
				printf("Edge between (%d,%d):\n",i,j);
				scanf("%d",&Graph[i][j]);
				
				Graph[j][i]=Graph[i][j];
			}
		}
	}
	
	int startNode;

	printf("Enter the starting node\n");
	scanf("%d",&startNode);
	
	path[0]=startNode;
	Hamiltonian(numVertices,1);

	return 0;
}
