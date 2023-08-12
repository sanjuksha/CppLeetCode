//
// Created by Sanjuksha on 1/2/2023.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums)
    {
        int res = 0;
        for(int i = 1; i <= nums.size()  ; i++)
        {
            res += (i - nums[i - 1]);
        }
        return res;
    }
};

int main()
{
    std::cout<<"LeetCode Problem: 268. Missing Number\n";
    std::vector<int> nums;
    nums = {0, 3, 1};

    Solution solution;
    int result;
    result = solution.missingNumber(nums);
    std::cout<<result<<std::endl;
    std::cout<<0%5;

};