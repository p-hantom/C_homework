/*
C: ʮ������תʮ����
����
��дһ����������λʮ��������(��ʾ��ʽΪ0x****��*Ϊ0-9��a-f����ΪСд)ת��ʮ��������
ע������ǩ��Ϊint hexToDecimal(char* hex);

����
һ��ʮ����������

���
��ʮ����������Ӧ��ʮ��������

����
����	���
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

