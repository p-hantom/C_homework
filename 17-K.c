#include <stdio.h>

void f(){
	int k1,m,i,j;
//	m=5;k1=3;
	int a[100000];//={3,9,3,9,3};
	scanf("%d%d",&m,&k1);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	
	int k;
	for(i=0;i<m-1;i++){
		k=i;
		for(j=i+1;j<m;j++){
			if(a[j]>a[k]){
				k=j;
			}
		}
		if(k!=i){
			int temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	int cnt=0;
	for(i=1;i<m;i++){
		if(a[i-1]>a[i]){
			cnt++;
			if(cnt==k1){
				printf("%d\n",a[i-1]);
				return;
			}
		}
	}
	if(k1==m){
		if(cnt==m-1&&a[m-1]<=a[m-2]){
			printf("%d\n",a[m-1]);
		}
	}
	else if(k1==1&&cnt==0){
		printf("%d\n",a[m-1]);
	}
	else{
		printf("error\n");
	}
}

int main(){
	int n,m;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		f();
	}
	
	return 0;
}
