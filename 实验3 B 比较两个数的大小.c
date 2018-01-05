/*
B: 比较两个数的大小
描述
编写一个函数，比较两个十六进制数(表示形式为0x****，其中*为0-9和a-e。并且，本题的所有字母均为小写)的大小。
注：函数签名为int hexcmp(char* hex1, char* hex2);

输入
两个十六进制数a和b。

输出
若a>b，输出1；a<b，输出-1；a=b，输出0。

样例
输入	输出
0x1234	-1
0x1235	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//若a>b，输出1；a<b，输出-1；a=b，输出0。
int hexcmp(char* hex1, char* hex2);

int main(){
	char a[7],b[7];
	int i,j;

//	for(i=0;i<6;i++){
//		scanf("%c",&a[i]);
//	}
//	for(i=0;i<6;i++){
//		scanf("%c",&b[i]);
//	}
	scanf("%s",a);
	scanf("%s",b);
//	printf("%s\n",a);
//	printf("%s\n",b);
	printf("%d\n",hexcmp(a,b));		
	return 0;
}

int hexcmp(char* hex1, char* hex2){
	int rnt=0,i;
	for(i=2;i<6;i++){
		if(hex1[i]>hex2[i]){
			rnt=1;
			break;
		}
		else if(hex1[i]<hex2[i]){
			rnt=-1;
			break;
		}
	}
	
	return rnt;
}

