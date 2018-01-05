#include <stdio.h>

void f(FILE *fp){
	int k1,m,i,j;
//	m=5;k1=3;
	int a[1000000];//={3,9,3,9,3};
	if(fp==NULL){
		scanf("%d%d",&m,&k1);
	}
	else{
		fscanf(fp,"%d%d",&m,&k1);
	}
	
	for(i=0;i<m;i++){		
		if(fp==NULL){
			scanf("%d",&a[i]);
		}
		else{
			fscanf(fp,"%d",&a[i]);
		}
	}
	if(m<k1) {
		printf("error\n");
		return;
	}
	
	int k,max;
	int cntk=1,found=0;
	for(i=0;i<m-1;i++){
		k=i;		
		for(j=i+1;j<m;j++){
			if(a[j]>a[k]){
				k=j;				
			}
		}
		
		if(k!=i){
			int temp=a[i];
			a[i]=a[k];
			a[k]=temp;
	    }
		if(i==0 && k1==1){
			found = 1;
			printf("%d\n",a[i]);
			break;
		}
		else if(i>0 && a[i]!=a[i-1]){
			cntk++;
			 if(k1==cntk){
			 	found = 1;
				printf("%d\n",a[i]);
				break;
			 }
		}		 
	}
	if(!found) {
		printf("error\n");
	}
//	int cnt=0;
//	for(i=1;i<m;i++){
//		if(a[i-1]>a[i]){
//			cnt++;
//			if(cnt==k1){
//				printf("%d\n",a[i-1]);
//				return;
//			}
//		}
//	}
//	if(k1==m){
//		if(cnt==m-1&&a[m-1]<=a[m-2]){
//			printf("%d\n",a[m-1]);
//		}
//	}
//	else if(k1==1&&cnt==0){
//		printf("%d\n",a[m-1]);
//	}
//	else{
//		printf("error\n");
//	}
}

int main(){
	//FILE *fp=fopen("input.txt","r");
	int n,m;
	//fscanf(fp,"%d",&n);
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		//f(fp);
		f(NULL);
	}
	
	//fclose(fp);
	return 0;
}
