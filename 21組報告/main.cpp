#include "Game.h"

int main() {
    for (;;) {
        char ch;
        cout << "-----------------------------\n";
        for (int i = 0; i < 7; i++) {
            if (i == 3)
                cout << "|          �C���}�l         |\n";
            else if (i == 4)
                cout << "|       �]PUSH SPCAE�^      |\n";
            else
                cout << "|                           |\n";
        }
        cout << "-----------------------------\n";
        ch = getchar();
        if (ch == ' ')
            break;

    }
    srand(time(0));  // �T�O�H���ƥͦ����u��l�Ƥ@��
    Produce p;     // �Ы�Produce��H�A��l�ƴѽL
    Game play(p);  // �Ы�Game��H�A�}�l�C��
    play.play();   // �}�l�C���`��
}
