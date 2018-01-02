/*
E: 中间数
描述
 
在一个整数序列a1, a2, …, an中，如果存在某个数，大于它的整数数量等于小于它的整数数量，则称其为中间数。在一个序列中，可能存在多个下标不相同的中间数，这些中间数的值是相同的。
给定一个整数序列，请找出这个整数序列的中间数的值。
 
输入
 
　　输入的第一行包含了一个整数n，表示整数序列中数的个数。
　　第二行包含n个正整数，依次表示a1, a2, …, an。
 
输出
 
如果约定序列的中间数存在，则输出中间数的值，否则输出-1表示不存在中间数。
 
样例
 
输入
输出
6
2 6 5 6 3 5
5
 
 
样例说明
 
　　比5小的数有2个，比5大的数也有2个。
 
样例
 
输入
输出
4
3 4 6 7
-1
 
 
样例说明
 
　　在序列中的4个数都不满足中间数的定义。
 
样例
 
输入
输出
5
3 4 6 6 7
-1
 
 
样例说明
 
　　在序列中的5个数都不满足中间数的定义。
 
评测用例规模与约定
 
　　对于所有评测用例，1 ≤ n ≤ 1000，1 ≤ ai ≤ 1000。

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* insert(int *a,int n);
int mid(int *a,int n);

int main(){
	int n,i;
	scanf("%d",&n);
	
	int *a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	insert(a,n);
	printf("%d\n",mid(a,n));
	
	free(a);
	
	return 0;
}

int mid(int *a,int n){
	int rnt=-1,mid=n/2;
	if(n<=2){
		return -1;
	}
	int i=0,j=n-1,x=0,y=0;
	while(a[i]<a[mid]){
		i++;
		x++;
	}
	while(a[j]>a[mid]){
		j--;
		y++;
	}
	if(x==y){
		rnt=a[mid];
	}
	
	return rnt;
}

int* insert(int *a,int n){  //从小到大 
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	return a;
}

