#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//???ʹ�ö���ע�� 
//���������ַ���s1��s2���Ƚ��������ַ�������s1>s2�����һ����������s1=s2�����0����s1<s2�����һ��������
//����ķ���ֵӦ������Ƚϵ������ַ�����һ������ͬλ�õ��ַ�ASCII��ֵ�����硱And���͡�Aid���Ƚϣ�
//���ݵ�2���ַ��ıȽϽ����Ӧ���5��Ҫ��Ҫʹ��strcpy��strcmp������
void dingDing(){
	//??? ����  123 1234  ��������� 0  �������û�п��ǵ� 
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
һ����������� 
1 1
12 12
123 124
132 123
321  231

��һ����������� 
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
