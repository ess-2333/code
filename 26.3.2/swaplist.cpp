#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

ListNode* swaplinkedNode(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* newhead = head->next; //反转后头节点
    ListNode* nexthead = head->next->next;//保存节点
    head->next->next = head;
    head->next = swaplinkedNode(nexthead);
    return newhead;
}

void vist(ListNode* head){
    if(head == nullptr) return;
    cout << head->val;
    ListNode* cur = head-> next;
    while(cur != nullptr){
        cout << "->" << cur->val;
        cur = cur->next;
    }
}

int main(){
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    cout << "swap before: ";
    vist(&n1);
    cout << endl;

    ListNode* head = swaplinkedNode(&n1);

    cout << "swap after: ";
    vist(head);
    cout << endl;

    return 0;
}