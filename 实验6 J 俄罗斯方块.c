#include<stdio.h>
#include<string.h>    
 

#define ROW 15
#define COL 10
#define N 4
 
int main()
{
    int board[ROW + 1][COL];//��ͼ
    int block[N][N];//����������
    int row,col,i,j,k;
    // ��������  
    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            //scanf("%d",&board[i][j]); 
			board[i][j] = 0;
        }
    }
	board[10][7]=board[11][6]=board[12][6]=board[14][4]=1;
	board[13][0]=board[13][1]=board[13][2]=board[13][6]=board[13][7]=board[13][8]=board[13][9]=1;
	for(i=0;i<15;i++){
		for(j=0;j<10;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
	
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
        	//scanf("%d",&block[i][j]);   
			block[i][j] = 0;          
        }
    }
    block[1][1] =block[1][2] =block[1][3]=block[2][3]=1;
    for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		{
			printf("%d ",block[i][j]);
		}
		printf("\n");
	}
    
	//scanf("%d",&col);    
	col=3;
	
    int pos[N*N][2];
    int s_pos = 0;
    // ��ȡС��������  
    for ( i = N - 1; i >= 0; i--)
    {
        for ( j = 0; j < N; j++)
        {
            if (block[i][j] == 1) 
            {
                pos[s_pos][0] = i;
                pos[s_pos][1] = j;
                s_pos++;
            }
        }
    }

    // ģ��С�������¹���  
    row = 1;//�Ӷ�����ʼ���䣬������Էž���������һ�У�������ܾ�ͣ
    col--;//���������һ������ģ������ڳ����в�����ֻ������������ֻ��һ�α���±�
    int checkflag;
    while (1)
    {
        checkflag = 0;
        for ( i = 0; i < s_pos; i++)
        {
            if (board[row + pos[i][0]][col + pos[i][1]] == 1)//�жϵ�ͼ���Ǹ�Ҫ�ŵ�������û��С����
            {
                checkflag = 1;
                break;
            }
        }   
        if (checkflag)//�ж�ǰ���forѭ�������ǲ����������ˣ����ܾͽ�����
            break;
        row++;
    }
    row--;//������ʱ���ǲ��ܵģ�������һ������һ���ǿ��Եģ����Իص���һ��

    // �ϲ�С���鵽����  
    for ( i = 0; i < s_pos; i++)
    {
        board[row + pos[i][0]][col + pos[i][1]] = 1;
    }


    // ������  
    for ( i = 0; i<ROW; i++) 
    {
        for ( j = 0; j<COL; j++) 
        {
            if (j != 0)
                printf(" ");//cout << " ";
            printf("%d",board[i][j]);//cout << board[i][j];
        }
        printf("\n");//cout << endl;
    }
    return 0;
}
