#include <iostream>
#include <vector>
#include "gtest/gtest.h"

class Solution
{
public:
    Solution()
    {
        l = 0;
        r = 1;
        maxP = 0;
    }

    int maxProfit(std::vector<int>& prices)
    {
        while( r < prices.size())
        {
            if(prices[l] < prices[r])
            {
                int profit;
                profit = prices[r] - prices[l];
                maxP = std::max(profit, maxP);
            }
            else
            {
                l = r;
            }
            r +=1;
        }
        return maxP;
    }

private:
    int l;  ///< l = buy, initializing to 0
    int r;  ///< r = sell, initializing to 1
    int maxP; ///<Maximum profit
};

int main()
{
    std::cout<<"LeetCode Problem 121: Best Time to Buy and Sell"<<std::endl;
    std::vector<int> prices;
    prices = {7, 1, 5, 3, 6, 4};

    Solution solution;
    int result;
    result = solution.maxProfit(prices);

    std::cout<<"Max Profit: "<<result<<std::endl;
}