#include "Produce.h"     // 包含Produce類的頭文件
#include <cstdlib>       // 包含標準庫以使用rand()和srand()
#include <ctime>         // 包含ctime以使用time()函數
#include <iostream>
#include <iomanip>
using namespace std;

// Produce類的建構子，初始化棋盤並隨機生成兩個初始方塊
Produce::Produce() {
    srand(time(0));      // 使用當前時間設置隨機數生成器的種子
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0; // 初始化棋盤所有位置為0
        }
        diamonds(); // 生成初始方塊
    }
    int p1 = (rand() % 16); // 隨機生成第一個方塊的位置
    int p2 = p1;       // 初始化第二個方塊的位置為第一個位置
    if (p1 == p2) {    // 確保第二個方塊的位置不同於第一個方塊的位置
      p2 = (rand() % 16);
    }
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (count == p1 || count == p2) {
                board[i][j] = 2; // 將兩個位置設置為2
            }
            count++;
        }
    }
}

// 隨機生成新方塊
void Produce::diamonds() {
    srand(time(0)); // 使用當前時間設置隨機數生成器的種子
    int emptySpaces[16];
    int entry = 0;
    // 計算空格數量並記錄空格位置
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptySpaces[entry++] = 4 * i + j;
            }
        }
    }
    if (entry == 0) 
        return; // 如果沒有空格，直接返回
    int amount = (entry == 1) ? 1 : (rand() % 2 + 1); // 如果只有一個空格，生成一個新方塊，否則隨機生成1或2個
    // 隨機選擇空格位置
    int place1 = emptySpaces[rand() % entry];
    int place2 = (amount == 1) ? -1 : emptySpaces[rand() % entry];
    while (amount == 2 && place1 == place2) {
        place2 = emptySpaces[rand() % entry];
    }
    // 在選擇的位置生成2或4
    board[place1 / 4][place1 % 4] = (rand() % 2 + 1) * 2;
    if (amount == 2) {
        board[place2 / 4][place2 % 4] = (rand() % 2 + 1) * 2;
    }
}


// 打印棋盤
void Produce::print() {
    cout << "\nNEXT\n";
    cout << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "| " << setw(4) << board[i][j] << " "; // 打印棋盤每個位置的值
        }
        cout << "|\n";
        cout << "\n";
    }
}
