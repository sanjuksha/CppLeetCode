/**
 * @file DesignCircularQueue.cpp
 * @author Sanjuksha Nirgude
 * @brief Design your implementation of the circular queue.
 *  The circular queue is a linear data structure in which 
 * the operations are performed based on FIFO (First In First Out) principle,
 *  and the last position is connected back to the first position to make a circle.
 *  It is also called "Ring Buffer".
 * 
 * One of the benefits of the circular queue is that 
 * we can make use of the spaces in front of the queue.
 * In a normal queue, once the queue becomes full, 
 * we cannot insert the next element even if there 
 * is a space in front of the queue. But using the circular queue, 
 * we can use the space to store new values.
 * 
 * Implement the MyCircularQueue class:
 * MyCircularQueue(k) Initializes the object with the size of the queue to be k.
 * int Front() Gets the front item from the queue. If the queue is empty, return -1.
 * int Rear() Gets the last item from the queue. If the queue is empty, return -1.
 * boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
 * boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
 * boolean isEmpty() Checks whether the circular queue is empty or not.
 * boolean isFull() Checks whether the circular queue is full or not.
 * You must solve the problem without using the built-in queue 
 * data structure in your programming language. 
 
 * @date 2024-02-07
 * 
 */

#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode() : value(0), next(nullptr), prev(nullptr){}
    ListNode(int value) : value(value), next(nullptr), prev(nullptr){}
    ListNode(int value, ListNode* prev, ListNode* next) : value(value), prev(prev), next(next) {}
};

class MyCircularQueue
{
public:
    //Constructor - k is the fixed size of the circular queue
    MyCircularQueue(int k) :capacity(k), size(0), head(nullptr), tail(nullptr)
    {

    }
    bool enQueue(int value)
    {

        if (isFull())
            return false; // can't add anything if the list is already full

        // Using the value make a new node- note that its prev and next would null right now
        ListNode* newNode = new ListNode(value);
        //If this is the first node to be added
        if(isEmpty())
        {
            head = tail = newNode; //Both head and tail are newNode as it's the first node of the list
        }
        else // just continuing in the already started list
        {
            tail->next = newNode; //the current tail's next is now set to new node, establishing the link from prev tail to current tail
            newNode->prev = tail; // Establishing the prev link of newNode to the old tail
            tail = newNode; //The tail pointer is updated to point to the new node, indicating that it is now the last element in the queue.
        }
        size++;
        
        return true;
    }
    //Always removes the oldest element in the queue
    bool deQueue()
    {
        if (isEmpty())
            return false;  // If the list is empty, can't remove anything
        
        // We have to remove the oldest element
        //Create a temp node to keep track of old memory location of current head
        ListNode* temp = head;
        //Find the oldest element which is next of the current dummy node head
        head = head->next; //this is the dequeueing step where we replace the old head with new head
        // Now if the new head is nullptr meaning this was the last element in the list
        if(head) //check if there is still a head of the list then make it's prev our dummy node
        {
            head->prev = nullptr;
        }
        else //if this was the last element of the queue then our list is empty meaning head is already null
        {
            tail = nullptr; // make tail nullptr as well
        }
        
        delete temp; //free memory to avoid any leaks
        size--;
        return true;
    }
    //returns the oldest element
    int Front()
    {
        return isEmpty()? -1: head->value; //if IsEmpty is true then return -1 else return head->value
    }
    //returns the newest element
    int Rear()
    {
        return isEmpty() ? -1: tail->value; //if IsEmpty is true then return -1 else return tail->value
    }
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
private:
    int capacity; //allocated memory for the list
    int size; // current size of the linked list
    ListNode* head; //dummy node
    ListNode* tail; //dummy node
};

int main()
{
    int k = 6;
    MyCircularQueue* obj = new MyCircularQueue(k);
    obj->enQueue(2);
    obj->enQueue(1);
    obj->deQueue();
    obj->enQueue(3);
    obj->deQueue();
    obj->enQueue(3);
    obj->deQueue();

    obj->enQueue(3);
    obj->deQueue();
    
    //Test
    bool param_2 = obj->deQueue();
    bool param_1 = obj->enQueue(7);
 
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    std::cout<<"LeetCode 622. Design Circular Queue\n";
    std::cout<<"Enqueue : "<<param_1<<"\n";
    std::cout<<"Dequeue : "<<param_2<<"\n";
    std::cout<<"Front : "<<param_3<<"\n";
    std::cout<<"Rear : "<<param_4<<"\n";
    std::cout<<"IsEmpty : "<<param_5<<"\n";
    std::cout<<"IsFull : "<<param_6<<"\n";

}