#include <stdio.h>
#include <string.h>

struct role{//创建随从数据结构 
    int attack;//攻击力 
    int health;//血量 
};
struct role player[2][8];//创建一个二维数组存储双方的英雄和随从 
int role_num[2] = {0 , 0};//分别表示双方角色数量 

void summon(int who ,int pos ,int att , int hea);
//召唤函数，who表示召唤方，pos表示在哪个位置召唤，att表示随从攻击力，hea表示血量 

void delete(int who ,int pos);
//移除死掉的随从 

void attack(int who , int pos1 , int pos2);
//攻击函数 

int main(void) {
    int i, j,pos, att , hea,n;
    int attacker , defender;
    char cmd[15];
    int who = 0 ;
    player[0][0].attack = 0 ;//初始化双方英雄的血量和攻击力 
    player[0][0].health = 30;
    player[1][0].attack = 0;
    player[1][0].health = 30;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"summon") == 0)
        {//summon密令，召唤随从 
            scanf("%d%d%d",&pos,&att,&hea);
            summon(who,pos,att,hea);
        }
        if(strcmp(cmd,"attack")== 0)
        {//攻击 
            scanf("%d%d",&attacker,&defender);//attacker表示攻击方位置，defender表示被攻击方位置 
            attack(who,attacker,defender);//攻击，who表示是哪方在攻击，初始who = 0，表示先手攻击 
        }
        if(strcmp(cmd,"end")== 0)
            who = 1- who ;//密令end 后，换对方操作，who = 1 - who 
    }
    
    if(player[0][0].health>0 && player[1][0].health<=0)//所有操作之后，比较双方英雄的血量确定胜负 
        printf("1\n");
    else if(player[0][0].health<=0 && player[1][0].health>0)
        printf("-1\n");
    else
        printf("0\n");
    for(i = 0 ; i < 2 ; i++)//打印双方角色数量，血量 
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
{//召唤函数，who表示召唤方，pos表示在哪个位置召唤，att表示随从攻击力，hea表示血量 
    int i;
    if(pos > 0)//召唤的随从只能在英雄的右方 
    {
        role_num[who]++;//每召唤一次，角色数量加1 
        for(i = role_num[who] ; i > pos ; i --)
        {//位置Pos中和右侧随从都要向右移动一个位置，以让刚召唤的随从放置在pos位置 
            player[who][i] = player[who][i-1];
        }
        player[who][pos].attack = att ;//给召唤的随从赋值攻击力、血量 
        player[who][pos].health = hea ;
    }
    
}

void delete(int who ,int pos)
{//移除死掉的随从 
    int i;
    if(pos > 0)//只有随从才需要移除 
    {
        for(i = pos ; i < role_num[who]; i ++)
        {//移除pos位置的随从，pos右侧的随从都要向左移动一个位置 
            player[who][i] = player[who][i+1];
        }
        role_num[who] -- ;//移除一个随从后，角色数量减1 
    }
}

void attack(int who , int pos1 , int pos2)
{//攻击函数 
    player[who][pos1].health -= player[1-who][pos2].attack;//被攻击方血量的减少值等于攻击方的攻击力值 
    player[1-who][pos2].health -= player[who][pos1].attack;//攻击对方的同时，自己也会受到对方攻击力大小的掉血量 
    if(player[who][pos1].health <= 0)//随从血量小于等于0后，需要移除 
        delete(who , pos1);
    if(player[1-who][pos2].health <= 0)
        delete(1-who , pos2);
}
