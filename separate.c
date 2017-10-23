#include <stdio.h>

void f(){
	double num;
	scanf("%lf",&num);
	int integer=(int )num;
	double float_part=num-integer;
	printf("integer part=%d\n float part=%lf",integer,float_part);
} 

int main(){
	f();
	
	return 0;
} 
