#include "map.h"
void Map::printMap()/*! Map print function*/
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

//* We count sides by analyzing each dimension of a figure separately*//
int Map::countSides()
{
    //*In each dimension we count sides by comparing each column with the next one*//
    int resX = _countSidesX(); //*From left to right*//
    int resY = _countSidesY(); //*From bottom to top*//
    int resZ = _countSidesZ(); //*From front to back*//
   return resX + resY + resZ;
}

int Map::_countSidesX() //*We go from left to right*//
{
    int resX = 2; //*left and right sides always exist*//

    for(int j = 0; j < y; j++) //*We go through each line*//
    {
         vector<int> line = data.at(j);
         for(int i = 0; i < x - 1; i++) 
         {
              
              int currentColumn = line.at(i); //*We compare current column with the next one, and if they are not simillar that means there is wall between them*//    
              int nextColumn = line.at(i+1);

              if(currentColumn != nextColumn)
              {
                resX++;
                continue;
              }
         }
         
    }

    return resX;
}
int Map::_countSidesY() //*We go from bottom to top*//
{
    int resY = 1; //*bottom side always exists*//

    for(int i = 0; i < y; i++)
    {
        vector<int> currentLine = data.at(i);
        for(int j = 0; j < x; j++)
        {
            int currentColumn = currentLine.at(j);
            if(currentColumn == 0) continue;

            int leftColumn = 0;
            int topColumn = 0;

            if(j - 1 >= 0) leftColumn = currentLine.at(j-1); //*We check if there is a column to the left of the current one*//
            if(i - 1 >= 0)
            {
                topColumn = data.at(i-1).at(j); //*We check if there is a column to the top of the current one*//
            }

            if(leftColumn != currentColumn && topColumn != currentColumn) //*If there is no column to the left or to the top of the current one, that means there is a NEW side*//
            {
                
                resY++;
                continue;
            }
        }
        
    }

    return resY;

}
int Map::_countSidesZ() //*We go from front to back*//
{

    int resZ = 2; //*front and back sides always exist*//
    for(int i = 0; i < y - 1; i++)
    {
        vector<int> currentLine = data.at(i);
        vector<int> nextLine = data.at(i+1);

        for(int j = 0; j < x; j++) //*Same proccess as in _countSidesX, but we go through Z axis, so map of values need to be read in columns*//
        {
            int currentColumn = currentLine.at(j);
            int nextColumn = nextLine.at(j);

            if(currentColumn != nextColumn)
            {
                resZ++;
                continue;
            }
        }
        
    }

    return resZ;

}