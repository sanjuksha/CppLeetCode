
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:


    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = (matrix.size() - 1);
        while (left < right) {
            for (int i = 0; i <= right; i++) {
                int top = left;
                int bottom = right;
                int topLeft = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = topLeft;
            }
            left += 1;
            right -= 1;
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
    matrix = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
    Solution solution;
    solution.printMatrix(matrix);
    std::cout<<"================="<<std::endl;
    solution.rotate(matrix);
    solution.printMatrix(matrix);
}