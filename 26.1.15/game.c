#include "game.h"

void InitBoard(char board[ROW][COL],int row, int col){ 
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            board[i][j] = ' ';
        }
    }
}

// void DisplayBoard(char board[ROW][COL],int row, int col){
//     for(int i = 0; i < row; i++){
//         printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//         if(i != row - 1){ //最后一行不打印
//             printf("---|---|---\n");
//         }
//     }
// }
void DisplayBoard(char board[ROW][COL],int row, int col){
    for(int i = 0; i < row; i++){
        //打印竖分割
        for(int j = 0; j < col; j++){
            printf(" %c ",board[i][j]);
            if(j < col - 1) printf("|");
        }
        printf("\n");
        //打印行分割
        if(i < row - 1){
            for(int j = 0; j < col; j++){
                printf("---");
                if(j < col - 1) printf("|");
            }
            printf("\n");
        }
    }
}

//玩家下棋
void PlayerMove(char board[ROW][COL],int row, int col){
    int x = 0;
    int y = 0;
    printf("玩家下棋:>\n");

    while(1){
        printf("输入坐标:>");
        scanf("%d%d",&x,&y);
        if(x >= 1 && x <= row && y >= 1 && y <= col){ //坐标合法判断
            if(board[x-1][y-1] == ' '){
                board[x-1][y-1] = '*';
                break; 
            }
            else printf("坐标被占用，输入错误\n");
        }
        else printf("坐标越界\n");
    }
}

//电脑下棋
void ComputerMove(char board[ROW][COL],int row, int col){
    
    printf("电脑下棋:>\n");

    int x = 0;
    int y = 0;
    while(1){
        x = rand() % row; //在main函数中需要设置srand，否则rand数值相同
        y = rand() % col;
        if(board[x][y] == ' '){
            board[x][y] = '#';
            break;
        }
    }
}

//判断输赢
char IsWin(char board[ROW][COL],int row, int col){
    for(int i = 0; i < row; i++){
        if(board[i][0] == board[i][1]&& board[i][1] == board[i][2] && board[i][0] != ' '){
            return board[i][1]; //行相等
        }
        if(board[0][i] == board[1][i]&& board[1][i] == board[2][i] && board[0][i] != ' '){
            return board[0][i]; //列相等
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' '){
        return board[1][1]; //左斜线相等
    }
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' '){
        return board[1][1]; //右斜线相等
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] == ' ') return 'C'; //存在空白继续
        }
    }
    return 'T';
}