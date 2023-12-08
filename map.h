#ifndef map_h
#define map_h

#include <vector>
#include <string>

using namespace std;

class Map
{
    public:
    int x;
    int y;

    vector<vector<int>> data;

    void printMap()
    {
        cout << "X: " << x << "   " << "Y: " << y << endl;
        for(vector<int> line : data)
        {
            for(int column : line)
            {
                cout << column << " ";
            }
            cout << endl;
        }
    }
};

#endif