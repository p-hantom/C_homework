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
	for(i=0;i<strlen(a[0]);i++){//第一个单词的第i个字母 
		cnt=0;//substring's length
		for(j=1;j<n;j++)//第j个单词 
			int flag=0;
			for(k=0;k<strlen(a[j]);k++){// 第j个单词的第k个字母 
				
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
