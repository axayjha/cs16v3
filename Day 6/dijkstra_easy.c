#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

void dijkstra(int graph[V][V], int src);
int minDist(int dist[V], bool sptSet[V]);
void printSol(int dist[V]);

int main()
{
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
}



void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];
	for(int i=0; i<V; i++)
		dist[i]=INT_MAX, sptSet[i]=false;

	dist[src]=0;

	for(int k=0; k<V; k++)
	{
		int u = minDist(dist, sptSet);
		sptSet[u] = true;

		for(int v=0; v<V; v++)
		{
			if(graph[u][v] && sptSet[v]==false && dist[u]!=INT_MAX && dist[v] > dist[u]+graph[u][v])
				dist[v] = dist[u] + graph[u][v];
		}

	}
	printSol(dist);
}

int minDist(int dist[V], bool sptSet[V])
{
	int min=INT_MAX,  min_index;
	for(int i=0; i<V; i++)
		if(sptSet[i] ==false && min>=dist[i])
			min=dist[i], min_index=i;

	return min_index;	
}


void printSol(int dist[V])
{
	printf("Edge -- Distance\n");
	for(int i=0; i<V; i++)
		printf("%d    --   %d\n", i, dist[i]);
}
