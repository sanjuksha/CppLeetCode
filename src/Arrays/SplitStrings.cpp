#include <iostream>
#include <vector>
//TODO: Not solving all cases
/*
    Given an array of strings words and a character separator, split each string in words by separator.

    Return an array of strings containing the new strings formed after the splits, excluding empty strings.

    Notes

    separator is used to determine where the split should occur, but it is not included as part of the resulting strings.
    A split may result in more than two strings.
    The resulting strings must maintain the same order as they were initially given.
    

    Example 1:

    Input: words = ["one.two.three","four.five","six"], separator = "."
    Output: ["one","two","three","four","five","six"]
    Explanation: In this example we split as follows:
*/

class Solution
{
public:
    std::vector<std::string> splitStrings(std::vector<std::string> words, char separator)
    {
        std::vector<std::string> result;
        for (auto& word: words)
        {
            int start = 0;
            int end = word.find(separator);

            while( end != std::string::npos) 
            {
                result.emplace_back(word.substr(start, end-start));
                start = end + 1;
                end = word.find(separator, start);
            }

            if (start < word.length())
            {
                result.push_back(word.substr(start));
            }
        }

        return result;

    }

};

int main()
{
    std::cout<<"Leetcode 2788. Split strings by separator"<<std::endl;
    std::vector<std::string> words = {"one.two.three", "four.five", "six"};
    char separator = '.';
    Solution solution;
    std::vector<std::string> result = solution.splitStrings(words, separator);

    for (const std::string& s : result) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}