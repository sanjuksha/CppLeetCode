/**
 * @file FindMinRotatedSortedArray.cpp
 * @author Sanjuksha Nirgude
 * @brief Suppose an array of length n sorted in ascending
 * order is rotated between 1 and n times. For example,
 * the array nums = [0,1,2,4,5,6,7] might become:
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 * 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]]
 * 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * 
 * Given the sorted rotated array nums of unique elements, 
 * return the minimum element of this array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 * 
 * Example 1:
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 * @date 2023-10-30
 */
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
            //if nums[left] > nums[right] meanning array not sorted 
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