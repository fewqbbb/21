#include "Game.h"

int main() {
    for (;;) {
        char ch;
        cout << "-----------------------------\n";
        for (int i = 0; i < 7; i++) {
            if (i == 3)
                cout << "|          遊戲開始         |\n";
            else if (i == 4)
                cout << "|       （PUSH SPCAE）      |\n";
            else
                cout << "|                           |\n";
        }
        cout << "-----------------------------\n";
        ch = getchar();
        if (ch == ' ')
            break;

    }
    srand(time(0));  // 確保隨機數生成器只初始化一次
    Produce p;     // 創建Produce對象，初始化棋盤
    Game play(p);  // 創建Game對象，開始遊戲
    play.play();   // 開始遊戲循環
}
