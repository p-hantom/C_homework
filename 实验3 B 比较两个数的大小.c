/*
B: �Ƚ��������Ĵ�С
����
��дһ���������Ƚ�����ʮ��������(��ʾ��ʽΪ0x****������*Ϊ0-9��a-e�����ң������������ĸ��ΪСд)�Ĵ�С��
ע������ǩ��Ϊint hexcmp(char* hex1, char* hex2);

����
����ʮ��������a��b��

���
��a>b�����1��a<b�����-1��a=b�����0��

����
����	���
0x1234	-1
0x1235	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//��a>b�����1��a<b�����-1��a=b�����0��
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

