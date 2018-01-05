/*
G: 字符串排序
描述
输入一串字符串，按字母的ascii顺序将它们升序排序输出。（字符串长度n<1000）
请实现相应的函数：void sortChar(char *p,int n);
其中p为指向字符串的指针，n为字符串的长度。

输入
字符串
 
输出
排序后的字符串
 
样例
输入                                                              输出
acdb                                                             abcd
4312                                                             1234

提示
计算字符串长度的方法：1. strlen 函数（在头文件string.h中）, 2.也可自己实现求字符串长度的方法
排序方法：可以参考书上的简单选择排序的方法.
提示代码：
#include<stdio.h>
#include<string.h>
void sortChar(char *p,int n) {
//函数定义
}
int main(){
   char string[1000];//用于接收字符串
   //待实现
   return 0;
}
*/ 

#include <stdio.h>
#include <string.h>
void sortChar(char *a,int n) {
	int i,j,k;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[k]){
				k=j;
			}
		}
		if(k!=i){
			char temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}
}

int main(){
   char string[1000];//用于接收字符串   
   int i;
   scanf("%s",string);
   
   int n=strlen(string);
   sortChar(string,n);
   
   for(i=0;i<n;i++){
   	printf("%c",string[i]);
   }
   
   return 0;
}
