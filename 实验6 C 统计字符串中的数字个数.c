/*
C: 统计字符串中的数字个数
描述
输入一串字符串，统计里面有几个数字(连续的数字算一个数字）。
例如输入asdad12asda43eftr45-23-3--22-，输出6。
12，43，45，23，3，22为该字符串的6个数字。

输入
第一行是输入输入一串字符串。

输出
输出字符串中数字个数。
样例
输入
23frw90ewe3**325%
输出
4
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dingDing(){//？？？如果换成while循环，则逻辑更简单！！！！！ 
//	char s[]="1asdad12asda43eftr45-23-3--22-";
//	//gets(s);
//	int i,sum=0,len=strlen(s),flag;//??? flag 没有初始化！！ 
//	for(i=0;i<len;i++){
//		if(s[i]>='0'&&s[i]<='9'){
//			if(flag){
//				sum++;
//			}
//			flag=0;			
//		}
//		else{
//			flag=1;
//		}
//	}
//	printf("%d\n",sum);
	char s[]="12asdad12asda43eftr45-23-3--22-";
	int i=0,sum=0;
	while(s[i]!='\0'){
		if(s[i]>='0'&&s[i]<='9'){
			while(s[i]>='0'&&s[i]<='9'){
				i++;				
			}
			sum++;
		}
		
		i++;
	}
	printf("%d\n",sum);
} 


int main(){
	char s[]="12asdad12asda43eftr45-23-3--22-";
	//gets(s);
//	int i,sum=0; 
//	i=0;
//	while(s[i]!='\0'){
//		if(s[i]>='0' && s[i]<='9'){
//			sum ++;			
//			while(s[i]!='\0' && s[i]>='0' && s[i]<='9'){
//				i++;
//			}
//		}
//		i++;
//	}
//	 
//	printf("%d\n",sum);
	dingDing();
	
	return 0;
}

