#include <stdio.h>
#include <string.h>
//n �� 100��ÿ�в����� 80 ���ַ���
//m �� 100��ÿ����ѯ�ĳ��Ȳ����� 80 ���ַ���

struct input{
	char name[80];
	char value[80];
	int type[2]={0};
};
struct input ss[100];

int main(){
	int n,m;
	n=10;m=5;
	//scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){//input
		scanf("%s",ss[i].name);
		if(getchar()=='{'){
			continue;			 
		}
		if(getchar()=='"'){//һ�� 
			ss[i].type[0]=1;//���е�һ��Ԫ����object 
			scanf("%s",ss[i].name);
			int len=strlen(ss[i].name);
			ss[i].name[len-2]='\0';//��������
			
			if(getchar()=='"'){
				ss[i].type[1]=2;//���е�2��Ԫ����string
				scanf("%s",ss[i].value);
				int len2=strlen(ss[i].value);
				ss[i].value[len2-2]='\0';//������,
			} 
			else if(getchar()=='{') {//���� 
				
			}
			
		} 
		else if{
		}
		
	}
	
	return 0;
} 
