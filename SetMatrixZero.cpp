#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    void setRCZero(int row, int col,vector<vector<int>>& matrix)
    {
        int m = matrix[0].size();
        int n = matrix.size();


        for(int j = 0; j < n; j++)
        {
            matrix[row][j] = 0;
        }

        for (int i = 0; i < m; i++)
        {

            matrix[i][col] = 0;

        }
    }
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix[0].size();
        int n = matrix.size();

        vector<std::pair<int,int>> indexes;

        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    std::pair<int,int> p;
                    p.first = i;
                    p.second = j;
                    indexes.push_back(p);
                }
            }
        }
        for(int i = 0; i < indexes.size(); i++)
        {
            setRCZero(indexes[i].first, indexes[i].second, matrix);
        }

    }

    void printMatrix(vector<vector<int>>& matrix)
    {
        for(int i = 0; i< matrix[0].size(); i++)
        {
            for(int j = 0; j< matrix.size(); j++)
            {
                std::cout<<matrix[j][i]<<" ";
            }
            std::cout<<std::endl;
        }
    }
};
int main()
{
    vector<vector<int>> matrix;
    matrix = {{0,1,2,0}, {3,4,5,2}, {13,3,6,7}, {15,14,12,16}};
    Solution solution;
    solution.printMatrix(matrix);
    solution.setZeroes(matrix);
    std::cout<<"================"<<std::endl;
    solution.printMatrix(matrix);
    //TODO: print vector and push on git and write in python

}