#ifndef sidesCalculation_h
#define sidesCalculation_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "map.h"

using namespace std;

int countSides(Map &map);
int _countSidesX(Map &map);
int _countSidesY(Map &map);
int _countSidesZ(Map &map);

#endif