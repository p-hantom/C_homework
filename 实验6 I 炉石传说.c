#include <stdio.h>
#include <string.h>

struct role{//����������ݽṹ 
    int attack;//������ 
    int health;//Ѫ�� 
};
struct role player[2][8];//����һ����ά����洢˫����Ӣ�ۺ���� 
int role_num[2] = {0 , 0};//�ֱ��ʾ˫����ɫ���� 

void summon(int who ,int pos ,int att , int hea);
//�ٻ�������who��ʾ�ٻ�����pos��ʾ���ĸ�λ���ٻ���att��ʾ��ӹ�������hea��ʾѪ�� 

void delete(int who ,int pos);
//�Ƴ���������� 

void attack(int who , int pos1 , int pos2);
//�������� 

int main(void) {
    int i, j,pos, att , hea,n;
    int attacker , defender;
    char cmd[15];
    int who = 0 ;
    player[0][0].attack = 0 ;//��ʼ��˫��Ӣ�۵�Ѫ���͹����� 
    player[0][0].health = 30;
    player[1][0].attack = 0;
    player[1][0].health = 30;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"summon") == 0)
        {//summon����ٻ���� 
            scanf("%d%d%d",&pos,&att,&hea);
            summon(who,pos,att,hea);
        }
        if(strcmp(cmd,"attack")== 0)
        {//���� 
            scanf("%d%d",&attacker,&defender);//attacker��ʾ������λ�ã�defender��ʾ��������λ�� 
            attack(who,attacker,defender);//������who��ʾ���ķ��ڹ�������ʼwho = 0����ʾ���ֹ��� 
        }
        if(strcmp(cmd,"end")== 0)
            who = 1- who ;//����end �󣬻��Է�������who = 1 - who 
    }
    
    if(player[0][0].health>0 && player[1][0].health<=0)//���в���֮�󣬱Ƚ�˫��Ӣ�۵�Ѫ��ȷ��ʤ�� 
        printf("1\n");
    else if(player[0][0].health<=0 && player[1][0].health>0)
        printf("-1\n");
    else
        printf("0\n");
    for(i = 0 ; i < 2 ; i++)//��ӡ˫����ɫ������Ѫ�� 
    {
        printf("%d\n",player[i][0].health);
        printf("%d ",role_num[i]);
        for(j = 1 ; j <= role_num[i]; j++)
        {
            printf("%d ",player[i][j].health);
        }
        printf("\n");
    }
    return 0;
}

void summon(int who ,int pos ,int att , int hea)
{//�ٻ�������who��ʾ�ٻ�����pos��ʾ���ĸ�λ���ٻ���att��ʾ��ӹ�������hea��ʾѪ�� 
    int i;
    if(pos > 0)//�ٻ������ֻ����Ӣ�۵��ҷ� 
    {
        role_num[who]++;//ÿ�ٻ�һ�Σ���ɫ������1 
        for(i = role_num[who] ; i > pos ; i --)
        {//λ��Pos�к��Ҳ���Ӷ�Ҫ�����ƶ�һ��λ�ã����ø��ٻ�����ӷ�����posλ�� 
            player[who][i] = player[who][i-1];
        }
        player[who][pos].attack = att ;//���ٻ�����Ӹ�ֵ��������Ѫ�� 
        player[who][pos].health = hea ;
    }
    
}

void delete(int who ,int pos)
{//�Ƴ���������� 
    int i;
    if(pos > 0)//ֻ����Ӳ���Ҫ�Ƴ� 
    {
        for(i = pos ; i < role_num[who]; i ++)
        {//�Ƴ�posλ�õ���ӣ�pos�Ҳ����Ӷ�Ҫ�����ƶ�һ��λ�� 
            player[who][i] = player[who][i+1];
        }
        role_num[who] -- ;//�Ƴ�һ����Ӻ󣬽�ɫ������1 
    }
}

void attack(int who , int pos1 , int pos2)
{//�������� 
    player[who][pos1].health -= player[1-who][pos2].attack;//��������Ѫ���ļ���ֵ���ڹ������Ĺ�����ֵ 
    player[1-who][pos2].health -= player[who][pos1].attack;//�����Է���ͬʱ���Լ�Ҳ���ܵ��Է���������С�ĵ�Ѫ�� 
    if(player[who][pos1].health <= 0)//���Ѫ��С�ڵ���0����Ҫ�Ƴ� 
        delete(who , pos1);
    if(player[1-who][pos2].health <= 0)
        delete(1-who , pos2);
}
