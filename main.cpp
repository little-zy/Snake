
// todo ���򴰿ڱ��������󣬻������ֹ����λָ�
// todo �����ꡢ��������ʱ��ָ��
// todo ��ʱ��
//! ����Խ����
// todo ����
// todo �����ӵĵ�ͼ
// todo ��ʱʳ��
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
struct Scale
{
    short row;
    short col;
};        // todo
#include "food.h"
#include "map.h"
#include "smove.h"
#include "snake.h"
using namespace std;
int main()
{
    // initiation:   20 51 8 5
    short row= 20, col= 51;
    int length= 5, score= 5, speed= 3;
    vector<Point> snake;
    bool GAMEOVER= false;
    bool FoodExist= false;
    Direction direction= LEFT;
    system("title Game initiation &cls&mode con:cols=50 lines=15&color 1f");
    cout << "Please input the height and width of map:\n(20 and 51 is "
            "recommanded)"
         << endl;
    cin >> row >> col;
    cout << "Please input the initial length and speed of snake:\n(8 and 5 is "
            "recommanded)"
         << endl;
    cin >> length >> speed;
    score= length;
    short ScoreRow= START_ROW + row / 2;
    vector<vector<char> > map(row, vector<char>(col, ' '));
    short life= 3;
    while (life) {
        system("title Good Game��������Ϸ��������Ϸ����18�������û����ţ�");
        map_initiation(map, ScoreRow, row, col, life, score);
        snake= snake_initiation(map, row, col, length);
        // todo ����?����ѹ�磬�����������
        FoodExist= false;
        direction= LEFT;        //? ��Ȼ��һֱ��
        // todo toward
        while (! GAMEOVER) {
            int score1= score;
            if (! FoodExist) {
                try {
                    creatFood(map, snake, FoodExist);
                }        // todo �����߰�����û�еط�����ʳ��
                catch (char const* error) {
                    system("cls");
                    cout << error;
                }
                catch (...) {
                    ;
                }
            }
            while (kbhit()) {
                switch (getch()) {
                    case LEFT:
                    case 97:
                    case 65: direction= LEFT; break;
                    case RIGHT:
                    case 100:
                    case 68: direction= RIGHT; break;
                    case UP:
                    case 119:
                    case 87: direction= UP; break;
                    case DOWN:
                    case 115:
                    case 83: direction= DOWN; break;
                    case 32:
                        goto_RowCol(START_ROW + map.size(),
                                    START_COL + map[0].size() / 2 - 1);
                        system("color 6f&pause");
                        goto_RowCol(START_ROW + map.size(),
                                    START_COL + map[0].size() / 2 - 1);
                        cout << "                            ";
                        system("color 20");
                        break;
                    default: break;
                };
            }
            GAMEOVER= smove(map, snake, direction, score1, FoodExist);
            if (score1 != score) {
                score= score1;
                goto_RowCol(ScoreRow, 7);
                cout << score << "     ";
            }
            Sleep(1000 / speed);
        };
        system("cls");
        goto_RowCol(START_ROW + row / 2 - 6, START_COL + col / 2 - 6);
        cout << "your score is " << score << " in this turn." << endl << endl;
        GAMEOVER= false;
        life--;
        length= score;
        goto_RowCol(START_ROW + row / 2 - 4, START_COL + col / 2 - 6);
        system("pause");
    }        // todo echo GAMEOVER
    return 0;
}
