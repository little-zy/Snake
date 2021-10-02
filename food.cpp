
#include "food.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void creatFood(vector<vector<char> >& map, const vector<Point>& snake,
               bool& FoodExist)
{
    if (snake.size() >= (map.size() - 1) * (map[0].size() - 1))
        throw "overflow";
    FoodExist= true;
    Point food;
    food.row_i= random((map.size() - 2)) + 1;        //? 2个括号！
    food.col_i= random((map[0].size() - 2)) + 1;
    for (Point tmp : snake) {
        if (food.col_i == tmp.col_i && food.row_i == tmp.row_i) {
            FoodExist= false;
        }
    }
    if (! FoodExist) creatFood(map, snake, FoodExist);
    map[food.row_i][food.col_i]= '*';
    goto_RowCol(START_ROW + food.row_i, START_COL + food.col_i);
    cout << '*';
}
