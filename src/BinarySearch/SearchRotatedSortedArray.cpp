#include <iostream>
#include <vector>

class Solution 
{
public:
    int searchInRotatedSorted(std::vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while(l <= r)
        {
            mid = l + (r-l)/2;
            if (target == nums[mid])
                return mid;

            // Left sorted
            if (nums[l] <= nums[mid])
            {
                if (target > nums[mid] || target < nums[l])
                {
                    l = mid +1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else // right sorted array
            {
                if (target < nums[mid])
                {
                    r = mid - 1;
                }
                else if ( target > nums[r])
                {
                    r = mid - 1;
                }
            }
        }

        return -1;


    }
};

int main()
{
    Solution solution;
    std::cout<<"LeetCode 33 : Search in Rotated Sorted Array"<<std::endl;
    
    //Inputs
    std::vector<int> nums;
    nums = { 4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    //Solution
    int indexOfTarget;
    indexOfTarget = solution.searchInRotatedSorted(nums, target);

    //Output
    std::cout<<"Index of Target Value: "<<indexOfTarget<<std::endl;
    
}