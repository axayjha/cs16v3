#include <stdio.h>
#define INF 99999

//void matrix_chain_order(const int p[], int m[][], int s[][], int n);
void print_optimal_parens(int s[6][6], int i, int j)
{
	if(i==j)
		printf("A%d", i);
	else
	{
		printf("(");
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j]+1, j);
		printf(")");		
	}	
}

int main()
{
	int p[]={0,10,20,50,1,100};
	int n=5;
	int m[n+1][n+1];
	int s[n][n+1];
	for(int i=1; i<=n; i++)
		m[i][i]=0;
	for(int l=2; l<=n; l++)
	{
		for(int i=1; i<=n-l+1; i++)
		{
			int j=i+l-1;
			m[i][j] = INF;
			for(int k=i; k<=j-1; k++)
			{
				int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if(q<m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i<j)
				printf("%d ", m[i][j]);
			else printf(" ");	
		}
		printf("\n");
	}
	
	for(int i=1; i<n-1; i++)
	{
		for(int j=1; j<n; j++)
		{
			if(i+1<=j)
				printf("%d ", s[i][j]);
			else printf(" ");	
		}
		printf("\n");
	}
	print_optimal_parens(s, 1, 4);
	printf("\n");
}
/*
void matrix_chain_order(const int p[], int m[][], int s[][], int n)
{
	
		
}*/

