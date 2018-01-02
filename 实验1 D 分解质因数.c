/*
D: 分解质因数
描述
 
请编写程序，将整数分解为若干个质数的乘积。 
 
输入
 
输入的第一行含一个正整数k，表示测试例的个数，后面紧接着k行，每行对应一个测试例，包含一个正整数x(2<=x<=10000)。
 
输出
 
每个测试例对应一行输出，输出x的质数乘积表示式，式中的质数从小到大排列，两个质数之间用“*”表示相乘。中间不要添加任何空格。
 
样例
 
输入
输出
3
13
4950
262
13
2*3*3*5*5*11
2*131
*/

#include <stdio.h>
#include <stdlib.h>

void test();
void f(int x);

int main(){
	
	test();
	
	return 0;
} 

void f(int x){
	int n=x,i;
	for(i=2;i<=n;i++){
		if(n%i==0){
			//printf("%d \n",i);			
			n/=i;
			if(n==1){
				printf("%d\n",i);
			}
			else{
				printf("%d*",i);
			}
			i=1;
		}
	}
}

void test(){
	int num,i;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		int x;
		scanf("%d",&x);
		f(x);
	}
}

