#include <stdio.h>
int gcd(int, int);

int main()
{
    int a, b;    
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD = %d\n", gcd(a,b));
    
}

int gcd(int x, int y)
{
    if(y%x==0)
        return x;
    else    
        return gcd(y, x%y);    
}