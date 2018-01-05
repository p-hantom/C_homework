/*
A: 回文数
描述
程序中输入一个正整数，请判断他是否为回文数。

提示：回文数：类似1234321，123321等这样，顺序和逆序相同的整数称为回文数。

输入
一个正整数n。

输出
若n是回文数，输出Yes，否则输出No。

样例1
输入             输出
1231             No

样例2
输入            输出
12321            Yes

*/ 

#include <stdio.h>
#include <stdlib.h>

int huiwen(int n);

int main(){
	int n;
	scanf("%d",&n);
	if(huiwen(n)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}

int huiwen(int n){
	int i=0,flag=1,num=0,n1=n;//is a huiwen
	while(n1!=0){
		//int x=n1%10;
		n1/=10;
		num++;
	}
	int *a=(int*)malloc(sizeof(int)*num);
	i=0;
	while(n!=0){
		int x=n%10;
		//printf("%d ",x);
		n/=10;
		a[i]=x;
		//printf("%d ",a[i]);
		i++;
		
	}
	int j;
	for(j=0;j<num;j++){
		if(a[j]!=a[num-j-1]){
			flag=0;
		}
	}
	free(a);
	
	return flag;
}

