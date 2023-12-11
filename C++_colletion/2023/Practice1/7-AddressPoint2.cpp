#include <iostream>
#include <vector>

using namespace std; // 指针链表,结构体

struct Node
{
    int val;
    Node *next;
    Node(int _val): val(_val),next(nullptr){}
};


int main()
{
    Node *p = new Node(1);
    Node *q = new Node(2);
    Node *o = new Node(3);

    p->next = q;
    q->next = o;

    Node *head = p;

    //添加节点
    Node *u = new Node(4);
    u->next = head;
    head = u;



    //删除节点
    //head->next = head->next->next;

    //遍历节点
    for (Node *i = head; i;i = i->next)
    {
        cout << i ->val <<endl;
    }

    return 0;
}
