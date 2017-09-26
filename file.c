#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int ch;
	char fileName[80];
	
	gets(fileName);
	
	if((fp=fopen(fileName,"wt"))=NULL){
		printf("failed");
		exit(1);
	}
	
	printf("input what you wanna put into your file");
	ch=getchar();
	while(ch!=EOF){
	fputc(ch,fp);
	}
	fclose(fp);
	
	printf("the contents are as follows");
	if(fp=fopen(fileName,"rt")==NULL){
		printf("failed");
		exit(2);
	}
	
	ch=fget(fp);
	while(fp!=EOF){
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	return 0;
}
