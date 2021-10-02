
#ifndef _MAP_H_
#define _MAP_H_ 1
#include "snake.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void map_initiation(vector<vector<char> >& map, const short ScoreRow,
                    const short row, const short col, const short life,
                    const int score);
#endif
