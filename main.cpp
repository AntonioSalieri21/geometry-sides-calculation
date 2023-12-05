#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> readDataFromFile() 
{
    vector<string> res;
    ifstream inputFile("data.txt");
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

int main() {
    vector<string> data = readDataFromFile();

    for(string line : data) {
        cout << line << endl;
    }
    int res = countSides2D(data);
    cout << "Number of sides: " << res << endl;
    return 0;
}
