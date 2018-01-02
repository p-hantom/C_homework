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
Linux�У����µ�һ�еĿ�ͷ������Ctrl-D���ʹ���EOF��
�����һ�е��м䰴��Ctrl-D�����ʾ���"��׼����"�Ļ�������
������ʱ���밴����Ctrl-D����Windows�У�Ctrl-Z��ʾEOF��
��˳����һ�䣬Linux�а���Ctrl-Z����ʾ���ý����жϣ��ں�̨����
��fg������������лص�ǰ̨��
����Ctrl-C��ʾ��ֹ�ý��̡���
*/
 		//ȥ��ĩβ�ı����� 
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
 		
 		//���Сд��
		for(i=0;i<strlen(buff);i++) {
			if(buff[i]>='A'&&buff[i]<='Z'){
				buff[i]-='A'-'a';
			}			
		}		
		//printf("%s\n",buff);
		
		//�����ֵ� 
		found=0;
		for(i=0;i<n;i++){
			if(strcmp(dic[i].word,buff)==0) {
				found=1;
				break;
			}
		}
		if(!found){
			//д���ֵ�
			strcpy(dic[n].word,buff);
			dic[n].count=1;
			n++; 	
		}
		else{
			//�޸ļ���
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
