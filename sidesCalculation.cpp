#include "sidesCalculation.h"
#include "readDataFromFile.h"
int countSides(Map &map)
{
    int resX = _countSidesX(map); 
    int resY = _countSidesY(map); 
    int resZ = _countSidesZ(map); 
   return resX + resY + resZ;
}

int _countSidesX(Map &map)
{
    int resX = 2; //left and right sides always exist

    for(int y = 0; y < map.y; y++)
    {
         vector<int> line = map.data.at(y);
         for(int i = 0; i < map.x - 1; i++)
         {
              
              int currentColumn = line.at(i);
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
int _countSidesY(Map &map)
{
    int resY = 1; //bottom side always exists

    for(int i = 0; i < map.y; i++)
    {
        vector<int> currentLine = map.data.at(i);
        for(int j = 0; j < map.x; j++)
        {
            int currentColumn = currentLine.at(j);
            if(currentColumn == 0) continue;

            int leftColumn = 0;
            int topColumn = 0;

            if(j - 1 >= 0) leftColumn = currentLine.at(j-1);
            if(i - 1 >= 0) 
            {
                topColumn = map.data.at(i-1).at(j);
            }

            if(leftColumn != currentColumn && topColumn != currentColumn)
            {
                
                resY++;
                continue;
            }
        }
        
    }

    return resY;

}
int _countSidesZ(Map &map)
{

    int resZ = 2; //front and back sides always exist
    for(int i = 0; i < map.y - 1; i++)
    {
        vector<int> currentLine = map.data.at(i);
        vector<int> nextLine = map.data.at(i+1);

        for(int j = 0; j < map.x; j++)
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