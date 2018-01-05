/*
描述

有一个r行c列(1<=r,c<=50)的电子表格，行从上到下编号为1~r，列从左到右编号是1~c。上面定义了几种操作：(x, y等都是整数)
l  SR x1 x2 
交换x1行和x2行
l  SC y1 y2 
交换y1列和y2列
l  DR x
删除x行
l  DC y
删除y列
l  IR x
在x行上面插入一行，新插入的行的所有单元格值为0
l  IC y
在y列前面插入一列，新插入的列的所有单元格值为0
 
输入
 
第一行是2个整数r, c，表示电子表格有r行c列。接下来的r行，每行c个整数，表示每个单元格的值。再接下来的一行有1个整数n，表示随后有n行，每行是一个操作命令。
 
 
输出
 
输出经过这n次操作后的电子表格内容。
 
样例输入
 
3 5
1 2 3 4 5
3 4 5 6 7
5 6 7 8 9
4
SR 1 3
SC 2 4
IR 2
DC 2
 
样例输出
 
5 7 6 9
0 0 0 0
3 5 4 7
1 3 2 5



函数原型
void *memcpy(void*dest, const void *src, size_t n);
功能
由src指向地址为起始地址的连续n个字节的数据复制到以destin指向地址为起始地址的空间内。
头文件
#include<string.h>
返回值
　　函数返回一个指向dest的指针。

例：
　　char a[100], b[50];
　　memcpy(b, a,sizeof(b)); //注意如用sizeof(a)，会造成b的内存地址溢出。
　　strcpy就只能拷贝字符串了，它遇到'\0'就结束拷贝；例：
　　char a[100], b[50];
strcpy(a,b);
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include <ctype.h>
#define MAX 30	 

 
 
void print(int **a, int r, int c){
	int i,j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void SR(int **a, int r1, int r2, int r, int c){
	if(r1<1 || r1>r || r2<1 || r2>r){
		return;
	}
	int tmp, j;
	r1--;r2--;
	
	for(j=0;j<c;j++){
		tmp = a[r1][j];
		a[r1][j] = a[r2][j];
		a[r2][j] = tmp;
	}
}
void SC(int **a, int c1, int c2, int r, int c){
	if(c1<1 || c1>c || c2<1 || c2>c){
		return;
	}
	int tmp, i;
	c1--;c2--;
	
	for(i=0;i<r;i++){
		tmp = a[i][c1];
		a[i][c1] = a[i][c2];
		a[i][c2] = tmp;
	}
}

void freeArray(int **a, int r, int c){
	int i;
	for(i=0; i<r; i++){
    	free(a[i]); 
    }
    free(a);
}

int ** creatArray(int r,int c){	
    int ** a = (int **)malloc(r*sizeof(int *));
    int i,j;
    for(i=0; i<c; i++){
    	a[i] = (int*)malloc(c*sizeof(int));
    }  
    return a;
}

void IR(int ***pa, int r1, int r, int c){
	int tmp, i, j;	
	int **a=*pa;
	if(r1<1 || r1>r){
		return;
	}
	
	int ** b =  (int **)malloc((r+1)*sizeof(int *));
	for(i=0;i<r1-1;i++){
		b[i]=a[i];
	}
	for(i=r1-1;i<r;i++){
		b[i+1]=a[i];
	}
	
	b[r1-1] = (int*)malloc(c*sizeof(int));
	//memset(b[r1-1],0,c);
	for(j=0;j<c;j++){
		b[r1-1][j]=0;
	}
	
//	printf("\n");
//	for(i=0;i<r;i++){
//		printf("%x ",a[i]);
//	}
//	printf("\n");
//	for(i=0;i<r+1;i++){
//		printf("%x ",b[i]);
//	}
// 	printf("\n");

//	printf("\n&a=%x, &b=%x\n",a,b);
	
	//print(b,r+1,c); 
	
	//int ** del = *pa;
	 
	*pa = b;
	
	//free(&del[0]);
}
void DR(int ***pa, int r1, int r, int c){
	int tmp, i, j;	
	int **a=*pa;
	if(r1<1 || r1>r){
		return;
	}
	
	int ** b =  (int **)malloc((r-1)*sizeof(int *));
	for(i=0;i<r1-1;i++){
		b[i]=a[i];
	}
	for(i=r1-1;i<r-1;i++){
		b[i]=a[i+1];
	}
	
 	//free(a[r-1]); //???????????
	
//	printf("\n");
//	for(i=0;i<r;i++){
//		printf("%x ",a[i]);
//	}
//	printf("\n");
//	for(i=0;i<r+1;i++){
//		printf("%x ",b[i]);
//	}
// 	printf("\n");

//	printf("\n&a=%x, &b=%x\n",a,b);
	
	//print(b,r+1,c); 
	
	//int ** del = *pa;
	 
	*pa = b;
	
	//free(&del[0]);  //???????????
}

void IC(int ***pa, int c1, int r, int c){
	int tmp, i, j;	
	int **a=*pa;
	if(c1<1 || c1>c){
		return;
	}
	
	int ** b =  creatArray(r,c+1);
	
	for(j=0;j<c1-1;j++){
		for(i=0;i<r;i++){
			b[i][j]=a[i][j];
		}
	}
	for(i=0;i<r;i++){
			b[i][c1-1]=0;
	}
	for(j=c1-1;j<c;j++){
		for(i=0;i<r;i++){
			b[i][j+1]=a[i][j];
		}
	}
	
	 
	//freeArray(*pa,r,c) ;//？？？ 
	*pa = b;
	
	//free(&del[0]);//？？？ 
}

void DC(int ***pa, int c1, int r, int c){
	int tmp, i, j;	
	int **a=*pa;
	if(c1<1 || c1>c){
		return;
	}
	
	int ** b =  creatArray(r,c-1);
	
	for(j=0;j<c1-1;j++){
		for(i=0;i<r;i++){
			b[i][j]=a[i][j];
		}
	}
	
	for(j=c1-1;j<c-1;j++){
		for(i=0;i<r;i++){
			b[i][j]=a[i][j+1];
		}
	}
	
	 
	//freeArray(*pa,r,c) ;
	*pa = b;
	
	//free(&del[0]);//？？？ 
}
void dev(){
	int r,c;
	r=3;
	c=5;
    int i,j,**a=creatArray(r,c); 
    int b[]={1,2,3,4,5,3,4,5,6,7,5,6,7,8,9};    
//    memcpy(a[0], &b[0], c);
//    memcpy(a[1], &b[1*c-1], c);
//    memcpy(a[2], &b[2*c-1], c);
	int k=1,flag=0;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			a[i][j]=k;
			if(k==9) flag=1;
			if(flag){
				k--;
			}else{
				k++;
			}			
		}		
	}	
    print(a,r,c);
    
    SR(a,1,3,r,c);
    print(a,r,c);
    
    SC(a,2,4,r,c);
    print(a,r,c);
    
    IR(&a,2,r,c);
    r++;
    //printf("After IR():&a=%x \n",a );
    print(a,r,c);
    
    DR(&a,2,r,c);
    r--;
    //printf("After IR():&a=%x \n",a );
    print(a,r,c);
    
    printf("\n IC:\n");
    IC(&a,2,r,c);
    c++;
    //printf("After IR():&a=%x \n",a );
    print(a,r,c);
    
    printf("\n DC:\n");
    DC(&a,2,r,c);
    c--;
    //printf("After IR():&a=%x \n",a );
    print(a,r,c);
    
    freeArray(a,r,c);
}
void hw(){
	int r,c,nops,n1,n2;
	char op[3];
	scanf("%d%d",&r,&c);
    int i,j;
	 
    int **a=creatArray(r,c);    
 	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			 scanf("%d",&a[i][j]);//a[i][j]=k;
		}
	} 
	scanf("%d",&nops);
	for(i=0;i<nops;i++){
		scanf("%s",op);
		
		if(strcmp(op,"SR")==0){
			scanf("%d%d",&n1,&n2);
			//printf("\n%s\n",op); 
			SR(a,n1,n2,r,c);
    		//print(a,r,c);
		}
		else if(strcmp(op,"SC")==0){
			scanf("%d%d",&n1,&n2);
			//printf("\n%s\n",op); 
			SC(a,n1,n2,r,c);
    		//print(a,r,c);
		}
		else if(strcmp(op,"IR")==0){
			scanf("%d",&n1);
			//printf("\n%s\n",op); 
			IR(&a,n1,r,c);
    		r++;
    		//print(a,r,c);
		}
		else if(strcmp(op,"IC")==0){
			scanf("%d",&n1);
			//printf("\n%s\n",op); 
			IC(&a,n1,r,c);
    		c++;
    		//print(a,r,c);
		}
		else if(strcmp(op,"DR")==0){
			scanf("%d",&n1);
			//printf("\n%s\n",op); 
			DR(&a,n1,r,c);
    		r--;
    		//print(a,r,c);
		}
		else if(strcmp(op,"DC")==0){
			scanf("%d",&n1);
			//printf("\n%s\n",op); 
			DC(&a,n1,r,c);
    		c--;
    		//print(a,r,c);
		}
	}
	
	print(a,r,c);
    
    
    freeArray(a,r,c);	
} 
int main()
{
  //hw();
  dev();
  return 0;
}
