//// This is a Multi Threading Leetcode question  1114

/**
     Suppose we have a class:

    public class Foo {
    public void first() { print("first"); }
    public void second() { print("second"); }
    public void third() { print("third"); }
    }
    The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

    Note:

    We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo
{
public:
    Foo()
    {
        currentPrint = 1;
    }

    void first(function<void()> printFirst)
    {
        std::unique_lock<std::mutex> lock(m);
        currentPrint = 2;
        printFirst();
        cv.notify_one();

    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<mutex> lock(m);
        cv.wait(lock,[&]() {return currentPrint == 2;});
        currentPrint = 3;
        printSecond();
        cv.notify_one();
        
    }

    void third(function<void()> printThird)
    {
       std::unique_lock<mutex> lock(m);
       cv.wait(lock, [&](){return currentPrint == 3;});
       printThird();
        
    }

    void printFirst()
    {
        // PrintFirst
        std::cout<<"First";

    }

    void printSecond()
    {
        // PrintSecond
        std::cout<<"Second";
        
    }
    void printThird()
    {
        // PrintThird
        std::cout<<"Third";
        
    }
private:
    std::condition_variable cv;
    int currentPrint;
    std::mutex m;

};

int main ()
{
    std::cout<<"LeetCode 1114: Print In Order"<<std::endl;
    Foo foo;
    std::thread ThreadA([&foo]() 
                    { 
                        foo.first([&foo]()
                         {
                            foo.printFirst();
                         });
                     });

    std::thread ThreadB([&foo]() {
        foo.second([&foo]() {
            foo.printSecond();
        });
    });

    std::thread ThreadC([&foo]() {
        foo.third([&foo]() {
            foo.printThird();
        });
    });

    ThreadA.join();
    ThreadB.join();
    ThreadC.join();
}