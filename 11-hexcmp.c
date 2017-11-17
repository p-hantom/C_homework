#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Èôa>b£¬Êä³ö1£»a<b£¬Êä³ö-1£»a=b£¬Êä³ö0¡£
int hexcmp(char* hex1, char* hex2);

int main(){
	char a[6],b[6];
	int i,j;
	for(i=0;i<6;i++){
		scanf("%c",&a[i]);
	}
	for(i=0;i<6;i++){
		scanf("%c",&b[i]);
	}
	printf("%d\n",hexcmp(a,b));		
	return 0;
}

int hexcmp(char* hex1, char* hex2){
	int rnt=0,i;
	for(i=2;i<6;i++){
		if(hex1[i]>hex2[i]){
			rnt=1;
			break;
		}
		else if(hex1[i]<hex2[i]){
			rnt=-1;
			break;
		}
	}
	
	return rnt;
}
