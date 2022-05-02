
#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    Solution(std::vector<std::vector<double>>& matrix)
    {
        m_matrix = matrix;
    }

    double sumOfMatrix(int i, int j)
    {
        double sum;
        sum = 0;
        for(int r = 0 ; r < i; r++)
        {
            for(int c = 0; c < j; c++)
            {
                sum += m_matrix[r][c];
            }
        }
        return sum;
    }

    void solution()
    {
        int left = 0;
        int right = m_matrix[0].size();

        int top = 0;
        int bottom = m_matrix.size();


        while( top != bottom)
        {
            if(right == left)
            {
                bottom -= 1;
                if(top == bottom)
                    break;
                right = m_matrix[0].size();
            }
            double sum;
            sum = 0;
            sum += sumOfMatrix(bottom, right);
            m_matrix[bottom - 1][right - 1] = sum;
            right -= 1;
        }

    }
    std::vector<std::vector<double>>  m_matrix;

    void printMatrix(vector<vector<double>>& matrix)
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
    std::vector<std::vector<double>> matrix;
    matrix = {{1,1,1}, {1,1,1}, {1,1,1}};
    auto solution = Solution(matrix);
    solution.printMatrix(matrix);
    solution.solution();

    for(int i = 0; i< solution.m_matrix[0].size(); i++)
    {
        for(int j = 0; j< solution.m_matrix.size(); j++)
        {
            std::cout<<solution.m_matrix[j][i]<<" ";
        }
    }
    std::cout<<std::endl<<"===================="<<std::endl;

    // Test 2
    std::vector<std::vector<double>> matrix2;
    matrix2 = {{1,1,1}, {1,1,1}};
    solution.printMatrix(matrix2);
    auto solution2 = Solution(matrix2);
    solution2.solution();

    for(int i = 0; i< solution2.m_matrix[0].size(); i++)
    {
        for(int j = 0; j< solution2.m_matrix.size(); j++)
        {
            std::cout<<solution2.m_matrix[j][i]<<" ";
        }
    }
}