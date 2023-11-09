#include <iostream>
#include <vector>
#include "../Print/VectorPrinter.cpp"

class Solution 
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        //Prefix PostFix method - Since we have to exclude the number itself
        // If we calculate all the prefix multiplications & all the postfix multiplications we get the same result
        std::vector<int> result(nums.size(), 1);

        //Multiply and enter in result all prefix
        int prefix = 1;
        //Iterate forward to find prefix
        for(int i = 0; i < nums.size(); i++ )
        {
            result[i] = prefix;
            prefix = nums[i] * prefix;
        }

        //Iterate backwards to find postfix
        int postfix = 1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }

        return result;

    }
};

int main()
{
    std::cout<<"LeetCode 238. Product of Array Except Self"<<std::endl;
    Solution solution;
    std::vector<int> nums;
    nums = {1, 2, 3, 4};

    std::vector<int> result;
    result = solution.productExceptSelf(nums);

    VectorPrinter vectorPrinter(result);
    vectorPrinter.print();



}