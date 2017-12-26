#include <stdio.h>

int main(){
	int m,n,p,q;
	int m1[100][100]={0},m2[100][100],m3[100][100];
	//scanf("%d%d%d%d",&m,&n,&p,&q);
	FILE *fp=fopen("test.txt","r");
	fscanf(fp,"%d%d%d%d",&m,&n,&p,&q);
	int i,j,k;
	if(n!=p){
		printf("error\n");
		return -1;
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//scanf("%d",&m1[i][j]);
			fscanf(fp,"%d",&m1[i][j]);
		}
	}
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			//scanf("%d",&m1[i][j]);
			fscanf(fp,"%d",&m2[i][j]);
		}
	}
	for(k=0;k<m;k++){
		for(i=0;i<q;i++){
			for(j=0;j<n;j++){
				m3[k][i]+=m1[k][j]*m2[j][i];
			}
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<q;j++){
			printf("%d ",m3[i][j]);
		}
		printf("\n");
	}
	
	fclose(fp);
	
	return 0;
}
