#include "readDataFromFile.h"

vector<string> split(string line)
{
    vector<string> result;
    stringstream ss(line);
    string word;
    while (getline(ss, word, ' ')) {
        result.push_back(word);
    }
    return result;
}

Map readDataFromFile(string file)
{
    Map res;
    ifstream inputFile(file);
    if (inputFile.is_open()) {
        string line;
        int i = 0;
        while (getline(inputFile, line)) {
            if(i == 0) 
            {
                vector<string> splitted = split(line);
                res.y = stoi(splitted.at(0));
                res.x = stoi(splitted.at(1));
                i++;
                continue;
            }
            vector<string> splitted = split(line);
            vector<int> line;
            for(string s : splitted)
            {
                line.push_back(stoi(s));
            }
            res.data.push_back(line);
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    return res;
}