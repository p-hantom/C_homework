#include <stdio.h>
#include <string.h>
//ֻ��һ��

struct input{	
	char name[80];
	char value[80];
	//int type[2];
};
struct input ss[100];

int main(){
	int n,m;
	n=5;m=2;
	//scanf("%d%d",&n,&m);
	int i,j;
	getchar();
	for(i=0;i<n-2;i++){//input
		scanf("%s",ss[i].name);
		
		//if(getchar()=='"'){//һ�� 
			//ss[i].type[0]=1;//���е�һ��Ԫ����object 
		//	scanf("%s",ss[i].name);
			int len=strlen(ss[i].name);
			ss[i].name[len-2]='\0';//��������
			
			getchar();
			//if(getchar()=='"'){
			//	ss[i].type[1]=2;//���е�2��Ԫ����string
				scanf("%s",ss[i].value);
				int len2=strlen(ss[i].value);
				ss[i].value[len2-2]='\0';//������,
			//} 
	}
	getchar();
	for(i=0;i<m;i++){
		char a[80];
		scanf("%s",a);
		for(j=0;j<n-2;j++){
			if(strcmp(a,ss[i].name)==0){
				printf("STRING %s",ss[i].value);
			}
		}
	}
	
	
	return 0;
}  
