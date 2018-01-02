#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>  
#include <math.h>
#include <string.h>

#define M 100

 int hasSubstring(int len,char *s,char *start){
 	int found = 0;
 	 		
 	while(*s != '\0'){
 		if(strlen(s)<len){
 			break;
 		}
 		if(strncmp(s,start,len)==0){
 		 	found = 1;
 		 	break;
 		} 		 
 		s++;
 	}
 	
 	return found;
 }
void f(int develop){
	FILE *fp = NULL;
	if(develop){//开发时从文件读入输入数据 
		fp = fopen("input.txt","r");
	}
	char a[100] [100];
	int n,m,i,j,k;
	if(develop) { 
		fscanf(fp,"%d",&n);
	}
	else{
		scanf("%d",&n);
	}
		
	m=0;
	for(i=0;i<n;i++){
		if(develop) { 
			fscanf(fp,"%s",a[m]);
		}
		else{
			scanf("%s",a[m]);
		}
		
		m++;
	}
	//printf("%s\n",a[k]);
	int len=0,found=1,maxlen=0,maxi,maxj,foundLen=0; 
	
	int s,l;
	for(len=strlen(a[0]);len>0;len--){
		for(i=0;i<strlen(a[0])-len+1;i++){					
				if(len<foundLen){
					continue;
				}
				if(develop){
					printf("\nlen=%d",len);
					printf("  test: ");
					for(s=i;s<i+len;s++){
						printf("%c",a[0][s]);
					}
				}
				
				found=1; 
				for(k=1;k<n;k++){				
					found*=hasSubstring(len,&a[k][0],&a[0][i]);
					if(!found){
						break;
					}				
				} 
				if(found){
					if(develop){
					 	printf("\nfound: ");
					}
					for(s=i;s<i+len;s++){
						printf("%c",a[0][s]);
					}
					printf("\n");
					if(len>=maxlen){
						maxlen=len;
						maxi=i;
						//maxj=j;
						foundLen = maxlen;						
					}				
				}			
			}
		}
	
	
//	printf("\nfound max:\n");
//	for(s=maxi;s<maxi+maxlen;s++){
//		printf("%c",a[0][s]);
//	}
//	printf("\n");
	
	if(develop){
		fclose(fp);
	} 
}
 
int main(){	
	//开发时develop = 1; 提交时	develop = 0;
	int develop = 1;
	f(develop);  
	
	return 0;
}

