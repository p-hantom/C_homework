/*
B: �������ڼ�
����
��֪1900��1��1��������һ��������֮�������һ�������ڼ���

����
1900��1��1���Ժ����һ�Ϸ����ڣ���ʽΪyyyy-MM-dd����2000-01-01��

���
������������Ӧ�����ڡ�

����
����	���
2017-11-11	Saturday

*/ 

#include <stdio.h>
#include <stdlib.h>

int main(){
	int y,m,d,n;
	int a[13],i,sum1=0,sum2,sum=0;
	scanf("%d-%d-%d",&y,&m,&d);
	sum2=d;
	
	for(i=1900;i<y;i++){
		if(i%4==0&&i%100!=0||i%400==0){
			n=366;
		}
		else
			n=365;
		sum1+=n;
	}
	if(y%4==0&&y%100!=0||y%400==0)
		a[2]=29;
	else
		a[2]=28;
	
	for(i=1;i<m;i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			a[i]=31;
		}
		else if(i==4||i==6||i==9||i==11){
			a[i]=30;
		}
		sum2+=a[i];
	}

	sum+=sum1+sum2;
	
	switch((sum-1)%7){
		case 0:printf("Monday\n");break;
		case 1:printf("Tuesday\n");break;
		case 2:printf("Wednesday\n");break;
		case 3:printf("Thursday\n");break;
		case 4:printf("Friday\n");break;
		case 5:printf("Saturday\n");break;
		case 6:printf("Sunday\n");break;
	} 
	
	
	return 0;
}

