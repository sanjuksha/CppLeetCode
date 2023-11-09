#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        //Using sliding window
        int l = 0;
        std::unordered_set<int> window;

        //Iterate through all the values
        for (int r = 0; r < nums.size(); r++)
        {
            //Check the current size of the window
            if (r-l > k)
            {
                //If size of window is more than K its invalid
                // So update the window by removig leftmost element
                window.erase(nums[l]);
                l++;
            }

            // Check if element in window and if not then add
            if(window.find(nums[r]) != window.end())
                return true;
            window.insert(nums[r]);

        }
        return false;
    }
};

int main()
{
    std::vector<int> nums;
    nums = {1, 2, 3, 1};
    int k = 1;

    Solution solution;
    bool result;

    result = solution.containsNearbyDuplicate(nums, k);

    std::cout<<std::boolalpha<<result<<std::endl;

}