#include <stdio.h>

void f(double num1,double num2);

int main(){
	double num1, num2;
	scanf("%lf%lf",&num1,&num2);
	f(num1,num2);
	
	return 0;
} 

void f(double num1,double num2){
	if(fabs(num1-num2)<1e-6){
		printf("yes\n");
	}
	else
		printf("no\n");
}
