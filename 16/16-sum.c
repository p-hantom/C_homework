#include <stdio.h>
#include <string.h>

int main(){
	int n,a,i,sum=0,j;
	//n=2;a=2;
	scanf("%d%d",&a,&n);
	for(i=1;i<=n;i++){
		int temp=0;
		for(j=0;j<i;j++){
			temp*=10;
			temp+=a;
		}
		sum+=temp;
	}
	printf("%d\n",sum);
	
	return 0;
}
