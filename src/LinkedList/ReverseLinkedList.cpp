#include <iostream>

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public: 
    ListNode* reverseList(ListNode* head)
    {
        //Create Prev and current - Initially prev would be NULL
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr)
        {
            //Create a temp node to store our next before severing the link
            ListNode* tempNext;
            tempNext = curr->next; // storing current node's next in the temp
            curr->next = prev; //change current.next to prev
            //Update prev to curr and curr to next
            prev = curr;
            curr = tempNext; //Use the stored value
        }
        return prev;

    }

    void printList(ListNode* head)
    {
        ListNode* current = head;
        while(current)
        {
            std::cout<<current->val<<" -> ";
            current = current->next;
        }
        std::cout<<"nullptr"<<std::endl;
    }
};

int main()
{
    Solution solution;
    std::cout<<"Leetcode 206: Reverse a Linked List"<<std::endl;

    //Inputs
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout<<"Original Linked List : ";
    solution.printList(head);

    //Solution
    head = solution.reverseList(head);

    //Output
    std::cout<<"Reversed Linked List: ";
    solution.printList(head);

    //Delete the list
    while(head)
    {
        ListNode* temp;
        temp = head;
        head = head->next;
        delete temp;
    }

}

