/*
H: �����ַ���
����
����һ���ַ�������Ӹ��ַ����������ҳ�ָ�����ַ�����ÿ���ַ�������n<100��������ַ�������m���ᳬ��10����
��ʵ����Ӧ�ĺ�����int findString(char stringArray[][100],char *targetString,int n);
����stringArrayΪ�ַ������飬
targetStringΪҪ�ҵ��ַ�����
n��������ַ���������
����ֵ��Ŀ���ַ������ֵĴ�����

����
����m����ʾ������ַ���������
�ַ���1
�ַ���2
�ַ���3
...
�ַ���m
Ŀ���ַ���

���
Ŀ���ַ������ִ���
 
����
 
����
���
3
abc
def
john
def
1





����
���
3
abc
def
john
tom
0
����
���
3
abc
abc
john
abc
2

��ʾ
�Ƚ������ַ����Ƿ���ȵĺ�����strcmp(char * str1, char * str2),��������ַ�������򷵻�0�����򷵻ط�0��
��ʾ���룺
#include<stdio.h>
int findString(char stringArray[][100], char * targetString, int n) {
   //��������
}
int main(){
   char stringArray[10][100];//�����ַ���������
   char targetString[100];//���մ����ҵ��ַ���
   //��ʵ��
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
  // ={"ab","ddd","abc"};//�����ַ���������
   //stringArray[]={"abc","ddd","abc"};
   char targetString[100];
   //="abc";//���մ����ҵ��ַ���
   //targetString="abc";
   
   int i,n;//m:�ַ������� 
   
   scanf("%d",&n);
   
   for(i=0;i<n;i++){
   		scanf("%s",&stringArray[i]);
   		//printf("%s\n",stringArray[i]);
   }
   
   //gets(targetString);//??????ִ�в��� 
   scanf("%s",targetString);
   printf("%d\n",findString(stringArray,targetString,n));
   return 0;
}

