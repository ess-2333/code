#include "game.h"

void menu(){
    printf("*************************\n");
    printf("******1.play 0.exit******\n");
    printf("*************************\n");
}

void game(){
    char ret = 0;
    char board[ROW][COL] = {0};
    //初始化board函数
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    //下棋
    while(1){
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if(ret != 'C'){
            break;
        }

        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if(ret != 'C'){
            break;
        }
    }

    if (ret == '*') printf("***\n玩家赢\n***\n");
    else if (ret == '#') printf("###\n电脑赢\n###\n");
    else if (ret == 'T') printf("\n平局\n");
}

int main(){
    srand((unsigned int)time(NULL)); //srand根据时间戳设置随机种子
    int input = 0;
    do{
        menu();
        printf("请选择:>");
        while (scanf("%d", &input) != 1) {
            while (getchar() != '\n'); // 清空输入缓冲区的非数字字符
            printf("输入无效，请输入数字0或1:>");
        }
        switch(input){
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("error\n");
                break;
        }
    } while(input);

}