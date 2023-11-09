//
// Created by Sanjuksha on 1/2/2023.
//
#include <iostream>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i ++)
        {
            int bit ;
            bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        return res;

    }
};

int main()
{
    std::cout<<"LeetCode Problem: 190. Reverse Bits"<<std::endl;

    uint32_t n;
    n = 00000010100101000001111010011100;
    uint32_t result;
    Solution solution;

    result = solution.reverseBits(n);

    std::cout<<result<<std::endl;
};