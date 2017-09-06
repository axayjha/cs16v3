#include <stdio.h>
#define INF 999999
int min(int a, int b)
{
	return a>b?b:a;
}

int main()
{
	int d[3][3]={{0,4,11},{6,0,2},{3,INF,0}};
	int p[3][3] = {{-1,1,1}, {2,-1,2},{3,-1,-1}};
	int n=3;
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				int D=d[i][j];
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				if(D!=d[i][j])
					p[i][j] = k+1;
			}
		}
	}
	printf("Distance matrix:\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\nPredecessor matrix: \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(p[i][j] ==-1)
				printf("N ");
			else printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	
}

