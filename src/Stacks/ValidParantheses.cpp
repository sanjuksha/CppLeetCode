#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s)
    {
        std::stack<char> stackData;
        std::unordered_map<char,char> closeToOpen;
        closeToOpen [')'] = '(';
        closeToOpen [']'] = '[';
        closeToOpen ['}'] = '{';

        for(auto& c : s)
        {
            if(closeToOpen.find(c) != closeToOpen.end())
            {
                if((!stackData.empty()) && (stackData.top()) == closeToOpen[c])
                {
                    stackData.pop();
                }
                    
                else
                    return false;
            }
            else
            {
                   stackData.push(c);
            }
        }
       return stackData.empty();

    }
};




/// Another Solution
/***
        std::stack<char> para;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                    para.push(s[i]);
                    break;

                case ')':
                    if(para.empty() || para.top() != '(')
                        return false;
                    else
                        para.pop();
                        break;

                case ']':
                    if(para.empty() || para.top() != '[')
                        return false;
                    else
                        para.pop();
                    break;

                case '}':
                    if(para.empty() || para.top() != '{')
                        return false;
                    else
                        para.pop();
                    break;
                default:;

            }
        }
        return para.empty();}

};
***/

int main()
{
    std::cout<<"LeetCode 20 : Valid Parantheses"<<std::endl;
    std::string s;
    s = "(){]}";

    Solution solution;
    bool result = solution.isValid(s);

    std::cout << std::boolalpha << result << std::endl;
}