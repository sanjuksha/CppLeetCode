/**
 * @file MaximumSubArray.cpp
 * @author Sanjuksha Nirgude
 * @brief 
 * Given an integer array nums, find the subarray
 * with the largest sum, and return its sum.
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * 
 * @date 2024-01-24
 */

#include <iostream> 
#include <algorithm>
#include <vector>

class Solution
{
public: 
    int maxSubArray(std::vector<int>& nums)
    {
        int result = nums[0];
        int curr = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            curr = std::max(curr + nums[i], nums[i]);
            result = std::max(result, curr);
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums;
    nums = {-2,1,-3,4,-1,2,1,-5,4};

    int result;
    Solution solution;
    result = solution.maxSubArray(nums);
    std::cout<<"LeetCode 53: Maximum SubArray \n";
    std::cout<<"Output: "<<result<<"\n";

}