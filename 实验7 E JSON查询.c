#include <stdio.h> 
#include <string.h>
#include<stdlib.h>

#define MAX 100
int ID[MAX];
int pID[MAX];
char key[MAX][80];
char value[MAX][80];


int main(){
	int develop=1;
	FILE *fp ;//= fopen("input.txt","r"); 
	if(develop){
		fp = fopen("input.txt","r"); 
	}
	int n,m,i,j,k;		
	if(develop){
		fscanf(fp,"%d%d\n",&n,&m);
	}
	else{
		scanf("%d%d\n",&n,&m);
	} 
	char line[81];
	char str[1000];// = (char*) malloc(80*n*sizeof(char));	 
	
	//把json读入str: 
	k=0;
	for(i=0;i<n;i++) {		
		if(develop){
			fgets(line,80,fp);
			printf("line= %s\n",line);
		}
		else{
			//gets(line);
			fgets(line,80, stdin);
		}
		
		for(j=0;j<strlen(line);j++){
			str[k++]=line[j];
		}
	}
 	str[k]='\0';
 //printf("\nstr= %s\n",str);

	int keyCount=0;
	int parentID=-1;
	int id = -1;	
	char ch;
	int flag = -1;//
	i = -1;
	while(1){
		i++;		
		ch=str[i]; 
		if(ch=='\0'){
			break;
		}
		else if(ch=='{'){
			parentID = id;
			flag = 0;//表示接下来开始读key 			
		}
		else if (ch=='}'){
			parentID = -1;
			flag = 0;//表示接下来开始读key 			
		} 
		else if (ch=='\"'){			
			if(flag==0){//开始读key 
				id++;
	    		ID[id]=id;
	    		pID[id]=parentID;
	    		value[id][0]='\0';
	        }
    		j=0;
    		int f;
    		do{
    			f = 0;
    			i++;
				ch=str[i];
				if(ch=='\\'&&str[i+1]=='\"') {				
				    f=1;
				    ch='\"';
				    i++;
				}
				else if(ch=='\\'&&str[i+1]=='\\') {				
				    f=1;
				    ch='\\';
				    i++;
				}
				if(flag==0){
					key[id][j++]=ch;
				}
				else if(flag==1){
					value[id][j++]=ch;
				}								
    		} while(f || ch!='\"');
    		if(flag==0){
				key[id][j-1]='\0';
			    flag = 1; //key结束 
			}
			else if(flag==1){
				value[id][j-1]='\0';
			    flag = 0; 
			}																		 
		}				 
	}
 	if(develop){
 		for(i=0;i<=id;i++){
	 		printf("id=%d,key=%s,pid=%d,value=%s\n",ID[i],&key[i],pID[i],&value[i]);
	 	}
 	}
	 
	
	for(k=0;k<m;k++){
		if(develop)		{
			fscanf(fp,"%s",line);
			printf("search-》%s\n",line);
		}
		else{
			scanf("%s",line);
		}		
		
		char search[81];
		strcpy(search,line);
		char *p=strchr(search, '.');
		int pid = -1;
		char * skey = search;	
		if(p){
			 skey = strtok(search,".");	
			 for(i=0;i<=id;i++){
			 	if(strcmp(key[i],skey)==0&& pID[i]==pid){
					pid = ID[i];
					break;						
				}
			}	 
			skey = strtok(NULL,".");
		}
		//Search key value:
		int keyfound = 0;
		for(i=0;i<=id;i++){
			if(strcmp(key[i],skey)==0&& pID[i]==pid){			
				if(strlen(value[i])>0){
					printf("STRING %s\n",&value[i]);
				}
				else{
					printf("OBJECT\n");
				}
				keyfound = 1;
				break;						
			}
		}
		if(!keyfound){
			printf("NOTEXIST\n");
		}
	 
	}
	
	if(develop){
		fclose(fp);	
	}
 	
	return 0;
}
