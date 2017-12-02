#include<stdio.h>
int G[100][100];
int totalcount = 0;
int getnodecolour(int k, int *x, int m, int n){
	int j;
	do{
		x[k] = ((x[k]+1)%(m+1));
		if(x[k]==0){
			return x[k];
		}

		for(j=1;j<=n;j++){
			
			if(G[k][j]!=0 && x[k]==x[j]){
				
				break;

			}
		}
		if(j==n+1){
			return x[k];
		}

	}while(1);
}
void mcolouring(int k, int* x, int n,int m){
    do{
	x[k] = getnodecolour(k,x,m,n);
	
	if(x[k]==0){
		return;
	}
	if(k==n){
		for(int i = 1;i<=n;i++){
			printf("%d ",x[i]);
            
		}
        totalcount++;
		printf("\n");
	}
	else{
		mcolouring(k+1,x,n,m);
	}
    }while(x[k]<=n);
}

int main(){
	int n,m,i,j,k,e;
	int x[101];
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	m = n;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) G[i][j] = 0;
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	printf("Enter start and end vertex if the exist in the graph\n");
	for(i=1;i<=e;i++){
		scanf("%d%d",&j,&k);
		G[j][k] = 1;
		G[k][j] = 1;
	}
	//for(i=1;i<=n;i++) for(j=1;j<=n;j++) printf("%d",G[i][j]);
	for(i=1;i<=n;i++) x[i] = 0;
	mcolouring(1,x,n,n);
    printf("Enter the total number of solutions = %d\n", totalcount);
}
