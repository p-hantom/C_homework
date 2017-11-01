#include <stdio.h>
#include <stdlib.h>
//从小到大 
sort(double x,double y,double z){
	double temp,max=x;
	if(x>y&&x>z){
		if(y>z)
			printf("%lf,%lf,%lf\n",z,y,x);
		else
			printf("%lf,%lf,%lf\n",y,z,x);		
	}
	else if(y>x&&y>z){
		if(x>z)
			printf("%lf,%lf,%lf\n",z,x,y);
		else
			printf("%lf,%lf,%lf\n",x,z,y);	
	}
	else{
		if(y>x)
			printf("%lf,%lf,%lf\n",x,y,z);
		else
			printf("%lf,%lf,%lf\n",y,x,z);	
	}
}

int main(){
	double x,y,z;
	scanf("%lf%lf%lf",&x,&y,&z);
	sort(x,y,z);
	
	return 0;
}
