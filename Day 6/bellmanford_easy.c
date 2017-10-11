#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge{
	int src, dst, weight;
};

struct graph{
	int V, E;
	struct Edge* edge; 
};

typedef struct graph Graph;

Graph *createGraph(int V, int E)
{
	Graph *newG = (Graph *)malloc(sizeof(Graph));
	newG->V = V;
	newG->E = E;

	newG->edge = (struct Edge*)malloc(E*sizeof(struct Edge));
	return newG;
}

void printSol(int dist[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d  -  %d\n", i, dist[i]);
}


void bellman(Graph *graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];


	for(int i=0; i<V; i++)
		dist[i] = INT_MAX;

	dist[src]=0;

	for(int i=1; i<V; i++)
	{
		for(int j=0; j<E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dst;
			int weight = graph->edge[j].weight;

			if(dist[u]!=INT_MAX && dist[v]> dist[u] + weight)
				dist[v]=dist[u] + weight;
		}
	}
	for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dst;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }

    printSol(dist, V);
}

int main()
{

	int V = 5;  
    int E = 8;  
    Graph *graph = createGraph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].weight = -1;
 
    graph->edge[1].src = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 4;
 
    graph->edge[2].src = 1;
    graph->edge[2].dst = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].weight = 2;
 
    graph->edge[4].src = 1;
    graph->edge[4].dst = 4;
    graph->edge[4].weight = 2;
 
    graph->edge[5].src = 3;
    graph->edge[5].dst = 2;
    graph->edge[5].weight = 5;
 
    graph->edge[6].src = 3;
    graph->edge[6].dst = 1;
    graph->edge[6].weight = 1;
 
    graph->edge[7].src = 4;
    graph->edge[7].dst = 3;
    graph->edge[7].weight = -3;
 
    bellman(graph, 0);
 

}
