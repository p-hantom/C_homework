#include<stdio.h>
#include<string.h>    
 

#define ROW 15
#define COL 10
#define N 4
 
int main()
{
    int board[ROW + 1][COL];//地图
    int block[N][N];//下落块的样子
    int row,col,i,j,k;
    // 输入数据  
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
    // 提取小方块坐标  
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

    // 模拟小方块落下过程  
    row = 1;//从顶部开始下落，如果可以放就往下再落一行，如果不能就停
    col--;//列数是最后一行输入的，所以在程序中操作的只有行数，列数只减一次变成下标
    int checkflag;
    while (1)
    {
        checkflag = 0;
        for ( i = 0; i < s_pos; i++)
        {
            if (board[row + pos[i][0]][col + pos[i][1]] == 1)//判断地图上那个要放的区域有没有小方块
            {
                checkflag = 1;
                break;
            }
        }   
        if (checkflag)//判断前面的for循环里面是不是能下落了，不能就结束了
            break;
        row++;
    }
    row--;//结束的时候是不能的，它的上一次下落一定是可以的，所以回到上一次

    // 合并小方块到方格  
    for ( i = 0; i < s_pos; i++)
    {
        board[row + pos[i][0]][col + pos[i][1]] = 1;
    }


    // 输出结果  
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
