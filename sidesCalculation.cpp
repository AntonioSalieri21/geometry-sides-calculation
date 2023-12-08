#include "sidesCalculation.h"

int countSides(vector<string> data)
{
    int resX = _countSidesX(data); 
    int resY = _countSidesY(data); 
    int resZ = _countSidesZ(data); 
   return resX + resY + resZ;
}

int _countSidesX(vector<string> &data)
{
    int resX = 2; //left and right sides always exist
    for(string line : data)
    {
         for(int i = 0; i < line.length() - 2; i += 2)
         {
              
              int currentColumn = line.at(i) - '0';
              int nextColumn = line.at(i+2) - '0';

              if(currentColumn != nextColumn)
              {
                resX++;
                continue;
              }
         }
         
    }

    return resX;
}
int _countSidesY(vector<string> &data)
{
    int resY = 1; //bottom side always exists

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
                topColumn = data.at(i-1).at(j) - '0';
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
int _countSidesZ(vector<string> &data)
{
    int resZ = 2; //front and back sides always exist
    for(int i = 0; i < data.size() - 1; i++)
    {
        string currentLine = data.at(i);
        string nextLine = data.at(i+1);

        for(int j = 0; j < currentLine.length(); j += 2)
        {
            int currentColumn = currentLine.at(j) - '0';
            int nextColumn = nextLine.at(j) - '0';

            if(currentColumn != nextColumn)
            {
                resZ++;
                continue;
            }
        }
        
    }

    return resZ;

}