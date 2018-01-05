#include <stdio.h>
#include <string.h>
long long a1[4],a2[4],a[3];
void fat(){
	//long long a1[4],a2[4],a[3];
	long long i;
//	for(i=0;i<4;i++){
//		scanf("%ld",&a1[i]);
//	}
//	for(i=0;i<4;i++){
//		scanf("%ld",&a2[i]);
//	}
//	for(i=0;i<3;i++){
//		scanf("%ld",&a[i]);
//	}
	long long d1=(a1[0]-a[0])*(a1[0]-a[0])+(a1[1]-a[1])*(a1[1]-a[1])+(a1[2]-a[2])*(a1[2]-a[2]);
	long long d2=(a2[0]-a[0])*(a2[0]-a[0])+(a2[1]-a[1])*(a2[1]-a[1])+(a2[2]-a[2])*(a2[2]-a[2]);
	if(d1>a1[3]*a1[3]&&d2>a2[3]*a2[3]){
		printf("No\n");
	}
	else if(d1==d2){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
}
int main(){
    long long x1,x2,x3,y1,y2,y3,z1,z2,z3,r1,r2;//double 与 long long的区别？？ 
    long long t;
    //scanf("%ld",&t);
    //while(t--){
        //scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld",&x1,&y1,&z1,&r1,&x2,&y2,&z2,&r2,&x3,&y3,&z3);
        x1=1;y1=0;z1=2;r1=7;x2=7;y2=2;z2=3;r2= 9;x3= 5;y3= 0;z3= 0;
        long long d1=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1);
        long long d2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)+(z3-z2)*(z3-z2);
        if(r1*r1<d1 && r2*r2<d2){
        	printf("No\n");
        } 
        else if(r1*r1-d1==r2*r2-d2) {
        	printf("No\n");
        }
        else{
        	printf("Yes\n");
        }
        
        a1[0]=x1;a1[1]=y1;a1[2]=z1;a1[3]=r1;
        a2[0]=x2;a2[1]=y2;a2[2]=z2;a2[3]=r2;
        a[0]=x3;a[1]=y3;a[2]=z3;
        printf("fat(): ");
        fat();
    //}
    
     
    return 0;
}
 
