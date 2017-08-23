#include <stdio.h>

struct job
{
	int deadline, profit;
};

void jobSequence(struct job *, const int);

int main()
{
	int n=9;
	//struct job j[]= {{5,30}, {3,25}, {2,23}, {2,20}, {3,18}, {4,18}, {7,16}, {7,15}, {5,10}};
	struct job j[]={{7,15}, {2,20}, {5,30}, {3,18}, {4,18}, {5, 10}, {2, 23}, {7,16}, {3,25}};
	jobSequence(j, n);
	
}

void jobSequence(struct job *jobs, const int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(jobs[j].profit < jobs[j+1].profit)
			{
				struct job temp = jobs[j];
				jobs[j] = jobs[j+1];
				jobs[j+1] = temp;
				
			}
		}		
	}
	
	int x[n], maxDeadline=jobs[0].deadline;
	for(int i=0; i<n; i++)
	{
		 x[i] =0;
		 if(jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
	}
	
	int slot[maxDeadline];
	for(int i=0; i<maxDeadline; i++) slot[i] =0;
	
	for(int i=0; i<n; i++)
	{
		int k=jobs[i].deadline;
		while(k>0)
		{
			if(slot[k-1]==0)
			{
				slot[k-1] = 1;
				x[i]=1;
				break;
			}
			k--;
		}
	}
	int profit=0;
	for(int i=0; i<n; i++)
	{	
		if(x[i]==1)
		{
			profit += jobs[i].profit;
		}
		printf("%d ", x[i]);
	}
	printf("\nTotal profit = %d\n", profit);	
}

