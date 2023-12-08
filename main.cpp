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
    int res = 4;
    for(string line : data) 
    {
        
        for(int i = 0; i < line.length() - 1; i += 2) 
        {

            int currentColumn = line.at(i) - '0';
            int nextColumn = line.at(i+2) - '0';
            
            if(currentColumn == 0 || nextColumn == 0) 
            {
                res += 1;
                cout << currentColumn << " " << nextColumn << "   " << res << endl;
                continue;
            }

            if(currentColumn != nextColumn) 
            {
                res += 2;
                cout << currentColumn << " " << nextColumn << "   " << res << endl;
                continue;
            }
            cout << currentColumn << " " << nextColumn << "   " << res << endl;


            
           
        }
    }
    return res;
}

int countSides3D(vector<string> data)
{
    int res = 6;
    for(int y = 0; y < data.size(); y++) 
    {
        string line = data.at(y);

        for(int x = 0; x < line.length(); x += 2)
        {
            int currentColumn = line.at(x) - '0';
            /*int rightColumn = -1;
            int leftColumn = -1;
            int upColumn = -1;
            int downColumn = -1;*/

            vector<int> neighbours(4,-1); //clokwise - 0 - top, 1 - right, 2 - bottom, 3 - left

            if(x + 2 < line.length()) neighbours.at(1) = line.at(x + 2) - '0';
            if(x - 2 >= 0) neighbours.at(3) = line.at(x - 2) - '0';
            if(y+1 < data.size()) 
            {
                string tmpLine = data.at(y+1);
                if(x < tmpLine.length()) neighbours.at(2) = tmpLine.at(x) - '0';
            } 
            if(y-1 >= 0) 
            {
                string tmpLine = data.at(y-1);
                if(x < tmpLine.length()) neighbours.at(0) = tmpLine.at(x) - '0';
            } 
            //cout << currentColumn << endl;
            for(int neighbour : neighbours) 
            {
                //cout << neighbour << " ";
                if(neighbour == -1) continue;
                if(currentColumn == 0 || neighbour == 0) 
                {
                    res += 1;
                    
                    continue;
                }

                if(currentColumn != neighbour) 
                {
                    res += 2;
                    continue;
                }
            }
            //cout << endl;
        }

    }
    return res;
}

int main() 
{

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
