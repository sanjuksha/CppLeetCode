#include <iostream>
#include <string>
#include <vector>

class Solution
{

public:
    int characterReplacement(std::string s, int k)
    {
        int l = 0; //left pointer
        int r = 0; //right pointer
        int maxCount = 0;

        //Vector of counts of letter A to Z
        // Its of size 26 since there are 26 letters
        //each index corresponds to the letter starting with A = 0, B= 1 ...
        std::vector<int> charCount(26);

        int result = 0;

        while (r < s.size())
        {
            //Increment the counter for the current char
            charCount[s[r] - 'A']++; // This is bcoz if char is A so Ascii of A- A = 0
            // So we are incrementing the value at count[0] and so on ...
            //max of the charCount
            maxCount = std::max(maxCount, charCount[s[r]- 'A']);
            //Check if window is valid or not
            if((r-l+1 - maxCount) > k)
            {
                //if window not valid
                l++; // move left pointer
                charCount[s[l]-'A']--; //Decrement val of char
            }

            result = std::max(result, r-l+1);
            r++;

        }
        return result;

    }

};

int main()
{

Solution solution;
int result;
int k = 1;
std::string s;
s = "AABABBA";
result = solution.characterReplacement(s, k);

std::cout<<result<<std::endl;

}