#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
	//double x;
	if(n<=3500){
		printf("0.00\n");
	}
	else if(n>3500){
		double x1=n-3500;
		if(x1<=1500){
			printf("%.2lf\n",x1*0.03);
		}
		else if(x1>1500&&x1<=4500){
			double x2=x1-1500;
			printf("%.2lf\n",1500*0.03+x2*0.1);
		}
		else if(x1>4500&&x1<=9000){
			double x3=x1-4500;
			printf("%.2lf\n",1500*0.03+3000*0.1+x3*0.2);
		}
		else if(x1>9000&&x1<=35000){
			double x4=x1-9000;
			printf("%.2lf\n",1500*0.03+3000*0.1+4500*0.2+x4*0.25);
		}
		else if(x1>35000&&x1<=55000){
			double x5=x1-35000;
			printf("%.2lf\n",1500*0.03+3000*0.1+4500*0.2+26000*0.25+x5*0.3);
		}
		else if(x1>55000&&x1<=80000){
			double x6=x1-55000;
			printf("%.2lf\n",1500*0.03+3000*0.1+4500*0.2+26000*0.25+20000*0.3+x6*0.35);
	    }
		else if(x1>80000){
			double x7=x1-80000;
			printf("%.2lf\n",1500*0.03+3000*0.1+4500*0.2+26000*0.25+25000*0.3+x7*0.45);
		}
	
	return 0;
}
