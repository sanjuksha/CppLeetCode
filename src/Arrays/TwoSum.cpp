/**
 * @file TwoSum.cpp
 * @author Sanjuksha Nirgude
 * @brief Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 */


#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution
{
public:
    Solution()
    {

    }

    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int,int> prevMap;
        std::vector<int> result;

        for(int i=0; i<=nums.size(); i++)
        {
            int diff;
            diff = target - nums[i];
            auto it = prevMap.find(diff);
            if(it != prevMap.end())
            {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            prevMap[nums[i]] = i;
        }
        return {0,0};
    }
};

int main()
{
    std::cout<<"LeetCode Problem 1: Two Sum"<<std::endl;
    std::vector<int> nums;
    nums = {3,2,4};
    int target;
    target = 6;
    Solution solution;
    std::vector<int> resultPair;
    resultPair = solution.twoSum(nums, target);

    std::cout<<"Output: [ "<<resultPair[0]<<","<<resultPair[1]<<"]"<<std::endl;

}