#include <iostream>
#include <vector>

class VectorPrinter
{
public:
    VectorPrinter(const std::vector<int>& vec) : vec_(vec)
    {

    }

    void print() const // this function won't modify the class contents
    {
        std::cout<<"[ ";
        for(int i = 0; i < vec_.size(); ++i)
        {
            std::cout<<vec_[i];
            if(i != vec_.size() -1)
            {
                std::cout<<", ";
            }
        }
        std::cout<<" ]"<<std::endl;
    }

private:
    const std::vector<int>& vec_;

};

// int main()
// {
//     std::vector<int> nums = {1,2,3,4,5};
//     VectorPrinter vectorPrinter(nums);
//     vectorPrinter.print();

//     return 0;
// } 


