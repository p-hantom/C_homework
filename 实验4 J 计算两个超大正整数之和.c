/*
J: ������������������֮��
����
 
�������������������ĺ͡�
 
����
 
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�����������a��b���Կո�ֿ���
 
���
 
��ÿ�����ݣ����㲢���a��b�ĺͣ������С�
 
����
 
����                              
���
3
123456789 12345678
13242325232535242 324
657936583496539485698934561 987

135802467
13242325232535566
657936583496539485698935548
 
*/ 

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100

void SUM();
void f(int n);

int main(){
	int carry=0,i,n;
	scanf("%d",&n);	
	f(n);	
	
	return 0;
}

void f(int n){
	int i;
	for(i=0;i<n;i++){
		SUM();
	}
}

void SUM(){
	int i,carry=0;
	char a1[MAX],a2[MAX];
	char sum[MAX],*p;
	sum[MAX-1]='\0';
	scanf("%s%s",a1,a2);
//	char a1[]="123456789",a2[]="12345678";
	int l1=strlen(a1),l2=strlen(a2);
	
	int j=l1-1,k=l2-1;
	for(i=MAX-2;j>=0&&k>=0;i--,j--,k--){
		int temp=a1[j]-'0'+a2[k]-'0'+carry;
		carry=0;
		if(temp>=10){
			temp-=10;			
			carry=1;
		}
		sum[i]=temp+'0';				
	}
	
	while(j>=0){
		sum[i]=a1[j]+carry;
		carry=0;
		j--;i--;
	}
	while(k>=0){
		sum[i]=a2[k]+carry;
		carry=0;
		k--;i--;
	}
	p=&sum[i+1];
	printf("%s\n",p);
}

