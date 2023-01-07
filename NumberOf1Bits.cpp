//
// Created by Sanjuksha on 1/2/2023.
//

#include <iostream>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n)
        {
            n = n & (n-1);
            result += 1;
        }
        return result;
    }
};
int main()
{
    std::cout<<"LeetCode Problem: 191. Number of 1 Bits"<<std::endl;
    uint32_t n;
    n = 00000000000000000000000000001011;
    int result;
    Solution solution;

    result = solution.hammingWeight(n);

    std::cout<<result<<std::endl;
}