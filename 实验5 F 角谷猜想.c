/*
F: 角谷猜想
 
描述

对于一个数n，如果是偶数，就把n砍掉一半；如果是奇数，把n变成 3*n+ 1后砍掉一半，直到该数变为1为止。计算需要经过几步才能将n变到1。
 
输入
 
第一行是1个整数T，表示随后有T个整数，每个整数占一行。 
 
输出
 
经过的步数。若n=1，则步数为0。
 
样例
 
输入

2
7
1

输出
11
0


*/ 

#include <stdio.h>
#include <stdlib.h>

int count=0;
void f2(int n){
	if(n==1){
		return;
	}
	
	if(n%2==0){	
		n /= 2;			
		f2(n);
	}
	else{
		n=(3*n+ 1)/2;		 
		f2(n);
	}
	count++;
}


int f(int n){
	int cnt=0;

	while(n!=1){
		if(n%2==0){
			n/=2;
			cnt++;
		}			
		else{
			n=(3*n+ 1)/2;
			cnt++;
		}			
	}
	return cnt;
}

int main(){
	f2(7);
//	int n,cnt=0,t,i;
//	//f(1);
//	scanf("%d",&t);
//	for(i=0;i<t;i++){
//		scanf("%d",&n);
//		count=0;
//		f2(n);
//		printf("%d\n",count);
//	}
//	
	return 0;
}

