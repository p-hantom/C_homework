#include <stdio.h>
#include <stdlib.h>

//100,9999超级素数个数 

int check(int n);
int *sum(int n);
//int sqrsum(int n);
//int pro(int n);
//int* separate(int n);  

int main(){
	int i,num=0,sum2=0,temp;
	for(i=100;i<10000;i++){
		if(check(i)){
			int *b=sum(i);
			if(check(b[0])){
				if(check(b[1])){
					if(check(b[2])){
						num++;
						sum2+=i;
						temp=i;
						//printf("%d ",i);
					}
				}
			}
			
		}
	}
	printf("the number of super prime numbers is %d\n",num);
	printf("the sum of super prime numbers is %d\n",sum2);
	printf("the largest of super prime numbers is %d\n",temp);
	
	
	//free(a);
	
	return 0;
}

int* sum(int n){
	//int sum1=0,sqrsum=0;
	int a[3],temp=n;
	a[0]=0;a[1]=0;a[2]=1;
	
	while(temp!=0){
		int x=temp%10;
		a[0]+=x;
		a[1]+=x*x;
		a[2]*=x;
		temp/=10;
	}
	
	return a;
}

//int* separate(int n){
//	int i,temp;
//	while(n!=0){
//		temp/=10;
//		num++;
//	}
//	
//	
//	return a;
//}

int check(int n){
	int flag=1;
	int i;
	for(i=2;i<n;i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	
	return flag;
}
