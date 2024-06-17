#include "Game.h"       // 包含Game類的頭文件
#include<iostream>      // 包含輸出輸入流頭文件
using namespace std;    // 使用標準命名空間

// Game類的建構子，初始化Produce對象A
Game::Game(Produce A) {
    this->A = A;
}

// 遊戲主循環
void Game::play() {
    char ch;
    // 遊戲開始畫面
    while (!isGameOver()) {  //如果遊戲還沒結束
        A.print();  // 打印當前棋盤狀態
        char move;
        cin >> move;  // 獲取用戶輸入
        if (move == 'w') {
            moveUp();    // 向上移動
        }
        else if (move == 'a') {
            moveLeft();  // 向左移動
        }
        else if (move == 's') {
            moveDown();  // 向下移動
        }
        else if (move == 'd') {
            moveRight(); // 向右移動
        }
        A.diamonds();  // 隨機生成新方塊
    }

    // 遊戲結束畫面
    if (isGameOver() == true) {
        cout << "-----------------------------\n";
        for (int i = 0; i < 7; i++) {
            if (i == 3)
                cout << "|         Game over         |\n";
            else
                cout << "|                           |\n";
        }
        cout << "-----------------------------\n";
    }
}
// 遊戲進行過程
    

// 將方塊向左移動
void Game::Left() {
    for (int i = 0; i < 4; i++) {
        int k = 0;
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] != 0) {
                A.board[i][k++] = A.board[i][j]; // 非0方塊向左移
            }
        }
        while (k < 4) {
            A.board[i][k++] = 0; // 剩餘位置補0
        }
    }
}

// 將相鄰的相同方塊向左合併
void Game::togetherLeft() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) { // 注意：這裡的j應該是<3而不是<4
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j + 1]) {
                A.board[i][j] *= 2; // 方塊合併
                A.board[i][j + 1] = 0;
            }
        }
    }
}

// 將方塊向左移動並合併相鄰的相同方塊
void Game::moveLeft() {
    Left();
    togetherLeft();
    Left(); // 再次移動以填補合併後的空格
}

// 將方塊向右移動
void Game::Right() {
    for (int i = 0; i < 4; i++) {
        int k = 3;
        for (int j = 3; j >= 0; j--) {
            if (A.board[i][j] != 0) {
                A.board[i][k--] = A.board[i][j]; // 非0方塊向右移
            }
        }
        while (k >= 0) {
            A.board[i][k--] = 0; // 剩餘位置補0
        }
    }
}

// 將相鄰的相同方塊向右合併
void Game::togetherRight() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j - 1]) {
                A.board[i][j] *= 2; // 方塊合併
                A.board[i][j - 1] = 0;
            }
        }
    }
}

// 將方塊向右移動並合併相鄰的相同方塊
void Game::moveRight() {
    Right();
    togetherRight();
    Right(); // 再次移動以填補合併後的空格
}

// 將方塊向上移動
void Game::Up() {
    for (int j = 0; j < 4; j++) {
        int k = 0;
        for (int i = 0; i < 4; i++) {
            if (A.board[i][j] != 0) {
                A.board[k++][j] = A.board[i][j]; // 非0方塊向上移
            }
        }
        while (k < 4) {
            A.board[k++][j] = 0; // 剩餘位置補0
        }
    }
}

// 將相鄰的相同方塊向上合併
void Game::togetherUp() {
    for (int i = 0; i < 3; i++) { // 注意：這裡的i應該是<3而不是<4
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i + 1][j]) {
                A.board[i][j] *= 2; // 方塊合併
                A.board[i + 1][j] = 0;
            }
        }
    }
}

// 將方塊向上移動並合併相鄰的相同方塊
void Game::moveUp() {
    Up();
    togetherUp();
    Up(); // 再次移動以填補合併後的空格
}

// 將方塊向下移動
void Game::Down() {
    for (int j = 0; j < 4; j++) {
        int k = 3;
        for (int i = 3; i >= 0; i--) {
            if (A.board[i][j] != 0) {
                A.board[k--][j] = A.board[i][j]; // 非0方塊向下移
            }
        }
        while (k >= 0) {
            A.board[k--][j] = 0; // 剩餘位置補0
        }
    }
}

// 將相鄰的相同方塊向下合併
void Game::togetherDown() {
    for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i - 1][j]) {
                A.board[i][j] *= 2; // 方塊合併
                A.board[i - 1][j] = 0;
            }
        }
    }
}

// 將方塊向下移動並合併相鄰的相同方塊
void Game::moveDown() {
    Down();
    togetherDown();
    Down(); // 再次移動以填補合併後的空格
}

// 判斷遊戲是否結束
bool Game::isGameOver() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] == 0) {
                return false; // 還有空格子，遊戲未結束
            }
            if (i > 0 && A.board[i][j] == A.board[i - 1][j]) {
                return false; // 還有相鄰且相同的方塊，遊戲未結束
            }
            if (j > 0 && A.board[i][j] == A.board[i][j - 1]) {
                return false; // 還有相鄰且相同的方塊，遊戲未結束
            }
        }
    }
    A.print(); // 打印最終的棋盤狀態
    return true; // 沒有空格子且沒有相鄰且相同的方塊，遊戲結束
}
