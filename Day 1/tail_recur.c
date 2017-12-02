#include <stdio.h>

int sum(int x)
{
	/* recursively sums all integers from 0 upto x */
	if(x<=1) return x;
	else return x+sum(x-1);
}

/*
sum(5)
5 + sum(4)
5 + (4 + sum(3))
5 + (4 + (3 + sum(2)))
5 + (4 + (3 + (2 + sum(1))))
5 + (4 + (3 + (2 + 1)))
15

*/


int _sum(int x, int res=0)
{
	/* same function with tail recursion */
	if(x==0) return res;
	else return _sum(x-1, res+x);
}


/*
_sum(5, 0)
_sum(4, 5)
_sum(3, 9)
_sum(2, 12)
_sum(1, 14)
_sum(0, 15)
15

*/

int main()
{
	printf("%d\n", _sum(5));
}


/*
Explanation (From stack overflow )
--------------------------------------
In traditional recursion, the typical model is that you perform your 
recursive calls first, and then you take the return value of the recursive 
call and calculate the result. In this manner, you don't get the result of 
your calculation until you have returned from every recursive call.

In tail recursion, you perform your calculations first, and then you execute 
the recursive call, passing the results of your current step to the next 
recursive step. This results in the last statement being in the form of 
"(return (recursive-function params))" (I think that's the syntax for Lisp).
 Basically, the return value of any given recursive step is the same as the 
 return value of the next recursive call.

The consequence of this is that once you are ready to perform your next 
recursive step, you don't need the current stack frame any more. This allows 
for some optimization. In fact, with an appropriately written compiler, you 
should never have a stack overflow snicker with a tail recursive call. Simply
reuse the current stack frame for the next recursive step.

*/
