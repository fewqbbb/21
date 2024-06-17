#ifndef GAME_H
#define GAME_H
#include<iostream>
#include"Produce.h"
using namespace std;

// 遊戲類的定義
class Game
{
private:
    void Left();   // 將方塊向左移動
    void togetherLeft();   // 將相鄰的相同方塊向左合併
    void moveLeft();    // 將方塊向左移動並合併相鄰的相同方塊
    void Right();  // 將方塊向右移動
    void togetherRight();  // 將相鄰的相同方塊向右合併
    void moveRight();   // 將方塊向右移動並合併相鄰的相同方塊
    void Up();     // 將方塊向上移動
    void togetherUp();     // 將相鄰的相同方塊向上合併
    void moveUp();      // 將方塊向上移動並合併相鄰的相同方塊
    void Down();   // 將方塊向下移動
    void togetherDown();   // 將相鄰的相同方塊向下合併
    void moveDown();    // 將方塊向下移動並合併相鄰的相同方塊

public:
    Produce A;          // 宣告一個Produce類型的成員變數A
    Game(Produce);      // 建構子，初始化遊戲狀態
    void play();        // 主遊戲循環函數
    bool isGameOver();  // 判斷遊戲是否結束
};
#endif
