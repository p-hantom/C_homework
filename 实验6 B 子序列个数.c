/*
B: 子序列个数
描述
输入两个字符串str1和str2，判断字符串str1包含字符串str2的个数，允许重叠。
例如：
01101010101
1010
输出3。

输入
分别输入两个字符串str1和str2，分别占一行。

输出
输出str1包含str2的个数。

样例
输入
ababababac
abab
输出
3
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//输入两个字符串str1和str2，判断字符串str1包含字符串str2的个数，允许重叠。
//例如：
//01101010101
//1010
//输出3。

int main(){
	char s1[101];//="01101010101";
	char s2[101];//="1010";	
	gets(s1);
	gets(s2);
	int l1=strlen(s1),l2=strlen(s2);
	int i,j,sum=0;
	int flag;
	for(i=0;i<l1;i++){
		flag=1;
		for(j=i;j<i+l2;j++){			
			if(s2[j-i]!=s1[j]){
				flag=0;break;
			}
		}
		if(flag){
			sum++;
		}
	}
	printf("%d\n",sum);
	
	return 0;
}

