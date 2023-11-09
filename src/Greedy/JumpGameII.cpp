#include <iostream>
#include <vector>
// LeetCode 45 Jump Game II

/**
 * @brief You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
    Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
    0 <= j <= nums[i] and
    i + j < n
    Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 * 
 */

class Solution
{
public:
    int jump(std::vector<int>& nums)
    {
       int l, r, result;
       l = r = result = 0;
       while (r < nums.size() - 1)
       {
        int farthest = 0;
        for(int i = l; i <= r; i++)
        {
            farthest = std::max(farthest, i +nums[i]);
        }
        l = r + 1;
        r = farthest;
        result++;
       }
    return result;
    }


};

int main()
{
    std::cout<<"LeetCode 45 Jump Game II"<<std::endl;
    std::vector<int> nums;
    nums = {2, 3, 1, 1, 4};

    Solution solution;
    int result = solution.jump(nums);

    std::cout<<"Mim Jumps : "<<result;
}