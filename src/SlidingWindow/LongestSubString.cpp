#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int l = 0;
        int r = 0;
        int maxSize = 0;
        std::unordered_set<char> charSet;

        //Iterate through the length of string size
        while (r < s.size())
        {
            //if the char at the right pointer is already in the set
            // remove the leftmost chars from the set until the right ptr char is removed
            while(charSet.find(s[r]) != charSet.end())
            {
                charSet.erase(s[l]);
                ++l;
            }
            //Calculate the max size until now
            maxSize = std::max(maxSize, r - l + 1);
            //If it's not in the charSet then lets add it there
            charSet.insert(s[r]);
            ++r;
            
        }
        return maxSize;
     }



};

int main()
{
    Solution solution;
    int result;
    std::string s;
    s = "abcabcbb";
    // s = "bbbbb";

    result = solution.lengthOfLongestSubstring(s);

    std::cout<<s<< " = " << result <<std::endl;

}