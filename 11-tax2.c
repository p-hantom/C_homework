#include <stdio.h>

int main(){
	int a=3500,t;
	scanf("%d",&t);
	//int x[]={0,1500*0.03,3000*0.1,4500*0.2,26000*0.25,20000*0.3,25000*0.35};
	int x[]={1500,3000,4500,26000,20000,25000};
	int rate[]={0.03,0.1,0.2,0.25,0.3,0.35};
	
	int i,sum[6],sum2[6],flag=1;
	for(i=0;i<6;i++){
		sum[i]+=x[i]*rate[i];
		sum2[i]+=x[i];
	}
	for(i=0;i<6;i++){
		if(t<sum[i]){
			if(i>0)
				printf("%d\n",t/rate[0]+a);
			else{
				printf("%d\n",(t-sum[i-1])/rate[i]+a+sum2[i-1]);
			}
			flag=0;
		}
	}
	if(flag){
		printf("%d\n",(t-sum[i-1])/0.45+sum2[i-1]);
	}
//	int i,y=0,y0,flag=1,sum=0;
//	for(i=1;i<7;i++){
//		y0=x[i-1]*rate[i-1];
//		y+=x[i]*rate[i];
//		sum+=x[i-1];
//		if(t<y){
////			int j;
////			for(j=1;j<i;j++){
////				a+=x[j];
////			}
//			printf("%d\n",(t-y0)/rate[i]+sum);
//			flag=0;
//		}
//	}
//	if(flag){
//		printf("%d\n",(t-y)/0.45+80000);
//	}
	
	return 0;
} 
