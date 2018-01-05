#include <stdio.h>
#include <malloc.h>  
/* malloc二维数组的2种方法:
int **a = malloc(sizeof(int)*3);  
    a[0]= malloc(sizeof(int)*2);  
    a[1]= malloc(sizeof(int)*2);  
    a[2]= malloc(sizeof(int)*2);  
    a[0][0] =1;  
    a[0][1] =2;  
    a[1][0] =3;  
    a[1][1] = 4;  
    a[2][0] =5;  
    a[2][1] = 6;  
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[0][0],a[0][1],a[1][0],a[1][1],a[2][0],a[2][1]);   
    free(a[0]);  
    free(a[1]);  
    free(a[2]);  
    free(a);  
    
int (*a)[2] = malloc(sizeof(int)*3*2);  
    a[0][0] =1;  
    a[0][1] =2;  
    a[1][0] =3;  
    a[1][1] = 4;  
    a[2][0] =5;  
    a[2][1] = 6;  
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[0][0],a[0][1],a[1][0],a[1][1],a[2][0],a[2][1]);   
    free(a);      
    
*/
int main(){
	int m,n,p,q;
	//int m1[100][100]={0},m2[100][100];//,m3[100][100];
	scanf("%d%d%d%d",&m,&n,&p,&q);
	//FILE *fp=fopen("input.txt","r");
	//fscanf(fp,"%d%d%d%d",&m,&n,&p,&q);
	 
	int (*m1)[n] = malloc(sizeof(int)*m*n);  
	int (*m2)[q] = malloc(sizeof(int)*p*q);
	
	int i,j,k;
	if(n!=p){
		printf("error\n");
		return -1;
	}	
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&m1[i][j]);
			//fscanf(fp,"%d",&m1[i][j]);			
		}
	}
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&m2[i][j]);
			//fscanf(fp,"%d",&m2[i][j]);
		}
	}
	int temp; 
	for(k=0;k<m;k++){
		for(i=0;i<q;i++){
			temp=0; 
			for(j=0;j<n;j++){
				temp+=m1[k][j]*m2[j][i];//m3[k][i]+=m1[k][j]*m2[j][i];//->可以直接输出,不用M3 				
			}
			printf("%d ",temp);
		}
		printf("\n");
	}
	
//	for(i=0;i<m;i++){
//		for(j=0;j<q;j++){
//			printf("%d ",m3[i][j]);
//		}
//		printf("\n");
//	}
	
	free(m1);
	free(m2);
	
	//fclose(fp);
	
	return 0;
}

