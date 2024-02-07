/**
 * @file RemovesDuplicates.cpp
 * @author your name (you@domain.com)
 * @brief Given an integer array nums sorted in non-decreasing order,
 * remove the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * Then return the number of unique elements in nums.
 * 
 * Examples:
 * Input: nums = [1,1,2]
 * Output: 2, nums = [1,2,_]
 * Explanation: Your function should return k = 2, 
 * with the first two elements of nums being 1 and 2 respectively.
 * It does not matter what you leave beyond the returned k 
 * (hence they are underscores).
 * 
 * @date 2023-09-17
 * 
 */


#include <iostream>
#include <vector>
#include<map>
#include "../Print/VectorPrinter.cpp"

class Solution
{
public:
    int removeDuplicates(std::vector<int> nums)
    {
        std::map<int, int> count;

        for(int i = 0; i < nums.size(); i++)
        {
            if (count.find(nums[i]) != count.end())
            {
                count[nums[i]] = 1;
                nums.erase(nums.begin() + i);
                i--;
            }
            else
            {
                count[nums[i]] += 1;
            }
        }


        return nums.size();

    }

};

int main()
{
    std::cout<<"LeetCode 26. Removes Duplictaes"<<std::endl;
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution solution;

    int result;
    result = solution.removeDuplicates(nums);

    std::cout<<"Number of unique elements : "<<result<<"\n";


}