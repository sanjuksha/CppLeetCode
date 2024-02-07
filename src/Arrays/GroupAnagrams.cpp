/**
 * @file GroupAnagrams.cpp
 * @author Sanjuksha Nirgude
 * @brief Given an array of strings strs, group the anagrams together. 
 * You can return the answer in any order. 
 * An Anagram is a word or phrase formed by rearranging the letters of a 
 * different word or phrase, typically using all the original letters exactly once.
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * @date 2024-01-25
 * 
 */


#include <iostream>
#include <vector>
#include <map>
#include <string>


class Solution 
{
public: 
    /**
     * @brief Group Anagrams 
     * Make a result vector which will have a  vector count (of each char)
     * as the key and the actual strings in the vector as a value.
     * To make a vector of counts, have a fixed size vector of 26 snd initial val
     * 0 whose index refers to the char like a = 1, b = 2 and so on..
     * Iterate through all the strings in the input string vector
     * for every char in this string add it's count to vector by incrementing
     * the vector values at that particular index.
     * Because Ascii of lowercase 'a' is not 0 substract it by 'a' so we get the 
     * range from 0 to 26
     * 
     * After the count is filled with the approriate string vector call getMapValues
     * @param strs 
     * @return std::vector<std::vector<std::string>> 
     */
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {

    std::map<std::vector<int>, std::vector<std::string>> result;
    for(auto& str : strs)
    {
        std::vector<int> count(26, 0);
        for(char c : str)
        {
            count[c - 'a']++;
        }
        result[count].push_back(str);
    } 
    return getMapValues(result);
    }

    /**
     * @brief Get the Map Values of the results into proper output format
     * 
     * @param result 
     * @return std::vector<std::vector<std::string>> 
     */

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
        std::cout<<"{ ";
        for(int i = 0; i < result.size(); ++i)
        {  
            std::cout<<"[ ";
            for(int j = 0; j < result[i].size(); ++j)
            {
                std::cout<<result[i][j];
                std::cout<<" , ";
            }
            std::cout<<" ] , ";
        }
        std::cout<<" }"<<std::endl;
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

