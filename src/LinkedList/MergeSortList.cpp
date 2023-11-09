#include<iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        //edge cases before traversing both list
        if(l1 == nullptr)
        {
            return l2;
        }

        if (l2 == nullptr)
        {
            return l1;
        }
        if(l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        // Traversing lists
        ListNode* dummy = new ListNode(); //empty list node to start with
        ListNode* curr = dummy; // This is the head, we attach everything to this

        while(l1 != nullptr && l2 != nullptr) // While both list exists
        {
            if (l1->val < l2->val)
            {
                curr->next = l1; // Add the l1 element to output
                l1 = l1->next; // Increment List 1
            }
            else //l2 >= l1 
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next; // Increment the curr ptr
        }

        //edge cases after traversing both lists
        //this is for when one of the list becomes empty & the
        //while loop breaks
        if(l1 == nullptr)
        {
            curr->next = l2;
        }

        if (l2 == nullptr)
        {
            curr->next = l1;
        }
    
        return dummy->next;


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
    std::cout<<"Leetcode 21: Merge Two Sorted Lists"<<std::endl;

    //List 1
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    //List 2
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    std::cout<<"List 1 : ";
    solution.printList(l1);
    std::cout<<"List 2 : ";
    solution.printList(l2);
    
    ListNode* output;
    output = solution.mergeList(l1,l2);

    std::cout<<"Merged List: ";
    solution.printList(output);


    //Delete the list
    while(output)
    {
        ListNode* temp;
        temp = output;
        output = output->next;
        delete temp;
    }

}