#include <stdio.h>

int main(){
	int n,a[100][100];
	scanf("%d",&n);
	int i=0,j=0,k;
	int sum=0;
	for(k=1;k<=n;k++){
		sum+=k;
	}
	for(k=1;k<=sum;k++){
		a[i][j]=k;
		if(i==0){
			i=j+1;
			j=0;
		}
		else{
			i--;
			j++;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==0)
				break;
			printf("%d ",a[i][j]);			
		}
		printf("\n");
	}
	
	return 0;
}
