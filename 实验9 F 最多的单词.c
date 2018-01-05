#include <stdio.h> 
#include <string.h>
#include<stdlib.h>

#define M 100 

typedef struct{
	char word[100];
	int count;
}DIC;

int main(){
	int develop=0;
	FILE *fp;
	if(develop){
		fp=fopen("input.txt","r");
	}
	
	DIC dic[M];
	char buff[100];
	int i,n=0,found;
	
 	//while(!feof(fp)){
 	//while(scanf("%s",buff)!=EOF){ 
 	while(1){
 		if(develop){
 			if(feof(fp)){
 				break;
 			}
 			fscanf(fp,"%s",buff);
 			printf("%s\n",buff);
 		}else{
 			if(scanf("%s",buff)==EOF){
 				break;
 			}
 		}
/*
Linux中，在新的一行的开头，按下Ctrl-D，就代表EOF（
如果在一行的中间按下Ctrl-D，则表示输出"标准输入"的缓存区，
所以这时必须按两次Ctrl-D）；Windows中，Ctrl-Z表示EOF。
（顺便提一句，Linux中按下Ctrl-Z，表示将该进程中断，在后台挂起，
用fg命令可以重新切回到前台；
按下Ctrl-C表示终止该进程。）
*/
 		//去掉末尾的标点符号 
 		for(i=strlen(buff)-1;i>=0;i--){
 			if(buff[i]!='.'&&buff[i]!='!'
			 &&buff[i]!='?'&&buff[i]!=','
			 &&buff[i]!=';'&&buff[i]!='\n'){
			 	break;
			 }
 		}
 		i++;
 		buff[i]='\0';
 		//printf("%s\n",buff);
 		
 		//变成小写：
		for(i=0;i<strlen(buff);i++) {
			if(buff[i]>='A'&&buff[i]<='Z'){
				buff[i]-='A'-'a';
			}			
		}		
		//printf("%s\n",buff);
		
		//查找字典 
		found=0;
		for(i=0;i<n;i++){
			if(strcmp(dic[i].word,buff)==0) {
				found=1;
				break;
			}
		}
		if(!found){
			//写入字典
			strcpy(dic[n].word,buff);
			dic[n].count=1;
			n++; 	
		}
		else{
			//修改计数
			dic[i].count ++; 
		}			
 	}
 	
 	int maxCount = 0,maxIdx=0;
 	for(i=0;i<n;i++){
 		//printf("%s %d\n",dic[i].word,dic[i].count);
		if(dic[i].count > maxCount ||
		   (dic[i].count == maxCount && strcmp(dic[i].word,dic[maxIdx].word)>0)) {
			maxCount = dic[i].count;
			maxIdx = i;
		}
	}
	printf("%s %d\n",dic[maxIdx].word,dic[maxIdx].count);
	
 	if(develop){
 		fclose(fp);
 	}
	 
	return 0;
}
