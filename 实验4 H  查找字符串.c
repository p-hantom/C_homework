/*
H: 查找字符串
描述
输入一组字符串，请从该字符串数组中找出指定的字符串（每个字符串长度n<100，输入的字符串个数m不会超过10个）
请实现相应的函数：int findString(char stringArray[][100],char *targetString,int n);
其中stringArray为字符串数组，
targetString为要找的字符串，
n是输入的字符串个数，
返回值是目标字符串出现的次数。

输入
数字m（表示输入的字符串个数）
字符串1
字符串2
字符串3
...
字符串m
目标字符串

输出
目标字符串出现次数
 
样例
 
输入
输出
3
abc
def
john
def
1





输入
输出
3
abc
def
john
tom
0
输入
输出
3
abc
abc
john
abc
2

提示
比较两个字符串是否相等的函数：strcmp(char * str1, char * str2),如果两个字符串相等则返回0，否则返回非0。
提示代码：
#include<stdio.h>
int findString(char stringArray[][100], char * targetString, int n) {
   //函数定义
}
int main(){
   char stringArray[10][100];//接收字符串的数组
   char targetString[100];//接收待查找的字符串
   //待实现
   return 0;
}
*/ 

#include <stdio.h>
#include <string.h>

int findString(char stringArray[][100], char * targetString, int n) {
	int i,num=0;
	for(i=0;i<n;i++){
		if(strcmp(stringArray[i],targetString)==0){
			num++;
		}
	}
	return num;
}

int main(){
   char stringArray[10][100];
  // ={"ab","ddd","abc"};//接收字符串的数组
   //stringArray[]={"abc","ddd","abc"};
   char targetString[100];
   //="abc";//接收待查找的字符串
   //targetString="abc";
   
   int i,n;//m:字符串个数 
   
   scanf("%d",&n);
   
   for(i=0;i<n;i++){
   		scanf("%s",&stringArray[i]);
   		//printf("%s\n",stringArray[i]);
   }
   
   //gets(targetString);//??????执行不了 
   scanf("%s",targetString);
   printf("%d\n",findString(stringArray,targetString,n));
   return 0;
}

