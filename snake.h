
#ifndef _SNAKE_H_
#define _SNAKE_H_ 1
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
#define START_ROW 5
#define START_COL 18
#define random(x) (rand() % x)
using namespace std;
struct Point
{
    short row_i;
    short col_i;
};
void goto_RowCol(short row, short col);
enum Direction { LEFT= 75, RIGHT= 77, UP= 72, DOWN= 80 };
vector<Point> snake_initiation(vector<vector<char> >& map, short row, short col,
                               int length);
#endif
