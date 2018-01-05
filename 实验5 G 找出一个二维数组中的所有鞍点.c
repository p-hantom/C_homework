/*
G: 找出一个二维数组中的所有鞍点
 
描述

找出一个二维数组中的所有鞍点，即该位置上的元素在该行中最大但是在该列中最小。需要注意有可能鞍点不存在，此时需要输出“NO”。 
 
输入
 
第一行输入2个正整数n和m，表示二维数组a[n][m]，保证n和m均不超过50。之后输入n行每行有m个用空格隔开的整数，表示二维数组对应位置的值。
 
输出
 
当鞍点存在时，将每个鞍点的信息在一行内输出。有多个鞍点时，按照元素读入的顺序进行输出。当鞍点不存在时，在一行内输出“NO”。注意行尾输出换行。
 
样例
 
输入
输出
2 3
23 83 15  99 98 97
a[0][1]=83  
 

*/ 

#include <stdio.h>
#include <stdlib.h>
//该位置上的元素在该行中最大但是在该列中最小。需要注意有可能鞍点不存在，此时需要输出“NO”。

int f(int max,int j,int n,int (*a)[50]){
	int i,k,min=max,flag=1;
	for(i=0;i<n;i++){
		if(a[i][j]<min){
			flag=0;
		}
	}
	return flag;
}

int main(){
	int a[50][50];//={{23,83,15},{99,98,97}};
	int m,n,i,j;
	//m=3;n=2;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int min,max,flag=1;
	for(i=0;i<n;i++){
		max=a[i][0];
		for(j=0;j<m;j++){
			if(max<a[i][j]){
				max=a[i][j];//第i行最大 
				if(f(max,j,n,a)){
					printf("a[%d][%d]=%d\n",i,j,a[i][j]);
					flag=0;
				}
			}
		}
	}
	if(flag){
		printf("NO\n");
	}
	
	return 0;
}

