#include <stdio.h>

//����10������(���Ϊ1-10)�μӸ�ӽ����������6����ί��֣�ÿλ���ֵĵ÷ִӼ������룬
//�����������1�����ֵ�6λ��ί���(10���ƣ�����Ϊ���ͣ�����֮��ʹ�ÿո�ָ�)����2�����ֵ�6λ��ί���...
//�Դ����ơ������ÿλ���ֵ�����ƽ���÷�(����2λС��)��
//������յ÷��ɸߵ��͵�˳�����ÿλ���ֵı�ż�����ƽ���÷֡�(��ͬ����ʱ�������С����ǰ��)
//Ҫ���ýṹ��洢����������Ϣ����ί�����ýṹ���е�����洢��

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
