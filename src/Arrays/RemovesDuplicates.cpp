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
                nums.erase(nums.begin() + i);
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
    std::vector<int> nums = {0,0,0,1,1,2,2,3,3,3,4};

    Solution solution;

    int result;
    result = solution.removeDuplicates(nums);

    std::cout<<result<<std::endl;


}