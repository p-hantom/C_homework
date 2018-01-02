#include <stdio.h>
#include <stdlib.h>
 
 
int main(){
	FILE *fp1=fopen("d:/test.txt","r");
	FILE *fp2=fopen("d:/test1.txt","w");
	if(fp1==NULL || fp2==NULL){
		exit(0);
	}
	
 	int c,capitalCount=0,lowerCount=0,digitCount=0; 
	char ch,pre;	
	
 	while(!feof(fp1)){
 		fscanf(fp1,"%c",&ch);
 		if(ch=='\\'){
 			//fscanf(fp1,"%c",&ch);
 			fseek(fp1,1,1);
 		}
 		else if(ch>='0'&&ch<='9') {
 			digitCount++;
 		}
 		else if(ch>='A'&&ch<='Z'){
 			capitalCount++;
 		}
 		else if(ch>='a'&&ch<='z'){
 			lowerCount++;
 			fputc(ch,fp2);
 		} 			
 	}
 	
	fclose(fp1); 
    fclose(fp2);
 	printf("%d %d %d\n",capitalCount,lowerCount,digitCount);
 	
	return 0;

}
