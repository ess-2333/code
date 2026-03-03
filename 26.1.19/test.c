#include "game.h"

void menu(){
    printf("*************************\n");
    printf("******1.play 0.exit******\n");
    printf("*************************\n");
}

void game(){
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
    
    //初始化
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');

    //设置雷
    SetMine(mine,ROW,COL);

    //打印棋盘
    DisplayBoard(show,ROW,COL);
    //DisplayBoard(mine,ROW,COL);

    //排雷
    FindMine(mine,show,ROW,COL);
}

int main(){
    srand((unsigned int)time(NULL)); //srand根据时间戳设置随机种子
    int input = 0;
    do{
        menu();
        printf("请选择:>");
        while (scanf("%d", &input) != 1) {
            while (getchar() != '\n'); // 清空输入缓冲区的非数字字符
            printf("输入无效,请输入数字0或1:>");
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