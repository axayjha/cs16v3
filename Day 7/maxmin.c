#include <stdio.h>
int a[] = {3,6,2,67,2,1};
void maxmin(int i, int j, int *max, int *min)
{
	if(i==j)
	{
		*max = *min = a[i];
	}
	else if(i == (j-1))
	{
		if(a[i]<a[j])
		{
			*max = a[j]; *min = a[i];
		}
		else
		{
			*max = a[i]; *min = a[j];
		}
	}
	else
	{
		int max1, min1, mid;
		mid = (i+j)/2;
		maxmin(i, mid, max, min);
		maxmin((mid+1), j, &max1, &min1);
		if(*max<max1)*max=max1;
		if(*min>min1) *min = min1;
	}
}

int main()
{
	int min = -999999, max=999999;
	maxmin(0,5, &max, &min);
	printf("Min = %d Max = %d\n", min, max);
	

}
