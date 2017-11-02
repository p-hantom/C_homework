#include <stdio.h>
#include <stdlib.h>

int square(int n){
	if(n<0)
		return NULL;
	if(n==0){
		return -1;
	}
	int i,ans=100;
	//scanf("%d",&n);
	int temp=n*10000; 
	for(i=101;i<temp;i++){
		if((temp-ans*ans)>(temp-i*i)&&(temp-i*i)>0){
			ans=i;
		}
		else{
			break;
		}
	}
	
	return ans;
}

int main(){
	int num;
	scanf("%d",&num);
	int j,*b=(int*)malloc(sizeof(int)*num);
	for(j=0;j<num;j++){
		int x;
		scanf("%d",&x);
		b[j]=square(x);
	}
	
	for(j=0;j<num;j++){
		if(b[j]==NULL){
			printf("ERROR\n");
			continue;
		}
		if(b[j]==-1){
			printf("0.00\n");
			continue;
		}
		printf("%.2f\n",b[j]*1.0/100);
	}
	
	free(b);
	
	return 0;
}
