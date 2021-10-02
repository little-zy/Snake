
#include "smove.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
bool ifdead(const vector<vector<char> >& map, Point head)
{
    bool GAMEOVER= false;
    short ErrorRow= START_ROW + 4;
    if (map[head.row_i][head.col_i] == '+') {
        goto_RowCol(ErrorRow, 2);
        cout << "Eat self!";
        goto_RowCol(START_ROW + map.size(), START_COL + map[0].size() / 2 - 1);
        system("color 40&pause");
        GAMEOVER= true;
    }
    if (map[head.row_i][head.col_i] == '#') {
        goto_RowCol(ErrorRow, 2);
        cout << "wall!";
        goto_RowCol(START_ROW + map.size(), START_COL + map[0].size() / 2 - 1);
        system("color 40&pause");
        GAMEOVER= true;
    }
    return GAMEOVER;
}
inline bool ifgrow(const vector<vector<char> >& map, Point head)
{
    if (map[head.row_i][head.col_i] == '*')
        return true;
    else
        return false;
}
void grow(vector<vector<char> >& map, vector<Point>& snake, int& score,
          Point head, bool& FoodExist)
{
    snake.insert(snake.begin(), head);
    goto_RowCol(START_ROW + head.row_i, START_COL + head.col_i);
    cout << '@';
    map[snake[1].row_i][snake[1].col_i]= '+';
    goto_RowCol(START_ROW + snake[1].row_i, START_COL + snake[1].col_i);
    cout << '+';
    score++;
    FoodExist= false;
}
void goon(vector<vector<char> >& map, vector<Point>& snake, Point head)
{
    {
        snake.insert(snake.begin(), head);
        goto_RowCol(START_ROW + head.row_i, START_COL + head.col_i);
        cout << '@';
    }
    {
        map[snake[1].row_i][snake[1].col_i]= '+';
        goto_RowCol(START_ROW + snake[1].row_i, START_COL + snake[1].col_i);
        cout << '+';
    }
    {
        map[snake[snake.size() - 1].row_i][snake[snake.size() - 1].col_i]= ' ';
        goto_RowCol(START_ROW + snake[snake.size() - 1].row_i,
                    START_COL + snake[snake.size() - 1].col_i);
        cout << ' ';
        snake.erase(snake.end() - 1);
    }
}
bool smove(vector<vector<char> >& map, vector<Point>& snake,
           Direction direction, int& score, bool& FoodExist)
{
    Point head= snake[0];
    switch (direction) {
        case LEFT:
            head.col_i-= 1;
            if (head.col_i >= 0) {
                if (ifdead(map, head)) {
                    // goto_RowCol(ErrorRow, 2);
                    // cout << "Can not back";
                    return true;
                } else if (ifgrow(map, head)) {
                    grow(map, snake, score, head, FoodExist);
                } else {
                    goon(map, snake, head);
                }
            } else {
                short ErrorRow= START_ROW + 4;
                goto_RowCol(ErrorRow, 2);
                cout << "wall!";
                goto_RowCol(START_ROW + map.size(),
                            START_COL + map[0].size() / 2 - 1);
                system("color 40&pause");
                return true;
            }
            break;
        case RIGHT:
            head.col_i+= 1;
            if (head.col_i < map[0].size()) {
                if (ifdead(map, head)) {
                    return true;
                } else if (ifgrow(map, head)) {
                    grow(map, snake, score, head, FoodExist);
                } else {
                    goon(map, snake, head);
                }
            } else {
                short ErrorRow= START_ROW + 4;
                goto_RowCol(ErrorRow, 2);
                cout << "wall!";
                goto_RowCol(START_ROW + map.size(),
                            START_COL + map[0].size() / 2 - 1);
                system("color 40&pause");
                return true;
            }
            break;
        case UP:
            head.row_i-= 1;
            if (ifdead(map, head)) {
                return true;
            } else if (ifgrow(map, head)) {
                grow(map, snake, score, head, FoodExist);
            } else {
                goon(map, snake, head);
            }
            break;
        case DOWN:
            head.row_i+= 1;
            if (ifdead(map, head)) {
                return true;
            } else if (ifgrow(map, head)) {
                grow(map, snake, score, head, FoodExist);
            } else {
                goon(map, snake, head);
            }
            break;
        default: break;
    };
    return false;
}