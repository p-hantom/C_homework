#include <stdio.h>

void f(int num){
	int a;
	a=num%10;
	if(a>4){
		num=num-a+10;
	}
	printf("%d\n",num);
}

int main(){
	int num;
	scanf("%d",&num);
	f(num);
	
	return 0;
}
