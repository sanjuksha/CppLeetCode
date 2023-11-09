#include <iostream>
#include <ctype.h>

class Solution {
public:

    bool checkIsPalindrome(std::string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }

    bool isPalindrome(std::string s) {
        std::string ss;
        for(auto& c : s)
        {
            if(isalnum(c))
            {
                ss += tolower(c);
            }
        }

        bool result =  checkIsPalindrome(ss);

        return result;
    }
};

int main()
{
    std::cout<<"LeetCode 125 : Valid Palindrome"<<std::endl;

    std::string s1, s2;
    s1 = "A man, a plan, a canal: Panama";
    std::cout<<s1<<std::endl;

    Solution solution;
    bool test1 = solution.isPalindrome(s1);

    std::cout<<std::boolalpha<<"Is a Palindrome : "<<test1<<std::endl;

    s2 = "race a car";
    bool test2 = solution.isPalindrome(s2);
    std::cout<<s2<<std::endl;

    std::cout<<std::boolalpha<<"Is a Palindrome : "<<test2<<std::endl;
}