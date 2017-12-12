#include <stdio.h>
#include <string.h>
//n ≤ 100，每行不超过 80 个字符。
//m ≤ 100，每个查询的长度不超过 80 个字符。

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
		if(getchar()=='"'){//一层 
			ss[i].type[0]=1;//此行第一个元素是object 
			scanf("%s",ss[i].name);
			int len=strlen(ss[i].name);
			ss[i].name[len-2]='\0';//读掉”：
			
			if(getchar()=='"'){
				ss[i].type[1]=2;//此行第2个元素是string
				scanf("%s",ss[i].value);
				int len2=strlen(ss[i].value);
				ss[i].value[len2-2]='\0';//读掉”,
			} 
			else if(getchar()=='{') {//二层 
				
			}
			
		} 
		else if{
		}
		
	}
	
	return 0;
} 
