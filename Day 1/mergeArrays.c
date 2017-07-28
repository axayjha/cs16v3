#include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter the elements of the first array: \n");
    for(int i=0; i<n1; i++)
        scanf("%d", &a[i]);

    printf("Enter the size of the second array: ");
    scanf("%d ", &n2);
    int b[n2];
    printf("Enter the elements of the second array: \n");
    for(int i=0; i<n2; i++)
        scanf("%d", &b[i]);

    int m=n1+n2;
    int c[m];

    for(int i=0; i<m; i++)
    {
        if(i < n1) c[i] = a[i];
        else c[i] = b[i-n1];
    }    

    printf("Merged array: \n");
    for(int i=0; i<m; i++)
        printf("%d ", c[i]);

}