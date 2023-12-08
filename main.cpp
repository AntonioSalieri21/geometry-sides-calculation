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
        int i = 0;
        while (getline(inputFile, line)) {
            if(i == 0) {
                i++;
                continue;
            }
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
    int resX = 2; //left and right sides always exist
    int resY = 1; //bottom side always exists
    int resZ = 2; //front and back sides always exist

   //calculating left to right sides
   for(string line : data)
   {
         for(int i = 0; i < line.length() - 1; i += 2)
         {
              
              int currentColumn = line.at(i) - '0';
              if(i + 2 >= line.length()) break; //if we are at the last column, we don't need to check the next one (it doesn't exist)
              int nextColumn = line.at(i+2) - '0';

              if(currentColumn != nextColumn)
              {
                resX++;
                continue;
              }
         }
         
   }
    cout << "Left to right sides: " << resX << endl;

    //calculating front to back sides
    for(int i = 0; i < data.size() - 1; i++)
    {
        string currentLine = data.at(i);
        string nextLine = data.at(i+1);

        for(int j = 0; j < currentLine.length(); j += 2)
        {
            int currentColumn = currentLine.at(j) - '0';
            if(j >= nextLine.length())
            {
                resZ++;
                continue;
            }

            int nextColumn = nextLine.at(j) - '0';

            if(currentColumn != nextColumn)
            {
                resZ++;
                continue;
            }
        }
        
    }
    cout << "Front to back sides: " << resZ << endl;

    //calculating bottom to top sides
    for(int i = 0; i < data.size(); i++)
    {
        string currentLine = data.at(i);
        for(int j = 0; j < currentLine.length(); j += 2)
        {
            int currentColumn = currentLine.at(j) - '0';
            if(currentColumn == 0) continue;

            int leftColumn = 0;
            int topColumn = 0;

            if(j - 2 >= 0) leftColumn = currentLine.at(j-2) - '0';
            if(i - 1 >= 0) 
            {
                if(j < data.at(i-1).length()) topColumn = data.at(i-1).at(j) - '0';
            }

            if(leftColumn != currentColumn && topColumn != currentColumn)
            {
                cout << "leftColumn: " << leftColumn << " " << "topColumn: " << topColumn << " " << "currentColumn: " << currentColumn << endl;
                resY++;
                continue;
            }
        }
        
    }
    cout << "Bottom to top sides: " << resY << endl;
    

   return resX + resY + resZ;
}

int main() 
{

    /*vector<string> data = readDataFromFile("data.txt");

    int res = countSides2D(data);

    cout << "Number of sides: " << res << endl;*/

    /*vector<string> data = readDataFromFile("HeightMap2.txt");

    int res = countSides3D(data);

    cout << "Number of sides: " << res << endl;*/

    vector<string> data = readDataFromFile("HeightMap1.txt");
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
    cout << "Number of sides: " << res << endl;

    return 0;
}
