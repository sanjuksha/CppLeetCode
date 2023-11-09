#include <iostream>
#include <vector>
#include <map>
#include "../Print/VectorPrinter.cpp"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::map<int, int> count; //Count occurences of each value in map
        std::map<int, vector<int>> freq; //Vector in which index is the frequency and 
        //values are the int's which occured at that frequency
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
        // Edge case where each element occurs only once and there is only one element
        if(count.size() < 2 && k <= count.size())
        {
            res.push_back(count.begin()->first);
            return res;

        }

       
//        std::map<int, int>::iterator it;

         // Make a Frequency  map (number of occurences, value vector) using the count map
        for (auto& it : count)
        {
            // here count value is the key for freq map
            if(freq.find(it.second) != freq.end())
            {
                freq[it.second].push_back(it.first);
            } else
            {
                //if the freq key doesn't exist, create one and add a vector
                std::vector<int> resVec;
                resVec.push_back(it.first);
                freq[it.second] = resVec;
            }
        }

        // Iterate backwards to find the top frquently occuring numbers
        for(int i = sizeof(freq); i > 0; i--)
        {
            // for every element in the vector of that frequency
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