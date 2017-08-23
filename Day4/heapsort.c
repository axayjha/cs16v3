#include <stdio.h>

int left(int);
int right(int);
void maxHeapify(int *, int, int);
void buildmaxheap(int *, int );
void heapsort(int *a, int n);
void swap(int *, int *);

int main()
{
	int a[]={6,5,4,4,3,45};
	heapsort(a, 6);
	for(int i=0; i<6; i++)
		printf("%d ", a[i]);
	printf("\n");	
}

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i + 2;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}
void maxHeapify(int *a, int n, int i)
{
	int largest = i;
	int l = left(i);
	int r = right(i);
	
	if(l<n && a[l] > a[largest])
		largest = l;
	if(r<n && a[r]>a[largest])
		largest=r;
		
	if(largest!=i)
	{
		swap(a+i, a+largest);
		maxHeapify(a, n , largest);
	}		
}

void heapsort(int *a, int n)
{
	buildmaxheap(a, n);
	for(int i=n-1; i>=0; i--)
	{
		swap(a, a+i);
		maxHeapify(a, i, 0);
	}
}

void buildmaxheap(int *a, int n)
{
	for(int i=n/2 -1;i>=0; i--)
	{
		maxHeapify(a, n, i);	
	}
}
