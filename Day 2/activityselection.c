#include <stdio.h>

struct activity
{
	int start, finish, duration;
};

void activitySelect(struct activity *a, int n);

int main()
{
	int n=10;
	//struct activity a[]= {{2,3,1}, {3,4,1}, {1,5,4}, {4,6,2}, {5,7,2}, {6,8,2}, {8,10,2}, {7,11,4}, {9,12,3}, {10, 13, 3}};
	struct activity a[] = {{1,5,4}, {2,3,1}, {3,4,1}, {4,6,2}, {5,7,2}, {6,8,2}, {7,11,4}, {8, 10, 2}, {9,12,3}, {10, 13, 3}};
	activitySelect(a, n);
	

}

void activitySelect(struct activity *a, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j].finish > a[j+1].finish)
			{
				struct activity temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				
			}
		}		
	}	
	
	int index=0;
	struct activity A[n];
	A[index++] = a[0];
	int k=0;
	for(int i=1; i<n; i++)
	{
		if (a[i].start >= a[k].finish)
		{
			A[index++] = a[i];
			k=i;
		}
	}
	for(int i=0; i<index; i++)
	{
		printf("%d, %d, %d\n", A[i].start, A[i].finish, A[i].duration);
	}
}



