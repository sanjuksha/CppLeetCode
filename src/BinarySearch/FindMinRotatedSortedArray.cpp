#include <iostream>
#include <vector>

class Solution 
{
public: 
    int findMin(std::vector<int>& nums)
    {
        //Since this is a sorted array we use Binary Search
        int l = 0;
        int r = nums.size() - 1;
        int res = nums[l]; //initially left as we start with an assumption of left is least
        int mid;
        while( l <= r)
        {
            if (nums[l] < nums[r]) //array is sorted & non rotated
            {
                res = std::min(res, nums[l]);
                break;
            }

            mid = l + (r-l) / 2;
            //if left > right meanning array not sorted 
            res = std::min(res, nums[mid]);

            if (nums[l] <= nums[mid]) //mid is in right sorted array
            {
                //so we change our left pointer
                l = mid + 1;
            }
            else // (nums[r] > nums[mid]) //mid is in left sorted array
            {
                r = mid - 1;
            }
            
        }
        return res;
    }

};

int main()
{
    Solution solution;
    std::cout<<"LeetCode 153 : Find Minimum in Rotated Sorted Array"<<std::endl;
    std::vector<int> nums;
    nums = {3, 4, 5, 0, 1, 2};

    int minVal = solution.findMin(nums);

    std::cout<<"Minimum Val in the array: "<<minVal<<std::endl;
}