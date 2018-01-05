/*
E: 查找图案中*周围8领域的-的个数
描述
已知图案：
--**-**--
-*-*****-
-*----**-
--*--**--
---***---
----*----
输入正整数n(0<n<8)，输出上图中有多少个*的8邻域内有n个-，边界点领域不完整，但也计入统计。
如果不满足输入，则输出Input Error。
8领域的意思如下：
--*
-*-
-*-
上图中间*周围的8领域内有2个*，6个-。
输入
第一行是输入1个正整数n(0<n<8)，若不满足输入，则输出Input Error。
输出
输出一个正整数，若有m个*的8邻域内有n个-，则输出m。
样例
输入
1
输出
2
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//--**-**--
//-*-*****-
//-*----**-
//--*--**--
//---***---
//----*----
//输入正整数n(0<n<8)，输出上图中有多少个*的8邻域内有n个-，边界点领域不完整，但也计入统计。
//如果不满足输入，则输出Input Error。
//8领域的意思如下：
//--*
//-*-
//-*-
//上图中间*周围的8领域内有2个*，6个-。
char a[8][11]={
"000000000",
"0--**-**--0",
"0-*-*****-0",
"0-*----**-0",
"0--*--**--0",
"0---***---0",
"0----*----0",
"000000000"};
int check(int i,int j){
	int n=0,x,y;
	for(x=i-1;x<i+2;x++){
		for(y=j-1;y<j+2;y++){
			//if(a[i][j]=='*'){
				if(a[x][y]=='-'){
					n++;
				}
			//}			
		}
	}
//	printf("%d\n",n);
	
	return n;
}

int main(){
	int n;//=1;
	scanf("%d",&n);
	if(n<=0||n>=8){
		printf("Input Error\n");
	}
	int sum=0;
	int i,j;
	for(i=1;i<7;i++){
		for(j=1;j<10;j++){
			if(a[i][j]=='*'){
				if(check(i,j)==n){
					sum++;
				}
			}
			
		}
	}
	printf("%d\n",sum);
	
	return 0;
}
