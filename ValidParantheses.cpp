#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s)
    {
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
        return para.empty();

    }
};

int main()
{
    std::cout<<"LeetCode 20 : Valid Parantheses"<<std::endl;
    std::string s;
    s = "(){[]}";

    Solution solution;
    bool result = solution.isValid(s);

    std::cout << std::boolalpha << result << std::endl;
}