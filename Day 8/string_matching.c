#include <stdio.h>
#include <string.h>

int is_in(const char str[], const char substr[])
{	
	for(int i=0, n=strlen(str), m=strlen(substr); i<n-m; i++)
		for(int j=0; j<m; j++)
			if(str[i+j]==substr[j]) if(j==m-1) return i;
	return -1;
}

int main()
{
	printf("%d\n", is_in("St. Thomas' College", "Tho")); //Found at position 4
	printf("%d\n", is_in("St. Thomas' College", "education")); //Not found
}
