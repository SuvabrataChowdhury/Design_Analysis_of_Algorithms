#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NO_OF_NODES 8

/*
	dfs:
		Input: A graph G and a starting vertex startNode.
		Output: A visit to all the vertices.
	
	Steps:
		1. If startNode is not visited then
			1.1 Mark startNode as visited
			1.2 For all neighbours neighbourNode of startNode do
				1.2.1 Perform dfs as neighbourNode being the startNode
*/

/*
	//G is stored as an adjacency list
	Algorithm dfs(G,startNode){
		
		if !visited[startNode] then{
			visited[startNode]:=true;
			write startNode;

			for node in G[startNode] do{
				dfs(G,node);
			}
		}
	}
*/

bool visited[NO_OF_NODES]={false};

void dfs(int graph[][NO_OF_NODES],int startNode){
	if(!visited[startNode]){
		visited[startNode]=true;
		printf("%d ",startNode);

		int i=0;
		while(graph[startNode][i]!=-1){
			dfs(graph,graph[startNode][i++]);
		}
	}
}

int main(){
	int graph[][NO_OF_NODES]={
					{1,2,-1},	//0
					{0,3,4,-1},	//1
					{0,4,5,-1},	//2
					{1,-1},		//3
					{1,2,6,-1},	//4
					{2,6,8,-1},	//5
					{4,5,7,-1},	//6
					{6,8,-1},	//7
					{7,5,-1}	//8
				};
	int startNode=0;

	printf("The visit is:\n");
	dfs(graph,startNode);
	printf("\n");

	return 0;
}
