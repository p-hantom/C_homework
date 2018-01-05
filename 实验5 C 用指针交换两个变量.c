/*
C: 用指针交换两个变量
描述

请实现如下给定的函数，该函数形参是两个指针，实现将两个指针指向的两个变量值交换。
void swapByPointer(int *A, int *B);
请完善该函数的定义，并在main函数中调用。

输入
 
两个int类型的数值
 
输出
 
交换值后两个数的值
 
样例
 
输入
输出
1 2
2 1

*/ 

#include <stdio.h>
#include <stdlib.h>

//对于一个数n，如果是偶数，就把n砍掉一半；如果是奇数，把n变成 3*n+ 1后砍掉一半，直到该数变为1为止。
//计算需要经过几步才能将n变到1。 
//输入
//第一行是1个整数T，表示随后有T个整数，每个整数占一行。 
//输出
//经过的步数。若n=1，则步数为0。

int f(int n){
	int cnt=0;
//	if(n==1){
//		return cnt;
//	}
//	if(n%2==0){
//		cnt++;
//		return f(n/2);
//	}
//	else{
//		cnt++;
//		return f((3*n+ 1)/2);
//	}
	while(n!=1){
		if(n%2==0)
			n/=2;
		else
			n=(3*n+ 1)/2;
			cnt++;
	}
	return cnt;
}

int main(){
	int n,cnt=0,t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		printf("%d ",f(n));
	}
	
	return 0;
}

