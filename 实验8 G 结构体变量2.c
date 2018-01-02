#include <stdio.h>
#include <string.h>
#define LEN 20
#define M 100
struct StudentType{
	char name[LEN];
	int math;
	int english;
	int total;
};
int main(){
	struct StudentType std[]={
		"Tom",80,70,0,
		"Andy",80,90,0,
		"John",80,80,0, 
	};
	
	int i,j;
	int len = sizeof(std)/sizeof(struct StudentType);
	for(i=0;i<len;i++){
		std[i].total = std[i].math+std[i].english;
	}
	
	int max_total,max_i;
	struct StudentType s;
	for(i=0;i<len-1;i++){
		max_i = i;
		max_total = std[i].total;
		for(j=i;j<len;j++){
			if(std[j].total > max_total){
				max_i = j;
				max_total = std[j].total;	
			}
		}
		if(max_i != i){
			s = std[max_i];
			std[max_i] = std[i];
			std[i] = s;
		}
	}
	
	for(i=0;i<len;i++){
		printf("%s %d\n",std[i].name,std[i].total);
	}
	return 0;
} 
