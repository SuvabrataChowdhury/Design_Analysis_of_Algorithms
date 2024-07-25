#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int toBeVisited[100],start=-1,end=-1;
bool visited[100]={false};

bool isEmpty(int queue[]){
	if(start==-1)
		return true;
	return false;
}

void printQueue(int queue[]){
	if(start!=-1){
		for(int i=start;i<=end;i++)
			printf("%d ",queue[i]);
		printf("\n");
	}
}

void add(int queue[],int item){
	if(start==-1)
		start++;
	
	end++;
	queue[end]=item;
}

int delete(int queue[]){
	if(start==-1)
		return -9999;

	int item=queue[start];
	if(start==end){
		start=-1;
		end=-1;
	}
	else
		start++;

	return item;
}

/*
	bfs:
		Input: A graph G represented as a adjacency list and a starting node startNode.
		Output:	A visit to all the vertices of G starting from start node.
	
	Steps:
		1. Set currentNode as startNode.
		2. Check if currentNode is not visited then 
			2.1. Insert the neighbours of the currentNode in a queue[to be visited...].
			2.2. Mark currentNode as visited.
		3. Remove a node from the queue and set it as the new currentNode.
		4. Repeat step 2 and 4 until the queue is empty [i.e. no nodes are left unvisited].
*/
/*
	Algorithm bfs(G,startNode){
		add(toBeVisited,startNode);

		while !isEmpty(toBeVisited) do{
			currentNode:=remove(toBeVisited);
			
			if(!visited[currentNode]){
				for i:=1 to G[currentNode].length do{
					add(toBeVisited,G[currentNode,i]);
				}

				visited[currentNode]:=true;
			}
		}

		write(visited);
	}

*/

void write(bool visited[]){
	for(int i=0;i<100;i++){
		if(visited[i])
			printf("%d ",i);
	}

	printf("\n");
}

void bfs(int graph[][5],int startNode){
	int currentNode;
	add(toBeVisited,startNode);
	
	//While there exists unvisited nodes do
	while(!isEmpty(toBeVisited)){
		
		//Start visit from the first waiting node
		/** Visit has started **/
		currentNode=delete(toBeVisited);

		if(!visited[currentNode]){	//If the currentNode has not been visited
			int i=0;
			while(graph[currentNode][i]!=-1){	//Iterate through the neighbours of currentNode
			//Add all neighbour of current nodes in the queue as they will be visited next
				add(toBeVisited,graph[currentNode][i++]);
			}
			
			visited[currentNode]=true;
			printf("%d ",currentNode);
		}

		/** Visit has been completed **/
		//Go to the next waiting node
	}

	printf("\n");
}

int main(){
	int graph[][5]={
			{-1,-1,-1,-1,-1},
			{2,3,-1,-1,-1},
			{1,3,4,5,-1},
			{1,2,5,-1},
			{2,5,-1},
			{2,3,4,-1}
			};
	printf("The bfs traversal of the graph is:")
	bfs(graph,1);

	return 0;
}
