#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

class MinStack
{
public:
    MinStack()
    {
        stack_ = {};
        minStack_ = {};
    }

    void push(int val)
    {
        stack_.push(val);
        if (!minStack_.empty())
            val = std::min(val,minStack_.top());
        minStack_.push(val);
    }

    void pop()
    {
        stack_.pop();
        minStack_.pop();
    }

    int top()
    {
        return stack_.top();
    }

    int getMin()
    {
       return minStack_.top();
    }
private:
    std::stack<int> stack_;
    std::stack<int> minStack_;
};

int main()
{
    std::cout<<"Leetcode 155. Min Stack"<<std::endl;
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    std::cout<<"Min value: "<< obj->getMin()<<std::endl;
    std::cout<<"Top value: "<< obj->top()<<std::endl;
    obj->pop();
    std::cout<<"Min value: "<< obj->getMin()<<std::endl;

}