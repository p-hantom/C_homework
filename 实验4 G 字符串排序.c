/*
G: �ַ�������
����
����һ���ַ���������ĸ��ascii˳����������������������ַ�������n<1000��
��ʵ����Ӧ�ĺ�����void sortChar(char *p,int n);
����pΪָ���ַ�����ָ�룬nΪ�ַ����ĳ��ȡ�

����
�ַ���
 
���
�������ַ���
 
����
����                                                              ���
acdb                                                             abcd
4312                                                             1234

��ʾ
�����ַ������ȵķ�����1. strlen ��������ͷ�ļ�string.h�У�, 2.Ҳ���Լ�ʵ�����ַ������ȵķ���
���򷽷������Բο����ϵļ�ѡ������ķ���.
��ʾ���룺
#include<stdio.h>
#include<string.h>
void sortChar(char *p,int n) {
//��������
}
int main(){
   char string[1000];//���ڽ����ַ���
   //��ʵ��
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
   char string[1000];//���ڽ����ַ���   
   int i;
   scanf("%s",string);
   
   int n=strlen(string);
   sortChar(string,n);
   
   for(i=0;i<n;i++){
   	printf("%c",string[i]);
   }
   
   return 0;
}
