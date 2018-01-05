/*
E: 超级楼梯
题目描述：
    有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
输入：
    输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
输出：
    对于每个测试实例，请输出不同走法的数量
样例输入：
2
2
3
样例输出：
1
2
*/ 
#include<stdio.h>

int f[41];
int main()
{
	int n,m,i;
	f[1]=0;
	f[2]=1;
	f[3]=2;
	for(i=4;i<41;i++){
		/** 
         * 逆向思考。要想走到M级,可以分为2种情况。 
         * 1)从m-2级迈两步 
         * 2)从m-1级迈一步 
         */  
		f[i]=f[i-1]+f[i-2];
		printf("f[%d]=%d\n",i,f[i]);
	} 
		
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",f[m]);
	}
	return 0;
}
