#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include "../Print/VectorPrinter.cpp"

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> answer(temperatures.size(),0);
        std::stack<std::pair<int,int>> stack; // (index, temp)
        for(size_t i = 0; i < temperatures.size(); ++i)
        {
            while (!stack.empty() && temperatures[i] > stack.top().second)
            {
                // pop the last temperature from the stack
                unsigned int stackInd, stackTemp;
                std::pair<int, int> poppedPair;
                poppedPair = stack.top();
                stackInd = poppedPair.first;
                stackTemp = poppedPair.second;
                stack.pop();
                
                // Update the answer value at the stack index based on days count
                answer[stackInd] = i - stackInd;
            }
            stack.push(std::make_pair(i,temperatures[i]));
        }
        return answer;
    }

};

int main ()
{
    std::cout<<"Leetcode 739: Daily Temperatures"<<std::endl;
    std::vector<int> temperatures;
    std::vector<int> answer;
    temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution solution;
    answer = solution.dailyTemperatures(temperatures);
    VectorPrinter vectorPrinter(answer);
    vectorPrinter.print();


}