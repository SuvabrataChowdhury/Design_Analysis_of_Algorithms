#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
	Problem Statement:
		Given a weighted graph G(V,E) and a starting vertex v0, destination vertex v, 
		we are to find a path from v0 to v which constitutes the minimum cost.
*/
/*
	Recursive Formulation:
		D(i,j)=min{D(i,j),D(i,k)+D(k,j)} ;

		D(i,i)=0
*/

#define INF 9999

bool status[100];
int dist[100],preNode[100];

void printPath(int preNode[],int numVertices,int endingVertex){
	int currentVertex=endingVertex;

	int path[numVertices],index=-1;
	while(currentVertex!=-1){
		path[++index]=currentVertex;
		currentVertex=preNode[currentVertex];
	}

	for(int i=index;i>=0;i--){
		if(i!=0)
			printf("%d->",path[i]);
		else
			printf("%d",path[i]);
	}
	printf("\n");

}

int findMinVertex(int numVertices,int dist[],bool status[]){
	int minVertex=-1;
	int minDistance=INF;

	for(int i=0;i<numVertices;i++){
		if(!status[i]){
			if(dist[i]<minDistance){
				minDistance=dist[i];
				minVertex=i;
			}
		}
	}

	return minVertex;
}

int dijkstra(int numVertices,int length[][numVertices],int startingVertex,int endingVertex){
	//Initialization

	status[startingVertex]=true;
	dist[startingVertex]=0;
	preNode[startingVertex]=-1;

	for(int i=0;i<numVertices;i++){
		if(i!=startingVertex){
			status[i]=false;
			dist[i]=length[startingVertex][i];
			preNode[i]=startingVertex;
		}
	}

	int remainingVertices=numVertices-1;
	int currentVertex=startingVertex;

	while(remainingVertices!=0){
		currentVertex=findMinVertex(numVertices,dist,status);
		
		status[currentVertex]=true;
		
		//Check wheather going through the current vertex minimizes the distance covered
		//for all the other unexplored vertices.
		for(int i=0;i<numVertices;i++){
			if(!status[i]){
				if(dist[i]>dist[currentVertex]+length[i][currentVertex]){
					dist[i]=dist[currentVertex]+length[i][currentVertex];
					preNode[i]=currentVertex;
				}
			}
		}

		remainingVertices--;
	}

	printPath(preNode,numVertices,endingVertex);

	return dist[endingVertex];
}

int main(){
	int numVertices,startingVertex,endingVertex;

	printf("Enter the number of vertices\n");
	scanf("%d",&numVertices);

	int length[numVertices][numVertices];
	
	printf("Enter the weights of the edges:\n");
	for(int i=0;i<numVertices;i++){
		for(int j=0;j<numVertices;j++){
			if(j>i){
				printf("Enter the distance between %d and %d\n",i,j);
				scanf("%d",&length[i][j]);
				length[j][i]=length[i][j];
			}
			else if(j==i)
				length[i][j]=0;
		}
	}
	
	printf("Enter the starting vertex\n");
	scanf("%d",&startingVertex);
	
	printf("Enter the ending vertex\n");
	scanf("%d",&endingVertex);

	printf("The path is:\n");
	int minDistance=dijkstra(numVertices,length,startingVertex,endingVertex);
	
	printf("The distance covered: %d\n",minDistance);

	return 0;
}
