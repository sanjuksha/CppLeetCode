/**
 * @file BinarySearch.cpp
 * @author Sanjuksha Nirgude
 * @brief Given an array of integers nums 
 * which is sorted in ascending order, and an integer target, 
 * write a function to search target in nums. If target exists, 
 * then return its index. Otherwise, return -1.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * 
 * @date 2023-11-02
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int binarySearch(std::vector<int>& nums, int target)
    {
        //Binary Search Algorithm
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right)
        {
            // The reason mid is calculated this way is bcoz
            // if the left and right values are too big 
            //there is a risk of over flow from 32-bit integer memory 
            // This method calculates the distance between them and adds it to the left to get mid.
            mid = left + (right -left)/ 2;
            if(nums[mid] < target) //target is on the right of mid value
            {
                left = mid + 1;
            }
            else if (nums[mid] > target) // target is on the left of mid value
            {
                right = mid - 1;
            }
            else //target is the mid value
            {
                return mid;
            } 

        }
        return -1; // target not found

    }
};

int main()
{
   std::cout<<"LeetCode 704 : Binary Search"<<std::endl;
  
    Solution solution;

    std::vector<int> nums;
    nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int index;

    index = solution.binarySearch(nums, target);

    std::cout<<"Target Index: "<<index<<std::endl; 


}
