#include <iostream>
#include <vector>

class Solution
{
public: 
    int maxArea(std::vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int maxArea = 0;

        while( l < r)
        {
            int currArea;
            currArea = (r-l)*std::min(nums[l],nums[r]);
            maxArea = std::max(currArea, maxArea);
             
            if(nums[l] < nums[r])
            {
                //Keep the right val and move left
                l++;
            }
            else if(nums[r] < nums[l])
            {
                //Keep the left val and move right
                r--;
            }
            else //if both vals are same
            {
                //Increment the pointe of which the next is larger
                if(nums[l+1] > nums[r-1] && (l+1) < (r-1))
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return maxArea;

    }


};

int main()
{
    Solution solution;
    std::cout<<"LeetCode 11 : Container With Most Water"<<std::endl;
   
    //Inputs
    std::vector<int> nums;
    nums = {1,8,6,2,5,4,8,3,7};

    //solution
    int maxArea = solution.maxArea(nums);

    //Output
    std::cout<<"Max Area = "<<maxArea<<std::endl;


}











