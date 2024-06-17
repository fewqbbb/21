#ifndef R_H
#define R_H

class Produce{
public:
    int board[4][4];          // 4x4棋盤矩陣
    Produce();                // 建構子，初始化遊戲面板
    void diamonds(); // 隨機生成新方塊
    void print();             // 打印當前棋盤狀態
};

#endif
