
#ifndef _SMOVE_H_
#define _SMOVE_H_ 1
#include "snake.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
//! 忘了&！！
bool smove(vector<vector<char> >& map, vector<Point>& snake,
           Direction direction, int& score, bool& FoodExist);
void goon(vector<vector<char> >& map, vector<Point>& snake, Point head);
void grow(vector<vector<char> >& map, vector<Point>& snake, int& score,
          Point head, bool& FoodExist);
inline bool ifgrow(const vector<vector<char> >& map, Point head);
bool ifdead(const vector<vector<char> >& map, Point head);
#endif
