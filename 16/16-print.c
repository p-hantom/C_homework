#include <stdio.h>
#include <string.h>

void print(){
	char a[100];
	int i=0;
//	while(a[i]=getchar()!='\0'){??????????????why???????????????
//		i++;
//	}

	gets(a);      //  ??????????????why???????????????


//	char c=getchar();??????????????why???????????????
//	while(c!='\0'){
//		a[i]=c;
//		i++;
//		c=getchar();
//	}

	for(i=strlen(a)-1;i>=0;i--){
		if(a[i]>='a'&&a[i]<='z'){
			printf("%c",a[i]);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<2;i++){
		print();
	}
	
	return 0;
}
