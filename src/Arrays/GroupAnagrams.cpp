#include <iostream>
#include <vector>
#include <map>
#include <string>
//TODO: Fix Output

class Solution 
{
public: 
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {

    std::map<std::vector<int>, std::vector<std::string>> result;

    //count occurences of letters
    std::vector<int> count(26);

    for(auto& str : strs)
    {
        //counting occurences
        for(char c : str)
        {
            count[c - 'a']++;
        }
        result[count].push_back(str);
    } 

    return getMapValues(result);
    }

    std::vector<std::vector<std::string>> getMapValues(std::map<std::vector<int>, std::vector<std::string>>& result)
    {
        std::vector<std::vector<std::string>> mapValues;

        for(auto& pair : result)
        {
            mapValues.push_back(pair.second);
        }

        return mapValues;
    }



    void print(std::vector<std::vector<std::string>>& result) const // this function won't modify the class contents
    {
        std::cout<<"[ ";
        for(int i = 0; i < result.size(); ++i)
        {  
            std::cout<<"[ ";
            for(int j = 0; j < result[i].size(); ++j)
            {
                std::cout<<result[i][j];
                std::cout<<" , ";
            }
            std::cout<<" ]"<<std::endl;
        }
        std::cout<<" ]"<<std::endl;
    }
};

int main()
{
    Solution solution;
    std::vector<std::string> strs;
    strs = {"eat","tea","nat","tan","ate","bat"};

    std::vector<std::vector<std::string>> result;

    result = solution.groupAnagrams(strs);
    solution.print(result);

}

