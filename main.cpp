#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> readDataFromFile(string file) 
{
    vector<string> res;
    ifstream inputFile(file);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            res.push_back(line);
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    return res;
}

int countSides2D(vector<string> data)
{
    int resHor = 2; //left and right sides always exist
    int resVer = 1; // bottom side always exists

    for(string line : data) 
    {
        for(int i = 0; i < line.length() - 1; i += 2) 
        {
            int currentColumn = line.at(i) - '0';
            int nextColumn = line.at(i+2) - '0';
            
            if(currentColumn != nextColumn) 
            {
                resHor++;
                continue;
            }
        }
        
        cout << "Horizontal sides: " << resHor << endl;

        for(int i = 0; i < line.length(); i += 2) 
        {
            int currentColumn = line.at(i) - '0';
            int prevColumn = -1;

            if(i - 2 >= 0) prevColumn = line.at(i-2) - '0';
            else 
            {
                resVer++;
                continue;
            }

            if(currentColumn == 0) continue;

            if(currentColumn != prevColumn) 
            {
                resVer++;
                continue;
            }
            

        }
        
        cout << "Vertical sides: " << resVer << endl;
    }

    return resHor + resVer;
}

int countSides3D(vector<string> data)
{
   int res = 0;

   return res;
}

int main() 
{

    vector<string> data = readDataFromFile("data.txt");

    int res = countSides2D(data);

    cout << "Number of sides: " << res << endl;

    /*vector<string> data = readDataFromFile("HeightMap1.txt");
    cout << "HeightMap1.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    int res = countSides3D(data);
    cout << "Number of sides: " << res << endl;
    cout << endl;


    data = readDataFromFile("HeightMap2.txt");
    cout << "HeightMap2.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    res = countSides3D(data);
    cout << "Number of sides: " << res << endl;
    cout << endl;


    data = readDataFromFile("HeightMap3.txt");
    cout << "HeightMap3.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    res = countSides3D(data);
    cout << "Number of sides: " << res << endl;
    cout << endl;


    data = readDataFromFile("HeightMap4.txt");
    cout << "HeightMap4.txt" << endl;
    for(string line : data) {
        cout << line << endl;
    }
    res = countSides3D(data);
    cout << "Number of sides: " << res << endl;*/

    return 0;
}
