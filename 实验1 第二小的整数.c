/*
����
 
�ҳ����������еڶ�С������
 
����
 
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У���һ������m(1<=m<=100)����ʾ�����m��������
 
���
 
��ÿ�����ݣ�����ڶ�С����������ڶ�С���������ڣ������ERROR��
 
����
 
����
���
4
7 3 1 2 4 5 6   7
4 5 5 8 13
1 2
4 3 3 3 3
2
8
ERROR
ERROR
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void homework();
void f(int *a,int len);
void print(int *a,int len);

int main(){
//	int a[]={3,3},len=2;
//	f(a,len);
	homework();
	
	return 0;
} 

void f(int *a,int len){
	//print(a,len);
	int i,j,temp,ans,found=0;
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			
		}
		//print(a,len);
		if(len==2){
			if(a[0]<a[1]){
				found=1;
				ans=a[1]; 
			}
				
		}
		if(a[i]>a[0]){
			found=1;
			ans=a[i];
			break;
		}
		
	}
	if(found){
		
		printf("%d ",ans);
		
		printf("\n");
	}
	else{
		printf("ERROR");
	}
}

void print(int *a,int len){
		int k;
		for(k=0;k<len;k++){
			printf("%d ",a[k]);			
		}
		printf("\n");
}

void homework(){
	int num;
	scanf("%d",&num);
	
//	if(num<=0)
//		printf("ERROR");
	
	int i,len,j;
	for(i=0;i<num;i++){
		scanf("%d",&len);
		
//		if(len<=0){
//			printf("ERROR");
//			continue;
//			
//		}
		int *a=(int *)malloc(sizeof(int)*len);
		for(j=0;j<len;j++){
			scanf("%d",&a[j]);
		}
		f(a,len);
		free(a);
	}
	
}

