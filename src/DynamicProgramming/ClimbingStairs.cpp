#include <iostream>

/// \class Solution to Climbing stairs
///\brief You are climbing a staircase. It takes n steps to reach the top.
///Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n)
    {
        int stepOne, stepTwo;
        stepOne = 1;
        stepTwo = 1;
        for(int i=0; i<n-1; i++)
        {
            int temp;
            temp = stepOne;
            stepOne = stepOne + stepTwo;
            stepTwo = temp;
        }
        return  stepOne;
    }
};

int main()
{
    // Number of Steps to climb
    std::cout<<"Leetcode 70: Climbing Stairs"<<std::endl;
    int n;
    std::cout<<"Enter number of steps to climb: ";
    std::cin>>n;
    std::cout<<std::endl;
    Solution solution;
    int output;
    output = solution.climbStairs(n);
    std::cout<<"Number of ways to climb: "<<output<<std::endl;

}