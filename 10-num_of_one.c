#include <stdio.h>
#include <stdlib.h>

int sum1(int n);
int f(int n);

int main(){
	int n;
	int i=2;
	
	while(i!=f(i))
		i++;
	printf("%d\n",i);
	
	return 0;
}

int f(int n){
	if(n==1)
		return 1;
	return f(n-1)+sum1(n);
}
 
int sum1(int n){
	int sum=0;
	while(n!=0){
		int x=n%10;
		n/=10;
		if(x==1)
			sum++;
	}
	
	return sum;
}
