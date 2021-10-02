
#include "snake.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void goto_RowCol(short row, short col)
{
    COORD position= {col, row};
    HANDLE hOutput= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, position);
}
vector<Point> snake_initiation(vector<vector<char> >& map, short row, short col,
                               int length)
{
    vector<Point> snake;
    Point tmp;
    tmp.row_i= row / 2;
    tmp.col_i= col / 2;
    snake.push_back(tmp);
    for (int len= 1; len < length; len++) {
        tmp.col_i+= 1;
        snake.push_back(tmp);
    }
    // 1
    map[snake[0].row_i][snake[0].col_i]= '@';
    for (int i= 1; i < snake.size(); i++) {
        tmp= snake[i];
        map[tmp.row_i][tmp.col_i]= '+';
    }
    // 2
    goto_RowCol(START_ROW + snake[0].row_i, START_COL + snake[0].col_i);
    cout << "@";
    for (int i= 1; i < snake.size(); i++) cout << "+";
    return snake;
}
