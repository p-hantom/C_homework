#include <stdio.h>
#include <stdlib.h>
 
#define M 100
struct STD{
	char name[20];
	int chinese;
	int math;
	int english;
	double average;
};

void print(FILE *fp,struct STD std){
	fprintf(fp,"%s ",std.name);
	fprintf(fp,"%d ",std.chinese);
	fprintf(fp,"%d ",std.math);
	fprintf(fp,"%d ",std.english);
	fprintf(fp,"%.0lf\n",std.average);
}

int main(){
	FILE *fp=fopen("student.txt","r");
	if(fp==NULL){
		exit(0);
	}
	struct STD std[M];
	int n=0;
	while(1) {		
		fscanf(fp,"%s",std[n].name);
		fscanf(fp,"%d",&std[n].chinese);
		fscanf(fp,"%d",&std[n].math);
		fscanf(fp,"%d",&std[n].english);
		fscanf(fp,"%lf",&std[n].average);	
		n++;
		if(feof(fp)) break;
	}
	fclose(fp);
 
 	struct STD s;
 	scanf("%s",s.name);
 	scanf("%d",&s.chinese);
 	scanf("%d",&s.math);
	scanf("%d",&s.english);
	s.average=(s.chinese + s.math + s.english)/3.0;
	
 	int i,j; 
	for(i=0;i<n;i++){
		if(s.average > std[i].average ||
		  (s.average == std[i].average&&strcmp(s.name,std[i].name)<0)){
			break;
		}
	}
	
 	fp=fopen("student.txt","w");
	if(fp==NULL){
		exit(0);
	}
 	for(j=0;j<i;j++){
 		print(fp,std[j]);
 	}
 	print(fp,s);
 	for(j=i;j<n;j++){
 		print(fp,std[j]);
 	}
 	
 	fclose(fp);
 	
	return 0;
}
