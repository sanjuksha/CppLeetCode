#include <iostream>
#include <vector>
#include "../Print/VectorPrinter.cpp"
#include <algorithm>

class Solution 
{
public:
     std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
     {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for(int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i-1] == nums[i])
            {
                continue;
            }
            // Similar to Two sum II from here
            int l = i + 1;
            int r = nums.size() - 1; 

            while(l < r)
            {
                int sum;
                sum = nums[i] + nums[l] + nums[r];
                
                if (sum > 0)
                {
                    r--;
                }
                else if(sum < 0)
                {
                    l++;
                }
                else
                {
                    result.push_back({nums[i],nums[l],nums[r]});
                    // Incrementing pointers
                    l++;
                    while(nums[l] == nums[l-1] && l < r)
                    {
                        l++;
                    }
                }
               
               
            }
            
        }
        return result;

     }
};

int main()
{
    Solution solution;
    std::cout<<"Leetcode 15 : 3Sum"<<std::endl;

    //Inputs
    std::vector<int> nums;
    nums = {-1,0,1,2,-1,-4};
    // nums = {0,0,0};

    //solution
    std::vector<std::vector<int>> result;
    result = solution.threeSum(nums);
  
    //Outputs
    for (auto& a : result)
    {
          VectorPrinter vectorPrinter(a);
          vectorPrinter.print();
    }


}