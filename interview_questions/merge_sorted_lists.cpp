#include <iostream>
#include <list>


/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == nullptr | list2 == nullptr)
    {
        return nullptr;
    }

    struct ListNode* current1 = list1;
    struct ListNode* current2 = list2;
    struct ListNode* firstNode = nullptr;
    
    while(true)
    {

        if(current1->val < current2->val)
        {
            while(current1->val < current2->val && current1->next != nullptr)
            {
                ++current1;
            }

            temp = current1->next;
            current1->next = current2;
            current1 = temp;
            ++current2;
        }
        else if(current1->val > current2->val)
        {
            while(current1->val > current2->val && current2->next != nullptr)
            {
                ++current2;
            }

            if(current2->next == nullptr)
            {
                current2->next = current1;
                return ;
            }
            else
            {
                temp = current2->next;
                current2->next = current1;
                current2 = temp;
            }
        }
    }

    return firstNode;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 == nullptr && list2 == nullptr)
    {
        return nullptr;
    }
    if(list1 == nullptr && list2 != nullptr)
    {
        return list2;
    }
    if(list1 != nullptr && list2 == nullptr)
    {
        return list1;
    }

    struct ListNode* current1 = list1;
    struct ListNode* current2 = list2;
    struct ListNode* firstNode = nullptr;
    
    if(current1->val <= current2->val)
    {
        firstNode = current1;
    }
    else
    {
        firstNode = current2;
    }

    while(true)
    {
        struct ListNode* temp = nullptr;

        if(current1->val <= current2->val)
        {
            temp = current1->next;
            current1->next = current2;
            current1 = temp;
            if(current1->next == nullptr)
            {
               break;
            }
        }
        else
        {
            temp = current2->next;
            current2->next = current1;
            current2 = temp;
            if(current2->next == nullptr)
            {
               break;
            }
        }
    }

    return firstNode;
}