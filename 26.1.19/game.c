#include "game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS],int row,int col){
    printf("-----扫雷-----\n");
    for(int j = 0; j <= col; j++){
        printf("%d ",j);
    }
    printf("\n");
    for(int i = 1; i <= row; i++){
        printf("%d ",i); //打印行号
        for(int j = 1; j <= col; j++){
            printf("%c ",board[i][j]); //%c后加个空格
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS],int row,int col){
    int count = easy; //设雷数量
    while(count){
        int x = rand() % row + 1;
        int y = rand() % col + 1;

        if(board[x][y] == '0'){
            board[x][y] = '#';
            count--;
        }
    }
}

//统计雷
int getminecount(char board[ROWS][COLS],int x,int y){
    int count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nx = x + i;
            int ny = y + j;
            if(nx >=1 && nx <= ROW && ny >=1 && ny <= COL){
                if(board[nx][ny] == '#' && (i != 0 || j != 0)){
                    count++;
                }
            }
        }
    }
    return count;
}

//0连续
void zero(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int row,int col){
    if(x < 1 || x > row || y < 1 || y > col || show[x][y] != '*'){ //实际边界
        return;
    }
    int count = getminecount(mine,x,y);
    show[x][y] = count + '0';
    if(count == 0){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;
                zero(mine,show,x+i,y+j,row,col);
            }
        }
    }
}

///胜利判断
int WinMine(char mine[ROWS][COLS],char show[ROWS][COLS],int win,int row,int col){
    //继承上次排查坐标
    int x = win/col;
    int y = win%col;
    if(x <= row){
        for(int i = x; i < row; i++){
            for(int j = y; j < col; j++){
                if(show[i+1][j+1] == '*'){ //问题
                    x = i;
                    y = j;
                    return x*row + y;
                }
                if(mine[i+1][j+1] == '#') continue;
            }
        }
    }
    return col*row;
}

//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col){
    int x = 0;
    int y = 0;
    int win = 0;
    
    while(1){
        printf("输入排查目标:>");
        scanf("%d%d",&x,&y);
        if(x >= 1 && x <= row && y >= 1 && y <= col){
            if(mine[x][y] == '#'){
                printf("扫雷失败\n");
                DisplayBoard(mine,ROW,COL);
                break;
            }
            else{ //不是雷
                //统计雷
                zero(mine,show,x,y,ROW,COL);
                DisplayBoard(show,ROW,COL);
            }
            //胜利条件
            win = WinMine(mine,show,win,ROW,COL);
            if(win == ROW*COL){
                printf("取得胜利\n");
                break;
            }
        }
        else printf("输入非法坐标，重新输入\n");

    }
    
}