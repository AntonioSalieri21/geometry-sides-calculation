#ifndef readDataFromFile_h
#define readDataFromFile_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "map.h"
#include <sstream>
using namespace std;

vector<string> split(string line);
Map readDataFromFile(string file);

#endif