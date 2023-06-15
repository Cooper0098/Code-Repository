#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // 反转链表

struct Node // 链表节点结构体
{
    int val;
    Node *next;
    Node(int _val):val(_val),next(nullptr){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr){}  
        ListNode(int x) : val(x), next(nullptr){}  
        ListNode(int x, ListNode *next) : val(x), next(next){}
                                                               
    };

public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        auto p = head, q = head->next;
        while (q != nullptr)
        {
            auto r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head->next = nullptr;
        return p;
    }
};

int main()
{

}


