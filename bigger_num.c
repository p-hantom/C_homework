#include <stdio.h>

double bigger_num(double num1,double num2){
	double rnt;
	if(num1>num2)
		rnt=num1;
	else
		rnt=num2;
	return rnt;
}

int main(){
	double num1,num2;
	scanf("%lf%lf",&num1,&num2);
	double bigger=bigger_num(num1,num2);
	printf("%lf\n",bigger);
	
	return 0;
}
