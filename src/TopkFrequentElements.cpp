#include <iostream>
#include <vector>
#include <map>
#include "VectorPrinter.cpp"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::map<int, int> count;
        std::map<int, vector<int>> freq;
        std::vector<int> res;

        // Count each elements occurrence
        for(int i = 0; i < nums.size(); i++)
        {
            if(count.find(nums[i]) == count.end())
            {
                count[nums[i]] = 1;
            } else
            {
                count[nums[i]] += 1;
            }
        }
        if(count.size() < 2 && k <= count.size())
        {
            res.push_back(count.begin()->first);
            return res;

        }

        // Frequency  map (number of occurences, value vector)
//        std::map<int, int>::iterator it;

        for (auto& it : count)
        {

            if(freq.find(it.second) != freq.end())
            {
                freq[it.second].push_back(it.first);
            } else
            {
                std::vector<int> resVec;
                resVec.push_back(it.first);
                freq[it.second] = resVec;
            }
        }

        for(int i = sizeof(freq); i > 0; i--)
        {
            for(auto const& a : freq[i])
            {
                if(res.size() != k)
                {
                    res.push_back(a);
                }
            }
        }
        return res;
    }

};

int main()
{
    std::cout<<"LeetCOde 347 : Top k Frequent elements"<<std::endl;

    std::vector<int> inputArray;

    inputArray = {1,1,1,2,2,3,3,3};
    int k =  3;

    

    Solution solution;
    std::vector<int> result;

    result = solution.topKFrequent(inputArray, k);
    VectorPrinter vectorPrinter(result);
    vectorPrinter.print();

}