/*
F: ���ͬ��׺
����
�������ַ��������ͬ��׺���������һ���ַ����������Ӵ�

����
�����ǿ��ַ���

���
���ͬ��׺����������ͬ��׺�����null

����1
����	���
abcdefg	
efg
dadcefg	

����2
����	���
abcdefg	
null
1234567	
*/ 

#include <stdio.h>
#include <string.h>

int main(){
	char s1[100],s2[100];  
	scanf("%s%s",s1,s2);
	int n1=strlen(s1),n2=strlen(s2);
	int i,j,num=0;
	for(i=n1-1,j=n2-1;i>=0,j>=0;i--,j--){
		if(s1[i]!=s2[j]){
			break;
		}
		num++;
	}
	if(num!=0){
		for(j=i+1;j<n1;j++){
			printf("%c",s1[j]); 
		} 
	}
	else
		printf("null\n");
	
	return 0;
}


