/*
����
 
�ڻ���Internet�ĳ����У����ǳ�����Ҫ�ж�һ��IP�ַ����ĺϷ��ԡ��Ϸ���IP����������ʽ��
   A.B.C.D
����A��B��C��D��Ϊλ��[0, 255]�е�������Ϊ�˼���������ǹ涨���ĸ������в�����ǰ������ڣ���001������������ڣ��������������жϳ����^_^
 
����
 
�����ɶ�����ɣ�ÿ����һ���ַ����������ɡ�End of file���������ַ����������Ϊ30���Ҳ����ո�Ͳ��ɼ��ַ���
 
���
 
����ÿһ�����룬�������һ�С�������ַ����ǺϷ���IP�����YES���������NO
 
����
 
����

202.115.32.24
a.b.c.d
End of file

���
YES
NO

==============================================
strtok�����������ǰ��ַ����Թ涨���ַ��ָ
pΪָ�룬bufҲ��ָ�룬���������˼���ǰ�buf�е��ַ�����"$"Ϊ�ָ����ָ����
�ָ�������ַ������浽ָ��p�С�
�ٴε���strtok����ʱ����buf����NULL������Ҫ��дbuf������
��Ҫע����ǣ�strtok������ѷָ�ǰ���ַ����ƻ�������ÿ�ηָ��
ԭ�����ַ����ͻ��ٵ�һ���֣������Իᱻ�ƻ���
p = strtok(buf, "$");    
while( p!=NULL ){    
    p = strtok(NULL, "$");         
}   


ͷ�ļ���#include <ctype.h>

isalnum() �����ж�һ���ַ��Ƿ�ΪӢ����ĸ�����֣��൱�� isalpha(c) || isdigit(c)����ԭ��Ϊ��
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
	if(num<0 || num>255){//λ��[0, 255]�е�����?
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
	if(flag){    //���ܳ���4λ 
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
