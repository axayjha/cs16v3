/* 
 02/08/2017
*/


#include <stdio.h>


struct item 
{
	int profit, weight;	
};

void knapsack(struct item *items, int M, const int n);

int main()
{
	int n=3, M=20;
	//struct item items[] = {{24,15}, {15,10}, {25,18}};
	struct item items[] = {{25,18}, {24,15}, {15,10}};		
	
	knapsack(items, M, n);
}

void knapsack(struct item *items, int M, const int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if((((float)(items[j].profit))/items[j].weight) < (((float)(items[j+1].profit))/items[j+1].weight))
			{
				struct item temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
		}		
	}
	
	
	float x[n];
	for(int i=0; i<n; i++) x[i] = 0.0;
	int i, u=M;
	for(i=0; i<n; i++)
	{
		if(items[i].weight > u)
		{
			break;			
		}
		x[i] = 1.0;
		u=u-items[i].weight;
		
	}	
	if(i<=n) x[i] = ((float)u)/items[i].weight;
	float profit=0;
	for(i=0; i<n; i++)
	{
		printf("%.2f ", x[i]);
		profit += items[i].profit * x[i];
	}
	printf("\nTotal profit = %.2f\n", profit);	
}


