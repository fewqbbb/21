#include "Game.h"       // �]�tGame�����Y���
#include<iostream>      // �]�t��X��J�y�Y���
using namespace std;    // �ϥμзǩR�W�Ŷ�

// Game�����غc�l�A��l��Produce��HA
Game::Game(Produce A) {
    this->A = A;
}

// �C���D�`��
void Game::play() {
    char ch;
    // �C���}�l�e��
    while (!isGameOver()) {  //�p�G�C���٨S����
        A.print();  // ���L��e�ѽL���A
        char move;
        cin >> move;  // ����Τ��J
        if (move == 'w') {
            moveUp();    // �V�W����
        }
        else if (move == 'a') {
            moveLeft();  // �V������
        }
        else if (move == 's') {
            moveDown();  // �V�U����
        }
        else if (move == 'd') {
            moveRight(); // �V�k����
        }
        A.diamonds();  // �H���ͦ��s���
    }

    // �C�������e��
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
// �C���i��L�{
    

// �N����V������
void Game::Left() {
    for (int i = 0; i < 4; i++) {
        int k = 0;
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] != 0) {
                A.board[i][k++] = A.board[i][j]; // �D0����V����
            }
        }
        while (k < 4) {
            A.board[i][k++] = 0; // �Ѿl��m��0
        }
    }
}

// �N�۾F���ۦP����V���X��
void Game::togetherLeft() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) { // �`�N�G�o�̪�j���ӬO<3�Ӥ��O<4
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j + 1]) {
                A.board[i][j] *= 2; // ����X��
                A.board[i][j + 1] = 0;
            }
        }
    }
}

// �N����V�����ʨæX�֬۾F���ۦP���
void Game::moveLeft() {
    Left();
    togetherLeft();
    Left(); // �A�����ʥH��ɦX�᪺֫�Ů�
}

// �N����V�k����
void Game::Right() {
    for (int i = 0; i < 4; i++) {
        int k = 3;
        for (int j = 3; j >= 0; j--) {
            if (A.board[i][j] != 0) {
                A.board[i][k--] = A.board[i][j]; // �D0����V�k��
            }
        }
        while (k >= 0) {
            A.board[i][k--] = 0; // �Ѿl��m��0
        }
    }
}

// �N�۾F���ۦP����V�k�X��
void Game::togetherRight() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j - 1]) {
                A.board[i][j] *= 2; // ����X��
                A.board[i][j - 1] = 0;
            }
        }
    }
}

// �N����V�k���ʨæX�֬۾F���ۦP���
void Game::moveRight() {
    Right();
    togetherRight();
    Right(); // �A�����ʥH��ɦX�᪺֫�Ů�
}

// �N����V�W����
void Game::Up() {
    for (int j = 0; j < 4; j++) {
        int k = 0;
        for (int i = 0; i < 4; i++) {
            if (A.board[i][j] != 0) {
                A.board[k++][j] = A.board[i][j]; // �D0����V�W��
            }
        }
        while (k < 4) {
            A.board[k++][j] = 0; // �Ѿl��m��0
        }
    }
}

// �N�۾F���ۦP����V�W�X��
void Game::togetherUp() {
    for (int i = 0; i < 3; i++) { // �`�N�G�o�̪�i���ӬO<3�Ӥ��O<4
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i + 1][j]) {
                A.board[i][j] *= 2; // ����X��
                A.board[i + 1][j] = 0;
            }
        }
    }
}

// �N����V�W���ʨæX�֬۾F���ۦP���
void Game::moveUp() {
    Up();
    togetherUp();
    Up(); // �A�����ʥH��ɦX�᪺֫�Ů�
}

// �N����V�U����
void Game::Down() {
    for (int j = 0; j < 4; j++) {
        int k = 3;
        for (int i = 3; i >= 0; i--) {
            if (A.board[i][j] != 0) {
                A.board[k--][j] = A.board[i][j]; // �D0����V�U��
            }
        }
        while (k >= 0) {
            A.board[k--][j] = 0; // �Ѿl��m��0
        }
    }
}

// �N�۾F���ۦP����V�U�X��
void Game::togetherDown() {
    for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] != 0 && A.board[i][j] == A.board[i - 1][j]) {
                A.board[i][j] *= 2; // ����X��
                A.board[i - 1][j] = 0;
            }
        }
    }
}

// �N����V�U���ʨæX�֬۾F���ۦP���
void Game::moveDown() {
    Down();
    togetherDown();
    Down(); // �A�����ʥH��ɦX�᪺֫�Ů�
}

// �P�_�C���O�_����
bool Game::isGameOver() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A.board[i][j] == 0) {
                return false; // �٦��Ů�l�A�C��������
            }
            if (i > 0 && A.board[i][j] == A.board[i - 1][j]) {
                return false; // �٦��۾F�B�ۦP������A�C��������
            }
            if (j > 0 && A.board[i][j] == A.board[i][j - 1]) {
                return false; // �٦��۾F�B�ۦP������A�C��������
            }
        }
    }
    A.print(); // ���L�̲ת��ѽL���A
    return true; // �S���Ů�l�B�S���۾F�B�ۦP������A�C������
}
