/*
F: ��λ1
����
��һ������10�����������飬ʹ��ѭ������nλ��

����
����һ������������Ҫ�ƶ���λ����Ȼ������10��������Ϊ������Ԫ�ء�

���
�ƶ�������顣������ĸ�Ԫ���Կո�ָ���

����
����	���
2	3 4 5 6 7 8 9 10 1 2
1 2 3 4 5 6 7 8 9 10	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n,num=10,a[10],i;
//	n=2;
	scanf("%d",&n);
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int temp,j;
	for(i=0;i<n;i++){
		temp=a[0];
		for(j=0;j<num-1;j++){
			a[j]=a[j+1];
		}
		a[num-1]=temp;
	}
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

//int* b=(int*)malloc(sizeof(int)*n);
//	int j;
//	for(i=0;i<n;i++){
//		b[i]=a[i];
//	}
//	for(i=n,j=0;i<10;i++,j++){
//		a[j]=a[i]; 
//	}
//	j=0;
//	for(i=10-n;i<10;i++,j++){
//		a[i]=b[j];
//	}
//	
//	for(i=0;i<10;i++){
//		printf("%d ",a[i]);
//	}
//	
//	free(b);

