/*
描述
 
在基于Internet的程序中，我们常常需要判断一个IP字符串的合法性。合法的IP是这样的形式：
   A.B.C.D
其中A、B、C、D均为位于[0, 255]中的整数。为了简单起见，我们规定这四个整数中不会有前导零存在，如001这种情况。现在，请你来完成这个判断程序吧^_^
 
输入
 
输入由多行组成，每行是一个字符串，输入由“End of file”结束。字符串长度最大为30，且不含空格和不可见字符。
 
输出
 
对于每一个输入，单独输出一行。如果该字符串是合法的IP，输出YES，否则，输出NO
 
样例
 
输入

202.115.32.24
a.b.c.d
End of file

输出
YES
NO

==============================================
strtok函数的作用是把字符串以规定的字符分割开
p为指针，buf也是指针，这句代码的意思就是把buf中的字符串以"$"为分隔符分割开来，
分割出来的字符串保存到指针p中。
再次调用strtok函数时，把buf换成NULL，不需要再写buf。即：
需要注意的是，strtok函数会把分割前的字符串破坏掉，即每次分割后，
原来的字符串就会少掉一部分，完整性会被破坏。
p = strtok(buf, "$");    
while( p!=NULL ){    
    p = strtok(NULL, "$");         
}   


头文件：#include <ctype.h>

isalnum() 用来判断一个字符是否为英文字母或数字，相当于 isalpha(c) || isdigit(c)，其原型为：
    int isalnum(int c);
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include <ctype.h>
#define MAX 30	 
int results[200];
int cnt = 0;

int valid(char *p){
	int isNum=1,num = 0;
	int i;
	for(i=0;i<strlen(p);i++){
		char ch = p[i];
		if(ch<'0' || ch>'9'){
			return 0;
		}
		int d = ch-'0';
		if(d>=0 && d<=9){
			num*=10;
			num+=d;
		}
		else{
			isNum = 0;
			break;
		}
	}	
	if(num<0 || num>255){//位于[0, 255]中的整数?
		isNum = 0;
	}
	
	return isNum;
}

int isValidIP(char *str){	 
   char *A,*B,*C,*D;
   int i, flag, num;
    
	num = 0;   
	flag = 1;
	
	A = strtok(str, ".");   
	if( A==NULL || !valid(A)){		 
	     flag=0;
    }
	if(flag){    
	    B = strtok(NULL, ".");    
	    if( B==NULL  || !valid(B)){    
	        flag=0;    
	    }    
	} 
	if(flag){    
	    C = strtok(NULL, ".");    
	    if( C==NULL  || !valid(C)){    
	        flag=0;    
	    }    
	} 
	if(flag){    
	    D = strtok(NULL, ".");    
	    if( D==NULL  || !valid(D)){    
	        flag=0;    
	    }    
	} 
	if(flag){    //不能超过4位 
		    D = strtok(NULL, ".");    
		    if( D!=NULL){    
		        flag=0;    
		    }    
	}
	if(flag){
	 	//printf("YES\n");
	 	results[cnt++]=1;
	 }
	 else{
	 	//printf("NO\n");
		 results[cnt++]=0;		 	
	 }
	return flag;
} 

void hw(){
  
  int n,i,j,count=0;
  char str[MAX+1];
  while(1){
  	scanf("%s",str); 
  	if(strcmp(str,"End")==0){
  		scanf("%s",str); 
  		if(strcmp(str,"of")==0){
  			scanf("%s",str); 
  			if(strcmp(str,"file")==0){
  				break;
  			}
  			else{
  				isValidIP(str);
  			}
  		}
  		else{
  			isValidIP(str);
  	    } 
  	}
  	else{
  		isValidIP(str);
  	}  	
  } 
  
  for(i=0;i<cnt;i++){
  	if(results[i]){
  		printf("YES\n");
  	}else{
  		printf("NO\n");
  	}
  }
} 

void dev(){
   
} 
int main()
{
  hw();
  //dev();
  return 0;
}
