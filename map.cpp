
#include "map.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void map_initiation(vector<vector<char> >& map, const short ScoreRow,
                    const short row, const short col, const short life,
                    const int score)
{
    short TitleCol= (col + START_COL) / 2 - 3, LifeRow= START_ROW + 3;
    for (short i= 1; i < row - 1; i++) {
        map[i][0]= map[i][col - 1]= '#';
        for (short j= 1; j < col - 1; j++) { map[i][j]= ' '; }
    }
    for (short j= 0; j < col; j++) { map[0][j]= map[row - 1][j]= '#'; }
    system("cls&mode con:cols=80 lines=30&color 20");
    goto_RowCol(0, TitleCol);
    cout << "Have a GOOD time!";
    goto_RowCol(1, TitleCol - 20);
    cout << "press  W¡ü S¡ý A¡û D¡ú to change direction ; press Spacebar to "
            "pause";
    goto_RowCol(LifeRow, 1);
    cout << "Life: " << life;
    goto_RowCol(ScoreRow, 0);
    cout << "Score: " << score;
    goto_RowCol(START_ROW, START_COL);
    for (short j= 0; j < col; j+= 2) { cout << map[0][j] << ' '; }
    for (short i= 1; i < row - 1; i++) {
        goto_RowCol(START_ROW + i, START_COL);
        for (short j= 0; j < col; j++) { cout << map[i][j]; }
    }
    goto_RowCol(START_ROW + row - 1, START_COL);
    for (short j= 0; j < col; j+= 2) { cout << map[row - 1][j] << ' '; }
    cout << endl;
}
