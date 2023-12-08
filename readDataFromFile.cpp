#include "readDataFromFile.h"

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