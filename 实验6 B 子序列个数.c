/*
B: �����и���
����
���������ַ���str1��str2���ж��ַ���str1�����ַ���str2�ĸ����������ص���
���磺
01101010101
1010
���3��

����
�ֱ����������ַ���str1��str2���ֱ�ռһ�С�

���
���str1����str2�ĸ�����

����
����
ababababac
abab
���
3
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���������ַ���str1��str2���ж��ַ���str1�����ַ���str2�ĸ����������ص���
//���磺
//01101010101
//1010
//���3��

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

