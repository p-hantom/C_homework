#include <stdio.h>
#include <stdlib.h>

void f(){
	double x,y,a,b,c,d,e,f;
	//ax+by=e,cx+dy=f
	printf("Please enter six parameters of two equations.");
	scanf("%lf,%lf,%lf,%lf,%lf,%lf",&a,&b,&c,&d,&e,&f);
	
	if(a*d==b*c){
		printf("insoluble");
	}
	else{
		x=(e*d-b*f)/(a*d-b*c);
		y=(e*c-a*f)/(b*c-a*d);
		printf("x=%lf,y=%lf\n",x,y);
	}
	
}

int main(){
	f();
	
	return 0;
}
