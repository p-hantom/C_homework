/*
C: ͳ���ַ����е����ָ���
����
����һ���ַ�����ͳ�������м�������(������������һ�����֣���
��������asdad12asda43eftr45-23-3--22-�����6��
12��43��45��23��3��22Ϊ���ַ�����6�����֡�

����
��һ������������һ���ַ�����

���
����ַ��������ָ�����
����
����
23frw90ewe3**325%
���
4
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dingDing(){//�������������whileѭ�������߼����򵥣��������� 
//	char s[]="1asdad12asda43eftr45-23-3--22-";
//	//gets(s);
//	int i,sum=0,len=strlen(s),flag;//??? flag û�г�ʼ������ 
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

