/*
F: �ǹȲ���
 
����

����һ����n�������ż�����Ͱ�n����һ�룻�������������n��� 3*n+ 1�󿳵�һ�룬ֱ��������Ϊ1Ϊֹ��������Ҫ�����������ܽ�n�䵽1��
 
����
 
��һ����1������T����ʾ�����T��������ÿ������ռһ�С� 
 
���
 
�����Ĳ�������n=1������Ϊ0��
 
����
 
����

2
7
1

���
11
0


*/ 

#include <stdio.h>
#include <stdlib.h>

int count=0;
void f2(int n){
	if(n==1){
		return;
	}
	
	if(n%2==0){	
		n /= 2;			
		f2(n);
	}
	else{
		n=(3*n+ 1)/2;		 
		f2(n);
	}
	count++;
}


int f(int n){
	int cnt=0;

	while(n!=1){
		if(n%2==0){
			n/=2;
			cnt++;
		}			
		else{
			n=(3*n+ 1)/2;
			cnt++;
		}			
	}
	return cnt;
}

int main(){
	f2(7);
//	int n,cnt=0,t,i;
//	//f(1);
//	scanf("%d",&t);
//	for(i=0;i<t;i++){
//		scanf("%d",&n);
//		count=0;
//		f2(n);
//		printf("%d\n",count);
//	}
//	
	return 0;
}

