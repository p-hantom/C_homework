#include <stdio.h>
#include <stdlib.h>
//find the second smallest integer

int find(int *a,int len){
	if(a<2)
		return NULL;
		//未考虑全部相等情况 
	
	int i,min=a[0],flag=1;
	for(i=1;i<len;i++){
		if(min>a[i]){
			min=a[i];			
		}
		if(a[i-1]!=a[i])
			flag=0;
	}
	if(flag){
		return NULL;
	}

	int min2=a[0];
	i=0;
	while(min2==min){
		i++;
		min2=a[i];
		
	}
	for(i=1;i<len;i++){
		if(a[i]>min&&min2>a[i]){
			min2=a[i];
		}
//		if(min2!=i&&){       //此处逻辑。。。待改进！ 
//			min2=a[i];
//		}
	}
	
	return min2;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	
	int *b=(int *)malloc(sizeof(int)*n);//保存每组的结果 
	for (i=0;i<n;i++){
		int num;//每组有几个元素
		scanf("%d",&num);
		int *a=(int *)malloc(sizeof(int)*num);
		
		for(j=0;j<num;j++){
			scanf("%d",&a[j]);
		}
		
		b[i]=find(a,num);
		
		free(a);
	}
	
	for(i=0;i<n;i++){
		if(b[i]==NULL){
			printf("ERROR");  //未完善 
		}
		else{
			printf("%d\n",b[i]);
		}
	}
	free(b);
	
	return 0;
}
