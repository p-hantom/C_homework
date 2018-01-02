/*
C: 十六进制转十进制
描述
编写一个函数将四位十六进制数(表示形式为0x****，*为0-9和a-f，均为小写)转成十进制数。
注：函数签名为int hexToDecimal(char* hex);

输入
一个十六进制数。

输出
该十六进制数对应的十进制数。

样例
输入	输出
0x0001	1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hexToDecimal(char* hex);

int main(){
	char a[6],i;
	for(i=0;i<6;i++){
		scanf("%c",&a[i]);
	}
	printf("%d\n",hexToDecimal(a));
	
	return 0;
}

int hexToDecimal(char* hex){
	int dcm=0,i,j=3,temp=16*16*16;
	for(i=2;i<6;i++){
		if(hex[i]>='a'){
			dcm+=temp*(hex[i]-'a'+10);
		}
		else{
			dcm+=temp*(hex[i]-'0');
		}
		temp/=16;
	}
	
	return dcm;
}

