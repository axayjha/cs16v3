#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *a, int p, int r){
	int x = a[r], i = p-1;
	for(int j=p; j<r; j++)		
		if(a[j] <= x){
			i++;
			swap(a+i, a+j);			
		}
	swap(a+i+1, a+r);
	return i+1;	
}



int kth_largest(int *a, int p, int r, int k){
	if(p<r){
		int pivot = partition(a, p, r);
		if(pivot == k-1)
			return a[pivot];
		else if(pivot > k-1)
			return kth_largest(a, p, pivot-1, k);
		else
			return kth_largest(a, pivot+1, r, k);
	}
}


int main(){
	int a[] = {10, 45, 454, 30, 80, 40, 900, 100};
	printf("%d\n", kth_largest(a,0,7, 3)); // 3rd largest -> 40
}