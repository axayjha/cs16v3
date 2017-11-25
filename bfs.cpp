#include<stdio.h>
int wt[10][10],n;
int Q[10],f=-1,r=-1;
int max=n;
void enqueue(int item)
{
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		Q[r]=item;
	}
	else
	Q[++r]=item;
}
int dequeue()
{
	return Q[f++];
}
int isempty()
{
	if(f==-1 || f>r)
	return 0;
	return 1;
}
int main()
{
	int i,j,s,u,v,color[10],p[10];
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
        color[1]=0;
        p[1]=999;
        for(i=2;i<=n;i++)
        {
        	color[i]=-1;
        	p[i]=999;
		}
		printf("enter start vertex\n");
		scanf("%d",&s);
		enqueue(s);
		while(isempty())
		{
			u=dequeue();
			printf("%d\n",u);
			for(v=1;v<=n;v++)
			{
				if(wt[u][v])
				{
					if(color[v]==-1)
					{
						color[v]=0;
						p[v]=u;
						enqueue(v);
					}
				}
			}
			color[u]=1;
		}
}
