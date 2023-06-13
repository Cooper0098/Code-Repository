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


