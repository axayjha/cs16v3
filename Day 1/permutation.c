/*
WAP to print all the permutations of an set of numbers
*/

#include <stdio.h>

void permute(int *,int ,int);
void printArray(int *, int);
void swap(int *, int *);

int main()
{
    int a[] = {1,2,3};
    permute(a, 0, 3);
}

void permute(int *array, int i, int length) { 
  if (length == i)
  {
     printArray(array,length);
     return;
  }

  for (int j = i; j < length; j++) 
  { 
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
  }
  return;
}

void printArray(int *array, int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
OUTPUT

1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2

*/