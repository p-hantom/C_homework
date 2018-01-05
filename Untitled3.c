#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct PALYER{
	int win;
	int lose;
	int tie;
	int j;
	int s;
	int b;
};

void f(int develop);

int main(){
	int develop=1;
	f(develop);
	
	return 0;
}

void f(int develop){
	struct PALYER a1={0,0,0,0,0,0};
	struct PALYER a2={0,0,0,0,0,0};
	int i,j,k,n;
	char g1,g2;
	FILE *fp;
	if(develop){
		fp=fopen("test.txt","r");
		fscanf(fp,"%d",&n);
	}
	else{
		scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		if(develop){
			fscanf(fp,"%c%c",&g1,&g2);
		}
		else{
			scanf("%c%c",&g1,&g2);
		}
		switch(g1){
			case 'J':switch(g2){
				case 'J':a1.tie++;a2.tie++;break;
				case 'C':a2.win++;a1.lose++;a2.s++;break;
				case 'B':a1.win++;a2.lose++;a1.j++;break;
			}
			case 'C':switch(g2){
				case 'J':a1.win++;a2.lose++;a1.s++;break;
				case 'C':a2.tie++;a1.tie++;break;
				case 'B':a1.lose++;a2.win++;a2.b++;break;
			}
			case 'B':switch(g2){
				case 'J':a2.win++;a1.lose++;a2.j++;break;
				case 'C':a2.lose++;a1.win++;a1.b++;break;
				case 'B':a1.tie++;a2.tie++;break;
			}
		}
		
	}
	printf("%d %d %d\n",a1.win,a1.tie,a1.lose);
	printf("%d %d %d\n",a2.win,a2.tie,a2.lose);
	
	if(develop){
		fclose(fp);
	}
}

