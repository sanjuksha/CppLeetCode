#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>
class Solution
{
public:
    Solution()
    {
    }
    /**
     *  This function returns true if any value appears
        at least twice in the array, and return false
        if every element is distinct.
     * @param nums
     * @return true if duplicate exists false o.w
     */
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_map<int,int> numMap;
        for (auto& n : nums)
        {
            if(numMap.find(n) != numMap.end())
                return true;
            numMap[n] += 1;
        }
        return false;
    }
};

int main()
{
    std::cout<<"LeetCode Problem 217: Contains Duplicate"<<std::endl;

    std::vector<int> nums;
    nums = {1,3,2,4};
    Solution solution;

    bool result;
    result = solution.containsDuplicate(nums);
    std::stringstream ss;
    ss << std::boolalpha << result;
    std::cout<<ss.str()<<std::endl;

}