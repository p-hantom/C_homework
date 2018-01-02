/*
D: Zig-Zag模式填充矩阵
描述

在一个m*n的数组中，按照Zig-Zag的顺序依次填写1,2,3,...m*n。



输入

两个整数m,n表示m*n的矩阵，整数间以空格隔开。2<=m,n<100

输出

输出矩阵

样例1
输入
3 3
输出
1 2 6
3 5 7
4 8 9
样例2
输入
2 3
输出
1 2 5
3 4 6


*/ 

#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[100][100]={0} ;
	int i,j,k,m,n;
	//m=3;
	//n=3;
	scanf("%d%d",&m,&n);
	
	int pre=0,next,flag=1;
	
	i=0;j=0;
	for(k=1;k<=m*n;k++){
		a[i][j]=k;
		if(i==0 && j==0){//左上角 
			next = 1;
		}
		else if(i==0 && j==n-1){//右上角
			if(pre == 1){
				next = 2;
			}
			else{
				next = 3;
			}
		}
		else if(i==m-1 && j==0){//左下角
			if(pre == 3){
				next = 4;
			}
			else{
				next = 1;
			}
		}
		else if(i==0){//第0行 
			if(pre==1){
				next =2;
			}
			else if(pre == 4){
				next = 1;
			}
		}
		else if(j==0){//第0列 
			next++;
		}
		else if(j==n-1){//末列 
			next--;
		}
		else if(i==m-1){//末行
			if(pre == 2) {
				next =1;
			}
			else if(pre == 1 ||pre == 3){
				next =4;
			}		
		} 
		switch(next){
			case 1:
				j++;
				break;
			case 2:
				i++;j--;
				break;
			case 3:
				i++;
				break;
			case 4:
				i--;j++;
				break;
	    }
	    pre = next;
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");	
	}
	
	return 0;
}

