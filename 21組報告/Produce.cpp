#include "Produce.h"     // �]�tProduce�����Y���
#include <cstdlib>       // �]�t�зǮw�H�ϥ�rand()�Msrand()
#include <ctime>         // �]�tctime�H�ϥ�time()���
#include <iostream>
#include <iomanip>
using namespace std;

// Produce�����غc�l�A��l�ƴѽL���H���ͦ���Ӫ�l���
Produce::Produce() {
    srand(time(0));      // �ϥη�e�ɶ��]�m�H���ƥͦ������ؤl
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0; // ��l�ƴѽL�Ҧ���m��0
        }
        diamonds(); // �ͦ���l���
    }
    int p1 = (rand() % 16); // �H���ͦ��Ĥ@�Ӥ������m
    int p2 = p1;       // ��l�ƲĤG�Ӥ������m���Ĥ@�Ӧ�m
    if (p1 == p2) {    // �T�O�ĤG�Ӥ������m���P��Ĥ@�Ӥ������m
      p2 = (rand() % 16);
    }
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (count == p1 || count == p2) {
                board[i][j] = 2; // �N��Ӧ�m�]�m��2
            }
            count++;
        }
    }
}

// �H���ͦ��s���
void Produce::diamonds() {
    srand(time(0)); // �ϥη�e�ɶ��]�m�H���ƥͦ������ؤl
    int emptySpaces[16];
    int entry = 0;
    // �p��Ů�ƶq�ðO���Ů��m
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptySpaces[entry++] = 4 * i + j;
            }
        }
    }
    if (entry == 0) 
        return; // �p�G�S���Ů�A������^
    int amount = (entry == 1) ? 1 : (rand() % 2 + 1); // �p�G�u���@�ӪŮ�A�ͦ��@�ӷs����A�_�h�H���ͦ�1��2��
    // �H����ܪŮ��m
    int place1 = emptySpaces[rand() % entry];
    int place2 = (amount == 1) ? -1 : emptySpaces[rand() % entry];
    while (amount == 2 && place1 == place2) {
        place2 = emptySpaces[rand() % entry];
    }
    // �b��ܪ���m�ͦ�2��4
    board[place1 / 4][place1 % 4] = (rand() % 2 + 1) * 2;
    if (amount == 2) {
        board[place2 / 4][place2 % 4] = (rand() % 2 + 1) * 2;
    }
}


// ���L�ѽL
void Produce::print() {
    cout << "\nNEXT\n";
    cout << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "| " << setw(4) << board[i][j] << " "; // ���L�ѽL�C�Ӧ�m����
        }
        cout << "|\n";
        cout << "\n";
    }
}
