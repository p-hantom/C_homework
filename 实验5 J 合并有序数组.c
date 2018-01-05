/*
J: 合并有序数组
描述
 
合并两个有序数组a={1,3,5},b={2,4,6}。
 
输入
 
无
 
输出
 
保证两个数组合并后依然有序，并输出合并后的结果。
 
样例
 
输入
输出
1 2 3 4 5 6
 
*/ 

#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[]={1,3,5},b[]={2,4,6};
	int c[6]={0},i,j;
	for(i=0;i<3;i++){
		c[i]=a[i];
	}
	for(i=3;i<6;i++){
		c[i]=b[i-3];
	}
	
	for(i=0;i<5;i++){
		for(j=i+1;j<6;j++){
			if(c[i]>c[j]){
				int temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
	for(i=0;i<6;i++){
		printf("%d ",c[i]);
	}
	
	return 0;
}

