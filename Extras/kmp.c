#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f[100];
void kmp_failure(char* p){
	int i = 1;
	int j = 0;
	int m = strlen(p);
	f[0] = 0;
	while(i<m){
		if(p[j]==p[i]){
			f[i] = j + 1;
			i = i + 1;
			j = j + 1;	
		}else if(j>0){
			j = f[j-1];
		}else{
			f[i] = 0;
			i = i + 1;
		}
	}
}
int main(){
	char t[100],p[100];
	printf("Enter the text\n");
	scanf("%s",t);
	printf("Enter the pattern to match\n");
	scanf("%s",p);
	int n = strlen(t);
	int m = strlen(p);
	int i = 0, j =0;
	int flag = -1;
	kmp_failure(p);
	while(i<n){
		if(p[j] == t[i]){
			if(j==(m-1)){
				printf("String match found at = %d\n", i-m+1);
				flag = 0;
				break;
				}
				i = i + 1;
				j = j + 1;
		}else if(j > 0){
			j = f[j-1];

		}else{
			i = i + 1; 

			}
	}
	if(flag){
		printf("Match not found\n");		
	}
}
