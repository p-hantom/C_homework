#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>  
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>  
#include <math.h>
#include <string.h>

#define M 1000

typedef struct{
	int key;
	int time;
	int flag;//0:return; 1:borrow 
}Node;

void f(int develop){
	FILE *fp = NULL;
	if(develop){//开发时从文件读入输入数据 
		fp = fopen("input.txt","r");
	}
	
	int n,m,i,j,k,nOps,nkeys;
	if(develop) {
		fscanf(fp,"%d%d",&nkeys,&nOps);
	}
	else{
		scanf("%d%d",&nkeys,&nOps);
	}
	
	Node op[M];
	int key,timeborrow,timereturn;
	n=0;
	while(n<2*nOps){
		if(develop) {
			fscanf(fp,"%d%d%d",&key,&timeborrow,&timereturn);			
		}
		else{
			scanf("%d%d%d",&key,&timeborrow,&timereturn);
		}
		//create a borrow record:
		op[n].key = key;
		op[n].flag = 1;//borrow
		op[n].time = timeborrow;
		n++;
		//create a return record:
		op[n].key = key;						
		op[n].flag = 0;//return;
		op[n].time = timeborrow+timereturn;
		n++;
	}
	if(develop){
		for(i=0;i<n;i++){
			printf("key# %d, time=%d, flag=%d\n",op[i].key,op[i].time,op[i].flag);
		}
	} 
	
	//sort
	Node nd,tmp;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(op[j].time < op[k].time ||
			   (op[j].time == op[k].time 
			    && op[j].flag < op[k].flag) ||
			   (op[j].time == op[k].time 
			    && op[j].flag == op[k].flag)
				&& op[j].key < op[k].key){
				k = j;
			}
		}
		if(k!=i){
			tmp = op[k];
			op[k]=op[i];
			op[i]=tmp;
		}		
	}
	
	if(develop){
		printf("\nsorted:\n");
		for(i=0;i<n;i++){
			printf("key# %d, time=%d, flag=%d\n",op[i].key,op[i].time,op[i].flag);
		}
	} 
	
	//perform operations
	int kk[1000];
	for(i=1;i<=nkeys;i++){
		kk[i]=i;
	}
	for(i=0;i<n;i++){
		if(develop){			
			printf("key# %d, flag=%d\n",op[i].key,op[i].flag);			
		} 
		if(op[i].flag ==1){//borrow			
			for(k=1;k<=nkeys;k++){
				if(kk[k]==op[i].key){
					kk[k]=-1;
					break;
				}
			}			
		}
		else{//return
			for(k=1;k<=nkeys;k++){
				if(kk[k]==-1){
					kk[k]=op[i].key;
					break;
				}
			}
		}
		if(develop)		{
			for(k=1;k<=nkeys;k++){
				printf("%d ",kk[k]);
			}
			printf("\n");
		}				
	}
	
	for(i=1;i<=nkeys;i++){
		printf("%d ",kk[i]);
	}
	printf("\n");
	
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

