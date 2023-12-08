#ifndef map_h
#define map_h

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Map
{
    public:
    int x;
    int y;

    vector<vector<int>> data;

    void printMap();
};

#endif