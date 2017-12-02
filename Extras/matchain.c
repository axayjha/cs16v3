#include <stdio.h>
#include <limits.h>

int n;
void matchain(int *p, int n);
void printParen(int s[n][n], int i, int j);

int main()
{
	int p[]= {10,20,50,1,100};
	n = sizeof(p)/sizeof(p[0]);
	matchain(p, n);
}


void matchain(int *p, int n)
{
	int m[n][n], s[n][n];
	for(int i=01; i<n; i++)
		m[i][i] = 0;

	for(int l=2; l<n; l++)
	{
		for(int i=1; i< n-l-1; i++)
		{
			int j = i+l-1;
			m[i][j] = INT_MAX;

			for(int k=0; k<=j; k++)
			{
				int q = m[i][k] + m[k][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
 		}
	}

	printf("Min no of mul = %d\n", m[1][n-1]);
	printParen(s, i, n-1);
}

void printParen(int s[n][n], int i, int j)
{
	if(i==j)
	{
		printf("A%d", i);
		return;
	}
	printf("(");
	printParen(s, i , s[i][j]);
	printParen(s, s[i][j]+1, j)
	printf(")");
}