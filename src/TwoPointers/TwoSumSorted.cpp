#include <iostream>
#include <vector>
#include "../Print/VectorPrinter.cpp"

class Solution
{
public: 
    std::vector<int> twoSumSorted(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; 
        std::vector<int> result;

        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum > target)
            {
                // need to reduce the sum to get near target
                // As the array is sorted - we move right pointer
                right--;
            }
            else if (sum < target)
            {
                // need to incread the sum to get near the target
                // As the array is sorted - we move left pointer
                left++;
            }
            else
            {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::cout<<"LeetCode 167 : Two Sum II - Input array sorted"<<std::endl;

    //Inputs
    std::vector<int> nums;
    // nums = {1,3,4,5,7,11,15};
    nums = {2,7,11,15};
    int target = 9;

    //Solution
    std::vector<int> output;
    output = solution.twoSumSorted(nums, target);

    //Output
    VectorPrinter vectorPrinter(output);
    vectorPrinter.print();

}