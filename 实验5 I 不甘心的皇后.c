/*
样例输入
 
8
0 0 0 0 0 0 0 0
4
1 2 0 3
4
1 2 3 4
4
1 3 2 4
0

样例输出
 
11814
2
1
0
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
int MAX=100;
int sum = 0;

void search1(int a[], int b[],int j, int n){	
 	int i;	 	
	for(i=1; i<=n; i++){//每个皇后有n(行)个位置可以试放 
		if(j==1 || abs(i-a[j-1])<=1)	{
			a[j]=i;//摆放皇后 
			if(j==n){
				sum ++; 
			}
			else{
				search1(a,b,j+1,n);
			}
			//a[j]=0; 
		}	
	}
}

void search2(int a[], int b[], int j, int n){	
	if(j>n){
		return;
	}
	if(b[j]>0) {
		a[j] = b[j];//摆放皇后 
		if(j==n){
			sum ++;
		}
		else{
			search2(a,b,j+1,n);
		}
		a[j]=0; 
		return; 
	}
 	int i;	 	
	for(i=1; i<=n; i++){
		if(j==1 || abs(i-a[j-1])<=1)
		{
			if(j==n || b[j+1]==0 || abs(i-b[j+1])<=1){			 
				a[j]=i;//摆放皇后 
				if(j==n){
					sum ++;
				}
				else{
					search2(a,b,j+1,n);
				}
				a[j]=0; 
			}
		}	
	}
}
void search(int a[], int b[], int j, int n){	
//	if(j>n){
//		return;
//	}
	if(b[j]>0) {
		if(j==1 || abs(b[j]-a[j-1])<=1)
		{
			if(j==n || b[j+1]==0 || abs(b[j]-b[j+1])<=1){			 
				a[j]=b[j];//摆放皇后 
				if(j==n){
					sum ++;
				}
				else{
					search(a,b,j+1,n);
				}
				a[j]=0; 
			}
		}	
		
		return; 
	}
 	int i;	 	
	for(i=1; i<=n; i++){
		if(j==1 || abs(i-a[j-1])<=1)
		{
			if(j==n || b[j+1]==0 || abs(i-b[j+1])<=1){			 
				a[j]=i;//摆放皇后 
				if(j==n){
					sum ++;
				}
				else{
					search(a,b,j+1,n);
				}
				a[j]=0; 
			}
		}	
	}
}
void hw(){
  int n,i,j,count=0;

  int a[MAX],b[MAX],result[MAX];
  scanf("%d",&n);
  while(n>0)
  {  	  
	  sum = 0;
	  for(i=1; i<=n; i++){
	  	scanf("%d",&b[i]);
	  	a[i]=0;
	  }
	    
	  search(a,b,1,n);

	  result[count]=sum;
	  count++;
	  
	  scanf("%d",&n);
  }
  for(i=0;i<count;i++){
  	printf("%d\n",result[i]);
  }
} 
void dev(){
  int n = 8;
  int a[MAX], b[]={0,0,0,0,0,0,0,0,0}; //11814

  search1(a,b,1,n);
  printf("%d\n",sum);
} 
int main()
{	
  hw();
  //dev();
  return 0;
}
