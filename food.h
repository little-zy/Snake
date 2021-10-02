
#ifndef _FOOD_H_
#define _FOOD_H_ 1
#include "snake.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void creatFood(vector<vector<char> >& map, const vector<Point>& snake,
               bool& FoodExist);
#endif
