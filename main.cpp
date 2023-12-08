#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sidesCalculation.h"
#include "readDataFromFile.h"

using namespace std;

int main() 
{

    vector<string> data = readDataFromFile("HeightMap1.txt");
    cout << "HeightMap1.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    int res = countSides(data);
    cout << "Number of sides: " << res << endl;
    cout << endl;


    data = readDataFromFile("HeightMap2.txt");
    cout << "HeightMap2.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    res = countSides(data);
    cout << "Number of sides: " << res << endl;
    cout << endl;


    data = readDataFromFile("HeightMap3.txt");
    cout << "HeightMap3.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    res = countSides(data);
    cout << "Number of sides: " << res << endl;
    cout << endl;


    data = readDataFromFile("HeightMap4.txt");
    cout << "HeightMap4.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    res = countSides(data);
    cout << "Number of sides: " << res << endl;

    return 0;
}
