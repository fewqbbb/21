#ifndef GAME_H
#define GAME_H
#include<iostream>
#include"Produce.h"
using namespace std;

// �C�������w�q
class Game
{
private:
    void Left();   // �N����V������
    void togetherLeft();   // �N�۾F���ۦP����V���X��
    void moveLeft();    // �N����V�����ʨæX�֬۾F���ۦP���
    void Right();  // �N����V�k����
    void togetherRight();  // �N�۾F���ۦP����V�k�X��
    void moveRight();   // �N����V�k���ʨæX�֬۾F���ۦP���
    void Up();     // �N����V�W����
    void togetherUp();     // �N�۾F���ۦP����V�W�X��
    void moveUp();      // �N����V�W���ʨæX�֬۾F���ۦP���
    void Down();   // �N����V�U����
    void togetherDown();   // �N�۾F���ۦP����V�U�X��
    void moveDown();    // �N����V�U���ʨæX�֬۾F���ۦP���

public:
    Produce A;          // �ŧi�@��Produce�����������ܼ�A
    Game(Produce);      // �غc�l�A��l�ƹC�����A
    void play();        // �D�C���`�����
    bool isGameOver();  // �P�_�C���O�_����
};
#endif
