#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//???使用多行注释 
//读入两个字符串s1和s2，比较这两个字符串。若s1>s2，输出一个正数；若s1=s2，输出0；若s1<s2，输出一个负数。
//输出的非零值应该是相比较的两个字符串第一个不相同位置的字符ASCII差值，例如”And”和”Aid”比较，
//根据第2个字符的比较结果，应输出5。要求不要使用strcpy和strcmp函数。
void dingDing(){
	//??? 输入  123 1234  输出错误是 0  这种情况没有考虑到 
	char s1[101],s2[101];
	gets(s1);
	gets(s2);
	//scanf("%s%s",s1,s2);  
//	int del,i=0,flag=1;
//	while(s1[i]!='\0'&&s2[i]!='\0'){
//		if(s1[i]!=s2[i]){
//			printf("%d\n",s1[i]-s2[i]);
//			flag=0;
//			break;
//		}
//		i++;
//	}
//	if(flag){
//		printf("0\n");
//	}
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0'&&s2[i]!='\0'){
		i++;
	}
	printf("%d\n",s1[i]-s2[i]);
} 

/*
一样长的情况： 
1 1
12 12
123 124
132 123
321  231

不一样长的情况： 
123 12
12 123
*/

void version2(){	
	char s1[101],s2[101];
	gets(s1);
	gets(s2);
	int i=0;
	while(s1[i]!='\0'&&s2[i]!='\0'&&s1[i]==s2[i]){
		i++; 
	} 
	printf("%d\n",s1[i]-s2[i]);
	 
}
int main(){
	//dingDing();
	version2();
	return 0;
}
