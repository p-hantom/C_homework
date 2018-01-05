#include <stdio.h>

//设有10名歌手(编号为1-10)参加歌咏比赛。另有6名评委打分，每位歌手的得分从键盘输入，
//再依次输入第1个歌手的6位评委打分(10分制，分数为整型，分数之间使用空格分隔)，第2个歌手的6位评委打分...
//以此类推。计算出每位歌手的最终平均得分(保留2位小数)，
//最后按最终得分由高到低的顺序输出每位歌手的编号及最终平均得分。(相同分数时歌手序号小的排前面)
//要求：用结构体存储歌手所有信息，评委分数用结构体中的数组存储。

struct SINGER{
	int num;
	int a[6];
	double average;
};

int main(){
	FILE *fp=fopen("input.txt","r");
	
	struct SINGER singer[10];
	int i,j,n=10;
	double sum;
	for(i=0;i<n;i++){
		singer[i].num=i+1;
		sum = 0;
		for(j=0;j<6;j++){
			fscanf(fp,"%d",&singer[i].a[i]);
			//scanf("%d",&singer[i].a[i]);
			sum += singer[i].a[i];
		}
		singer[i].average = sum/6;
	}
	fclose(fp);
//	struct SINGER singer[]={
//		{1,{1,1,1,1,1,1},1},
//		{2,{2,2,2,2,2,2},2},
//		{3,{3,3,3,3,3,3},3},
//		{5,{4,4,4,4,4,4},4},
//		{4,{4,4,4,4,4,4},4},
//		{8,{2,2,2,2,2,2},2},
//		{7,{9,9,9,9,9,9},9},
//		{6,{7,7,7,7,7,7},7},
//	};
	
	int max_i,min_num;
	struct SINGER s;
	double max_score;
	
	int len = n;//sizeof(singer)/sizeof(struct SINGER);
	for(i=0;i<len-1;i++){
		max_i=i;
		max_score=singer[i].average;
		min_num = singer[i].num;
		for(j=i;j<len;j++){
			if((singer[j].average==max_score&&singer[j].num<min_num) ||
			    singer[j].average>max_score){
			   		max_i=j;
			   		max_score=singer[j].average;
					min_num = singer[j].num;
			   }
		}
		if(max_i != i){
			s = singer[max_i];
			singer[max_i] = singer[i];
			singer[i] = s;
		}
	}
	for(i=0;i<len;i++){
		printf("%d %0.2lf\n",singer[i].num,singer[i].average);
	}
	
	return 0;
}
