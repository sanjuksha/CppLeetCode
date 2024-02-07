/**
 * @file ValidAnagram.cpp
 * @author Sanjuksha Nirgude
 * @brief 
 * Given two strings s and t, return true if t is an anagram of s,
 *  and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the 
 * letters of a different word or phrase, typically using all 
 * the original letters exactly once.
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * @date 2023-07-15
 * 
 */


#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include<bits/stdc++.h>

class Solution {
public:
    bool isAnagram(std::string s, std::string t)
    {
        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s!=t)
            return false;
        else
            return true;

    }
};

int main()
{
    std::string s, t;
    s = "anagram";
    t = "nayaram";

    Solution solution;
    bool result;

    result = solution.isAnagram(s,t);
    std::cout<<"LeetCode Problem 242: Valid Anagram"<<std::endl;
    std::stringstream ss;
    ss << std::boolalpha << result;
    std::cout<<ss.str()<<std::endl;

}