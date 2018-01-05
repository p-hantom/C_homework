/*
E: 选择排序
 
描述

输入n个整数，使用选择排序算法按从小到大排序，然后输出结果。

输入
 
一行是1个整数n，表示随后有n个整数，第二行有n个整数，空格隔开。 
 
输出
 
输出结果有n-1行，每行为排序一趟后的结果。
 
样例
 
输入

5
1 5 4 3 2

输出
1 5 4 3 2
1 2 4 3 5
1 2 3 4 5
1 2 3 4 5
 
提示
 
选择排序工作原理是每一次从待排序的数据中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。


*/ 

#include <stdio.h>
#include <stdlib.h>

void f();
void f_li(){
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	
//	n=5;
//	 int a[]={1,5,4,3,2};
	
	int i,j,k,l;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int temp,min,minIdx;
	for(i=0;i<n-1;i++){
		min=a[i];
		minIdx=i;
		for(j=i+1;j<n;j++){
			if(a[j]<min){
				min=a[j];
				minIdx=j;
			}			
		}
		if(minIdx!=i){
			temp = a[i];
			a[i]=a[minIdx];
			a[minIdx]=temp;
		}	
		for(k=0;k<n;k++){
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	free(a);
}
int main(){

//	f();
	f_li();
	return 0;
}

void f(){
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	
	//int a[]={5,1,3,2,4};
	
	int i,j,k,l;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int temp;
	for(i=0;i<n-1;i++){
		temp=a[i];
		for(j=i+1;j<n;j++){
			if(a[j]<temp){
				temp=a[j];
				l=j;
			}			
		}
		if(a[i]!=temp){
			for(k=l-1;k>=i;k--){
				a[k+1]=a[k];
			}
			a[i]=temp;
		}		
		for(k=0;k<n;k++){
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	free(a);
}


