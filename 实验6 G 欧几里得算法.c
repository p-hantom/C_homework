#include<stdio.h>
#include<string.h>

int extend(int n, int a){
	int q, r, r1=n, r2=a, t, t1=0, t2=1, i=1;
	while(r2>0){
		q = r1/r2;
		r = r1%r2;
		
		r1 = r2;
		r2 = r;	
		t = t1 - q*t2;				
		t1 = t2;		
		t2 = t;		
	} 
	if(t1 >= 0){
		return t1 % n;
	}
	else{
		while((t1+i*n)<0){
			i++;
		}
		return t1 + i*n;
	}
}

int Exgcd(int a,int b,int *x,int *y)
{
      if(b==0)
      {
            *x=1;
            *y=0;
            return a;
      }
      int ans=Exgcd(b,a%b,x,y);
      int temp=*x;
      *x=*y;
      *y=temp-a/b* (*y);
      return ans;
}
int gcd(int a,int b)
{
   return b==0 ? a : gcd(b,a%b);
}

int main(){
	int a, n, x, y;
	scanf("%d%d",&a,&n); 
	while(a!=0 && n!=0)
	{
		Exgcd(n,a,&x,&y);		
		printf("%d\n",y);//输入 136468984 134548555 时输出为负数！！！ 
		scanf("%d%d",&a,&n); 
	}
	
	//int x,y;
	//int z = Exgcd(3837,1001,&x,&y);	
	//z = Exgcd(4,6,&x,&y);
	
	//int x = extend(3837,1001);
	//printf("%d\n",x);
	
	
//	int a, n;
//	scanf("%d%d",&a,&n); 
//	while(a!=0 && n!=0)
//	{
//		int x = extend(n,a);
//		printf("%d\n",x);
//		scanf("%d%d",&a,&n); 
//	}
//	
	
	return 0; 
} 
