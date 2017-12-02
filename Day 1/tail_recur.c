#include <stdio.h>

int sum(int x)
{
	/* sums upto x */
	if(x<=1) return x;
	else return x+sum(x-1);
}

int _sum(int x, int res=0)
{
	if(x==0) return res;
	else return _sum(x-1, res+x);
}

int main()
{
	printf("%d\n", _sum(5));
}