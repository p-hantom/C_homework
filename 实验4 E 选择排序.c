/*
E: ѡ������
 
����

����n��������ʹ��ѡ�������㷨����С��������Ȼ����������

����
 
һ����1������n����ʾ�����n���������ڶ�����n���������ո������ 
 
���
 
��������n-1�У�ÿ��Ϊ����һ�˺�Ľ����
 
����
 
����

5
1 5 4 3 2

���
1 5 4 3 2
1 2 4 3 5
1 2 3 4 5
1 2 3 4 5
 
��ʾ
 
ѡ��������ԭ����ÿһ�δӴ������������ѡ����С������󣩵�һ��Ԫ�أ���������е���ʼλ�ã�ֱ��ȫ�������������Ԫ�����ꡣ


*/ 

#include <stdio.h>
#include <stdlib.h>

void f();
void f_li(){
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	
//	n=5;
//	 int a[]={1,5,4,3,2};
	
	int i,j,k,l;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int temp,min,minIdx;
	for(i=0;i<n-1;i++){
		min=a[i];
		minIdx=i;
		for(j=i+1;j<n;j++){
			if(a[j]<min){
				min=a[j];
				minIdx=j;
			}			
		}
		if(minIdx!=i){
			temp = a[i];
			a[i]=a[minIdx];
			a[minIdx]=temp;
		}	
		for(k=0;k<n;k++){
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	free(a);
}
int main(){

//	f();
	f_li();
	return 0;
}

void f(){
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	
	//int a[]={5,1,3,2,4};
	
	int i,j,k,l;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int temp;
	for(i=0;i<n-1;i++){
		temp=a[i];
		for(j=i+1;j<n;j++){
			if(a[j]<temp){
				temp=a[j];
				l=j;
			}			
		}
		if(a[i]!=temp){
			for(k=l-1;k>=i;k--){
				a[k+1]=a[k];
			}
			a[i]=temp;
		}		
		for(k=0;k<n;k++){
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	free(a);
}


