#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d",&n);
	int i,j,k;
	char  a[100][100],b[100][100];
	int cnt=0;
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<strlen(a[0]);i++){//��һ�����ʵĵ�i����ĸ 
		cnt=0;//substring's length
		for(j=1;j<n;j++)//��j������ 
			int flag=0;
			for(k=0;k<strlen(a[j]);k++){// ��j�����ʵĵ�k����ĸ 
				
				if(a[0][i]==a[j][k]){
					b[i][cnt]=a[0][i];
					cnt++;
				}
				else{
					if(cnt!=0){
						b[cnt+1]='\0';
						break;						
					}
				}
			}
		}
	}
	
	return 0;
}
