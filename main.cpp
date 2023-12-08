#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "readDataFromFile.h"

using namespace std;

int main() 
{

    Map map = readDataFromFile("HeightMap1.txt");
    cout << "HeightMap1.txt" << endl;
    map.printMap();

    int res = map.countSides();
    cout << "Number of sides: " << res << endl;
    cout << endl;


    map = readDataFromFile("HeightMap2.txt");
    cout << "HeightMap2.txt" << endl;
    map.printMap();

    res = map.countSides();
    cout << "Number of sides: " << res << endl;
    cout << endl;


    map = readDataFromFile("HeightMap3.txt");
    cout << "HeightMap3.txt" << endl;
    map.printMap();

    res = map.countSides();
    cout << "Number of sides: " << res << endl;
    cout << endl;


    map = readDataFromFile("HeightMap4.txt");
    cout << "HeightMap4.txt" << endl;
    map.printMap();

    res = map.countSides();
    cout << "Number of sides: " << res << endl;
    cout << endl;
    return 0;
}
