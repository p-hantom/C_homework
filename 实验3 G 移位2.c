/*
G: 移位2
描述
有一组包含m个整数的数组，使其左移或者右移n位。(n<=m)

输入
先输入两个正整数分别代表数组的个数以及将要移动的位数。接着输入一个整数(1或0)代表移动的方向。规定：1向左移0向右移。然后输入m个整数作为组数的元素。

输出
移动后的数组。（输出的各元素以空格分隔）

样例
输入	输出
4 2
3 4 1 2
1	
1 2 3 4	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//先输入两个正整数分别代表数组的个数以及将要移动的位数。接着输入一个整数(1或0)代表移动的方向。
//规定：1向左移0向右移。然后输入m个整数作为组数的元素。
int main(){
	int n,num,i,flag;
//	n=2;
	scanf("%d%d%d",&num,&n,&flag);
	int *a=(int*)malloc(sizeof(int)*num);
	for(i=0;i<num;i++){
		scanf("%d",&a[i]);
	}
	
	int temp,j;
	if(flag==1){
		for(i=0;i<n;i++){
			temp=a[0];
			for(j=0;j<num-1;j++){
				a[j]=a[j+1];
			}
			a[num-1]=temp;
		}
	}
	else{
		for(i=0;i<n;i++){
			temp=a[num-1];
			for(j=num-1;j>0;j--){
				a[j]=a[j-1];
			}
			a[0]=temp;
		}
		
	}	
	
	for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
	free(a);
	
	return 0;
}

