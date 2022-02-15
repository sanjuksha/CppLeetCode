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