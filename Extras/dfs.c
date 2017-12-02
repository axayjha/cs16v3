#include <stdio.h>
int wt[10][10],p[10],time,color[10],d[10],n;
void dfs_visit(int wt[][10],int u)
{
	int v;
	color[u]=0;
	time++;
	d[u]=time;
	printf("%d ",u);
	for(v=1;v<=n;v++)
	{
		if(wt[u][v])
		{
			if(color[v]==-1)
			{
				p[v]=u;
				dfs_visit(wt,v);
			}
		}
	}
	color[u]=1;
	time++;
}	
void dfs(int wt[][10])
{
        int u;
        //printf("enter start vertex\n");
        //scanf("%d",&s);
        for(u=1;u<=n;u++)
        {
                color[u]=-1;
                d[u]=999;
                p[u]=999;
        }
        time=0;
	for(u=1;u<=n;u++)
	{
		if(color[u]==-1)
			dfs_visit(wt,u);
	}
}
int main()
{
	int i,j;
	printf("enter n\n");
        scanf("%d",&n);
        printf("enter adjacency matrix\n");
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        scanf("%d",&wt[i][j]);
                }
        }
	dfs(wt);
}
