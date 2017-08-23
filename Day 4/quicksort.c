#include <stdio.h>
int partition(int *, int, int);
void quicksort(int *, int, int);
void swap(int *, int *);
int main()
{
	int a[]={6,5,4,4,3,45};
	quicksort(a, 0, 5);
	for(int i=0; i<6; i++)
		printf("%d ", a[i]);
	printf("\n");	
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int partition(int *A, int p, int r)
{
	int x = A[r];
	int i=p-1;
	for(int j=p; j<r; j++)
	{
		if(A[j] <=x)
		{
			i++;
			swap(A+i, A+j);
		}
	}
	swap(A+i+1, A+r);
	return i+1;
}

void quicksort(int *a, int p, int r)
{
	if(p<r)
	{
		int q=partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
}
