#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int Graph[999][999];
int numVertices;

void printArr(int arr[],int length){
	for(int i=1;i<=length;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void printGraph(int numVertices){
	for(int i=0;i<=numVertices;i++){
		for(int j=0;j<=numVertices;j++){
			printf("%d ",Graph[i][j]);
		}

		printf("\n");
	}
}

bool isValidAssign(int color,int vertex,int numVertices,int coloration[]){
	for(int i=1;i<vertex;i++){
		if(Graph[vertex][i]==1 && coloration[i]==color)
			return false;
	}

	return true;
}

void colorGraph(int numVertices,int color[numVertices],int currentVertex,int maxColor){
	if(currentVertex<=numVertices){
		for(int i=1;i<=maxColor;i++){
			if(isValidAssign(i,currentVertex,numVertices,color)){
				color[currentVertex]=i;
				colorGraph(numVertices,color,currentVertex+1,maxColor);
			}
		}
	}
	else
		printArr(color,numVertices);
}

int main(){

	printf("Enter the number of vertices:\n");
	scanf("%d",&numVertices);

	
	for(int i=1;i<=numVertices;i++){
		for(int j=1;j<=numVertices;j++){
			if(i==j)
				Graph[i][j]=0;
			if(i<j){
				printf("Edge between (%d,%d)\n",i,j);
				scanf("%d",&Graph[i][j]);
				
				Graph[j][i]=Graph[i][j];
			}
		}
	}

	printf("The Graph is\n");
	printGraph(numVertices);

	int maxColor;
	printf("Enter the maximum number of colors to color the graph\n");
	scanf("%d",&maxColor);

	int color[numVertices+1];
	printf("The possible colorations are:\n");
	colorGraph(numVertices,color,1,maxColor);

	return 0;
}
