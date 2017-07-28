/* Day 1
 *
 * Write a recursive function to find a number in an array using binary search
 *
 */

#include <stdio.h>

void sort(int*, int);
void swap(int *, int *);
void binarySearch(int *, int, int, int);

int main()
{
   int length, number;
 
   printf("Enter the length of the array: ");
   scanf("%d", &length);
   
   int array[length];
 
   printf("Enter %d elements of the array:\n", length); 
   for (int i = 0; i < length; i++) scanf("%d", &array[i]);
   sort(array, length);
   printf("Enter number to find: ");
   scanf("%d", &number);
    
   binarySearch(array, 0, length, number);
  
}


void binarySearch(int *arr, int start, int end, int num)
{
    if(start==end)
    {
        printf("Not Found\n");
        return;
    }
    int mid = start + ((end-start)/2);

    if(num == arr[mid])
    {
        printf("Found!\n");
        return;
    }
    else if(num < arr[mid])
        binarySearch(arr, start, mid-1, num);

    else    
        binarySearch(arr, mid+1, end, num);
}

void sort(int* a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Output

Enter the length of the array: 6
Enter 6 elements of the array: 
1
2
3
4
5
6
Enter number to find: 3
Found!

*/
