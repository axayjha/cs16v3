/* Day 1
 *
 * Write a program to find a number in an array using binary search
 *
 */

#include <stdio.h>
 
void sort(int*, int);
void swap(int *, int *);

int main()
{
   int i, first, last, mid, length, number;
 
   printf("Enter the length of the array: ");
   scanf("%d", &length);
   
   int array[length];
 
   printf("Enter %d elements of the array:\n", length);
 
   for (i = 0; i < length; i++) scanf("%d", &array[i]);
   sort(array, length);
   printf("Enter number to find: ");
   scanf("%d", &number);
 
   first = 0;
   last = length - 1;
   
 
   while (first <= last) 
   {
   	  mid = (first+last)/2;

      if (array[mid] < number) first = mid + 1;    

      else if (array[mid] == number) 
      {
         printf("Found at location %d.\n", mid+1);
         break;
      }

      else last = mid - 1;
   }

   if (first > last)  printf("Not found\n");
  
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
Enter 6 elements of the arrayr: 
1
2
3
4
5
6
Enter number to find: 3
Found at location 3.

*/
