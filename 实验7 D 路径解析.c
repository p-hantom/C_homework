#include <stdio.h> 
#include <string.h>
#include<stdlib.h>
#define DEPTH 1000
#define LEN 20 
#define STRLEN 1000

int main(){
	int develop = 1; 
	FILE *fp;
	if(develop){
		fp=fopen("input.txt","r");
	}
 	char curr[DEPTH][LEN];
 	char input[DEPTH][LEN];
 	char result[DEPTH][LEN];
 	int l,i,j,k,cur=0,inputNodes;
 	char *p; 	
 	char str[STRLEN];//="/d2/d3"; //当前目录	
 	int lines;
 	if(develop){
 		fscanf(fp,"%d",&lines);
 		fscanf(fp,"%s",str);
 	}
 	else{
 		scanf("%d",&lines);
 		scanf("%s",str);
 	}
 	
 	
 	i=0;
	p=strtok(str,"/");
	while(p!=NULL){
		strcpy(curr[i],p);
		//printf("i=%d,%s\n",i,curr[i]);
		cur = i;
		i++;
		p=strtok(NULL,"/");
	}
 	
 	char test[STRLEN];//="../d4/f1"; 
 	for(l=0;l<lines;l++){
 		if(develop){
 			fscanf(fp,"%s",test);
 		}
 		else{
 			scanf("%s",test);
 		}
 		i=0;
		p=strtok(test,"/");
		while(p!=NULL){
			strcpy(input[i],p);
			//printf("i=%d, %s\n",i,input[i]);		
			i++;
			p=strtok(NULL,"/");
		}
		inputNodes = i;
		
		j=0;
		i=0;
		while(i<inputNodes){
			if(i==0 && strcmp(input[i],"..")==0){
				while(strcmp(input[i],"..")==0){
					cur--;
					i++;
				}
				if(cur>=0){
					strcpy(result[j++],curr[cur]);
				}
			}
			else if(strcmp(input[i],"..")==0){
				int dotcnt=0;
				while(strcmp(input[i],"..")==0){				
					i++;
					dotcnt++;
				}
				for(k=0;k<dotcnt;k++){
					if(j>0){
						j--;
					}
				}
			}
			else if(i==0 && strcmp(input[i],".")==0){
				while(strcmp(input[i],".")==0){					
					i++;
				}
				if(cur>=0){
					strcpy(result[j++],curr[cur]);
				}
			}
			else if(strcmp(input[i],".")==0){
				i++;
			}
			else{
				strcpy(result[j++],input[i]);
				i++;
			}
		}
	 	
	 	//printf("\n 输出：\n");
		if(j==0){
			printf("/");
		}
	 	for(k=0;k<j;k++){
	 		printf("/%s",result[k]);
	 	}
	 	printf("\n");
 	}
 	
 	
 	if(develop){
		fclose(fp);
	}
 	
	return 0;
}
