#include <iostream>
#include <vector>

class Solution
{

public:
    bool search2DMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        //this is 2D binary search
        // First we apply binary search to find which row contains target

        int top, bottom;
        top = 0;
        bottom = matrix.size() - 1 ;
        int rightCol = matrix[0].size()- 1;

        int midRow;

        while( top <= bottom)
        {
            midRow = top + (bottom - top)/2;
            if (target < matrix[midRow][0])
            {
                bottom = midRow -1 ;
            }
            else if (target > matrix[midRow][rightCol])
            {
                top = midRow + 1;
            }
            else
                break;
        }
        // check if all rows were traversed - it means we didn't find the target
        // At the end of above while loop we should have midRow as the one with target
        if(!(top <= bottom))
        {
            //We exceeded the traverse- no target found
            return false;
        }

        //Now binary search on the midRow that we found from above

         midRow = top + (bottom - top)/2;
         int l = 0;
         int r = matrix[midRow].size() - 1;
         int mid;

         while(l <= r)
         {
            mid = l + (r-l)/2;
            if (matrix[midRow][mid] > target)
            {
                r = mid - 1;
            }
            else if(matrix[midRow][mid] < target)
            {
                l = mid + 1;
            }
            else
                return true;
         }

         return false;

    }
};

int main()
{
    Solution solution;
    std::cout<<"LeetCode 74 : Search a 2D Matrix"<<std::endl;
  
    std::vector<std::vector<int>> matrix;

    matrix = {{1,3,5,7}, 
              {10,11,16,20},
              {23,30,34,60}};

    int target = 11;

    bool result;

    result = solution.search2DMatrix(matrix, target);

    std::cout<<std::boolalpha<<"Target exists: "<<result<<std::endl;



}