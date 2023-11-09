//// This is a Multi Threading Leetcode question  1195

/**
 * @brief Fizz Buzz MultiThreaded
 * You have the four functions:

    printFizz that prints the word "fizz" to the console,
    printBuzz that prints the word "buzz" to the console,
    printFizzBuzz that prints the word "fizzbuzz" to the console, and
    printNumber that prints a given integer to the console.
    You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

    Thread A: calls fizz() that should output the word "fizz".
    Thread B: calls buzz() that should output the word "buzz".
    Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
    Thread D: calls number() that should only output the integers.
 * 

    Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

    "fizzbuzz" if i is divisible by 3 and 5,
    "fizz" if i is divisible by 3 and not 5,
    "buzz" if i is divisible by 5 and not 3, or
    i if i is not divisible by 3 or 5.
    Implement the FizzBuzz class:

    FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
    void fizz(printFizz) Calls printFizz to output "fizz".
    void buzz(printBuzz) Calls printBuzz to output "buzz".
    void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
    void number(printNumber) Calls printnumber to output the numbers.
    

    Example 1:

    Input: n = 15
    Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
    Example 2:

    Input: n = 5
    Output: [1,2,"fizz",4,"buzz"]
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;


class FizzBuzz
{

private:
    int n;
    int x;
    std::mutex m;
    std::condition_variable cv;

public:

    FizzBuzz(int n)
    {
        this->n = n;
        this-> x = 1;

    }

    void fizz(function<void()> printFizz)
    {
        while(true)
        {
            std::unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (x%3 == 0 && x%5 != 0) || x > n;});
            if(x > n) return;
            printFizz();
            x++;
            cv.notify_all();
        }

    }

    void buzz(function<void()> printBuzz)
    {
        while(true)
        {
            std::unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (x%3 != 0 && x%5 == 0) || x > n;});
            if(x > n) return;
            printBuzz();
            x++;
            cv.notify_all();
        }

  
    }

    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while(true)
        {
            std::unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (x%3 == 0 && x%5 == 0) || x > n;});
            if(x > n) return;
            printFizzBuzz();
            x++;
            cv.notify_all();
        }

    }

    void number(function<void(int)> printNumber)
    {
        while(true)
        {
            std::unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (x%3 != 0 && x%5 != 0) || x > n;});
            if(x > n) return;
            printNumber(x);
            x++;
            cv.notify_all();
        }

    }

    void printFizz()
    {
        string s = "fizz";
        std::cout<<s;
    }

    void printBuzz()
    {
        string s = "buzz";
        std::cout<<s;
    }

    void printFizzBuzz()
    {
        string s = "fizzbuzz";
        std::cout<<s;
    }

    void printNumber(int x)
    {
        std::cout<<x;
    }


};

int main()
{
    std::cout<<"LeetCode 1195: Fizz Buzz Multithreaded"<<std::endl;

    int n = 15; // Change n to your desired sequence length

    FizzBuzz fb(n);

    // Define print functions
    function<void()> printFizz = []() { cout << "fizz" << endl; };
    function<void()> printBuzz = []() { cout << "buzz" << endl; };
    function<void()> printFizzBuzz = []() { cout << "fizzbuzz" << endl; };
    function<void(int)> printNumber = [](int num) { cout << num << endl; };

    // Create threads
    thread threadA(&FizzBuzz::fizz, &fb, printFizz);
    thread threadB(&FizzBuzz::buzz, &fb, printBuzz);
    thread threadC(&FizzBuzz::fizzbuzz, &fb, printFizzBuzz);
    thread threadD(&FizzBuzz::number, &fb, printNumber);

    // Join threads
    threadA.join();
    threadB.join();
    threadC.join();
    threadD.join();





}

