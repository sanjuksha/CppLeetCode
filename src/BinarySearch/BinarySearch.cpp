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
