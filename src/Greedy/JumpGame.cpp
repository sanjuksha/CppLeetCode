#include <iostream>
#include <vector>
//Leetcode 55. Jump Game
/**
 * @brief You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
    Return true if you can reach the last index, or false otherwise.
    Example 1:

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 * 
 */

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        int goal = nums.size() - 1;
        
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(nums[i] + i >= goal)
            {
                goal = i;
            }
        }
        
        if(!goal)
        {
            return true;
        }
        return false;

    }
};

int main()
{
    std::cout<<"Leetcode 55. Jump Game"<<std::endl;
    std::vector<int> nums;
    //nums = {2, 3, 1, 1, 4};
    nums = {3, 2, 1, 0, 4};

    Solution solution;
    bool result = solution.canJump(nums);

    std::cout<<"Can Jump : "<<result;
}