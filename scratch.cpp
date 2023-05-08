#include <iostream>
#include <vector>
#include <forward_list>
#include <list>


using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *func(){
    ListNode *head;
    head = new ListNode(9);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    return head;
}

int main()
{
    ListNode *head = func();

    return 0;
}