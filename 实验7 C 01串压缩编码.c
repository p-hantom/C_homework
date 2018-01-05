#include <stdio.h> 
#include <string.h>
#include<stdlib.h>
#define DEPTH 500
#define LEN 10 


int main(){  
  	int i,j,d,m;	
	int k = 0;
	 
	char input[8000];
	int n;
	scanf("%d",&n);	
	for(j=0;j<n/8;j++){
		scanf("%d",&m);		
		char str[8];
		for(i=0;i<8;i++) str[i]='0';
		i=7;
		while(m>0)  {
			d=m%2;
			str[i--]=d+'0';
			m/=2;
		}
		for(i=0;i<8;i++){
			input[k++]=str[i];
		}
	}
	
//	for(i=0;i<k;i++){
//		printf("%c",input[i]);
//	}
	int zeros = 0;
	int ones = 0;
	i=0;	
	while(i<k){
		zeros = 0;
		ones = 0;
		while(input[i]=='0'){
			zeros++;
			i++;
		}
		while(input[i]=='1'){
			ones++;
			i++;
		}
		if(zeros>0){
			printf("%d ",zeros);
		}
		if(ones>0){
			printf("%d ",ones+128);
		}
		
	}		
		//printf("%c",str[i]); 
	return 0;
}
