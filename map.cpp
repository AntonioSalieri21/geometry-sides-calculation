
#include "map.h"

void Map::printMap()
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