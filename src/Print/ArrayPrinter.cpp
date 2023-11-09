#include <iostream>

class ArrayPrinter
{
public:
    /**
     * @brief In order to determine the array length
     * automatically, the template parameter N captures
     * the size of the array, and the constructor takes 
     * an array reference int (&arr)[N] as a parameter. 
     */
    template <size_t N>
    ArrayPrinter(int (&arr)[N]) : arr_(arr), length_(N)
    {

    }

    void print() const // this function won't modify the class contents
    {
        std::cout<<"[ ";
        for(int i = 0; i < length_; ++i)
        {
            std::cout<<arr_[i];
            if(i != length_ -1)
            {
                std::cout<<", ";
            }
        }
        std::cout<<" ]"<<std::endl;
    }

private:
    int* arr_;
    size_t length_;


};

int main()
{
    int nums[] = {1,2,3,4,5};
    ArrayPrinter arrayPrinter(nums);
    arrayPrinter.print();

    return 0;
} 
 

