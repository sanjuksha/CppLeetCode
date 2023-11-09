//// This is a Multi Threading Leetcode question  1115

/**
 * @brief The same instance of FooBar will be passed to two different threads:

    thread A will call foo(), while
    thread B will call bar().
    Modify the given program to output "foobar" n times.
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class FooBar {
private:
    int n;
    int currentPrint;
    std::mutex m;
    std::condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        currentPrint = 1;
    }

    void foo(function<void()> printFoo) 
    {
        
        
        for (int i = 0; i < n; i++) 
        {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock,[&]() {return currentPrint == 1;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            currentPrint = 2;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
       
        for (int i = 0; i < n; i++) 
        {
            std::unique_lock<mutex> lock(m);
            cv.wait(lock,[&]() {return currentPrint == 2;});
   
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            currentPrint =1;
            cv.notify_one();
        }
    }

    void printFoo()
    {
        std::cout<<"Foo";
    }

    void printBar()
    {
        std::cout<<"Bar";
    }
};

int main ()
{
    std::cout<<"Leetcode 1115: PrintFooBar Alternately"<<std::endl;
    
    FooBar foobar(10);
    std::thread ThreadFoo([&foobar]() 
                    { 
                        foobar.foo([&foobar]()
                         {
                            foobar.printFoo();
                         });
                     });

    std::thread ThreadBar([&foobar]() {
        foobar.bar([&foobar]() {
            foobar.printBar();
        });
    });

    ThreadFoo.join();
    ThreadBar.join();
}