/*
H: �������˷�
����
 
���������������Ļ���
 
����
 
��1����һ������n����ʾ�����n�����ݡ�ÿ������ռһ�У�������������a��b���ÿո������
0 <= a,b <= 10^500(10��500�η�)
 
���
 
��ÿ������������������Ļ��������С�
 
����
 
����

3
1 2
5 8
2 9999

��� 
2
40
19998
 
*/ 

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define and &&
#define or ||
#define not !
#define Int(X) (X - '0')
#define Char(X) (X + '0')

char *multiBigInteger(const char *, const char *);
int checkNum(const char *);
int copied_code(){
	char num1[100] = {'\0'}, num2[100] = {'\0'};
    while(scanf("%s%s", num1, num2) != EOF)
    {
        char *result = "0";
        if(strlen(num1) > 100 or strlen(num2) > 100)
        {
            printf("ERROR\n");
            return 1;
        }
        if(checkNum(num1) or checkNum(num2))
        {
            printf("ERROR: input must be an Integer\n");
            return 1;
        }
        printf("num1:\t%s\nnum2:\t%s\n", num1, num2);
        result = multiBigInteger(num1, num2);
        if(result[0] == '0')
        {
            int i;
            printf("result:\t");
            for(i = 1; (size_t)i < strlen(result); i++)
            {
                printf("%c", result[i]);
            }
            printf("\n");
        }
        else
        {
            printf("result:\t%s\n", result);
        }
        printf("\n");
    }
    return 0;
} 
void hw(){
	int n, i;
	char num1[100],num2[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		char *result = "0";
		scanf("%s%s",num1,num2);
		result = multiBigInteger(num1, num2);
		//printf("%s\n",result); 
		
		int j=0;
		while(result[j]=='0') {
			j++;
		}
		
		for(;j<strlen(result);j++){
			printf("%c",result[j]);
		}
		printf("\n");
		free(result);
    }
}
void test(){
	char num1[]="1234",num2[]="123",*result;
	result = multiBigInteger(num1, num2);
	int i=0;
	//printf("%c %d ",result[0],result[0]);

	while(result[i]=='0') {
		i++;
	}
	for(;i<strlen(result);i++){
		printf("%c",result[i]);
	}
	printf("\n");		
}
int main(void)
{
	hw();
	//test();
    return 0;
} 

int checkNum(const char *num)
{
    int i;
    for(i = 0; (size_t)i < strlen(num); i++)
    {
        if(num[i] < '0' or num[i] > '9')
        {
            return 1;
        }
    }
    return 0;
}

char *multiBigInteger(const char *num1, const char *num2)
{
    char *tempRes = NULL;              //��������ÿ����˵Ľ��
    char *result = NULL;               //�����������ս��
    int tempResLen;                    //ÿ����˽������󳤶�
    int num1Len = strlen(num1);        //num1�ĳ���
    int num2Len = strlen(num2);        //num2�ĳ���
    int resultLen;                     //�������󳤶�
    int i, j, k;                       //ѭ��������
    int res;                           //ÿ��һλ���/��ӵĽ��
    int carry = 0;                     //��λ
    int offset = 0;                    //�ӷ���ƫ��λ
    resultLen = num1Len + num2Len - 1; //����������Ϊnum1���Ⱥ�num2����֮�ͣ������±��0��ʼ������Ҫ��һ
    tempResLen = num1Len;              //ÿ��num1����num2ÿһλ�Ľ����󳤶���num1Len+1,�����±��0��ʼ�����Լ�һ��Լȥ1,ֻʣnum1Len
    //��ʼ��resultΪ0
    result = (char *)malloc((resultLen+2)*sizeof(char));
    memset(result, '0', (resultLen+1)*sizeof(char));
    result[resultLen+1] = 0;

    tempRes = (char *)malloc((tempResLen+2)*sizeof(char));
    for(j = num2Len - 1; j >= 0; j--)
    {
        //��ʼ��tempResÿλΪ0
        memset(tempRes, '0', (tempResLen+1)*sizeof(char));
        /*����num1��num2��λ��˵Ľ�������浽tempRes��
         *ÿһλ��˺���֮ǰ�Ľ�λ��ӵó�res����res�ĸ�
         *λ(res%10)���浽tempRes��,Ȼ��res������λ��
         *(res/10)��Ϊ��λcarry*/
        for(i = num1Len-1; i >= 0; i--)
        {
            res = Int(num1[i]) * Int(num2[j]) + carry;
            tempRes[tempResLen--] = Char(res % 10);
            carry = res / 10;
        }
        //tempRes��һλΪ��λ���ոյ�ѭ����û����ģ����ѽ�λ����
        tempRes[tempResLen] = Char(carry);
        tempResLen = num1Len;
        carry = 0;
        //��result��ĩβ��ʼ����ͣ�����һ�Σ�����ƫ��һλ
        for(k = resultLen-offset; k > (resultLen-offset-num1Len); k--)
        {
            res = Int(result[k]) + Int(tempRes[tempResLen--]) + carry;
            result[k] = Char(res%10);
            carry = res/10;
        }
        result[k] += Int(tempRes[tempResLen] + carry);
        carry = 0;
        tempResLen = num1Len;
        offset++;

    }
    //printf("num1Len:%d\nnum2Len:%d\n", num1Len, num2Len);
    return result;
}

 

