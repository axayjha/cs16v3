#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minKey(int key[V], bool mstSet[V]);
void printMST(int parent[V], int graph[V][V]);
void primsMST(int graph[V][V]);

int main(){
	int graph[V][V] = {
					  {0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                      };
 
    primsMST(graph); 

}


void primsMST(int graph[V][V]){
	int key[V];
	int parent[V];
	bool mstSet[V];

	for(int i=0; i<V; i++)
		key[i]=INT_MAX, mstSet[i]=false;

	parent[0]=-1;
	key[0]=0;

	for(int k=0; k<V; k++){
		int u=minKey(key, mstSet);
		mstSet[u] = true;

		for(int v=0; v<V; v++){
			if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
				parent[v]=u, key[v]=graph[u][v];
		}

	}

	printMST(parent, graph);
}


void printMST(int parent[V], int graph[V][V]){
	printf("Edges \t\tWeight\n");
	for(int i=1; i<V; i++){
		printf("%d -- %d\t\t%d\n", i, parent[i], graph[i][parent[i]]);
	}
}

int minKey(int key[V], bool mstSet[V]){
	int min=INT_MAX, min_index;
	for(int i=0; i<V; i++)
		if(mstSet[i]==false && min>key[i])
			min=key[i], min_index=i;
	return min_index;	
}
