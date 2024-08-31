//
// Created by 朱俊驰 on 7/5/24.
//
# include <iostream>
#include "../linkedlist.h"
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    while(head!= nullptr and head->val == val){
        ListNode* temp_node = head;
        head = head->next;
        delete temp_node;
    }

    if (head == nullptr){
        return nullptr;
    }

    ListNode* cur = head->next;
    ListNode* prev = head;
    while(cur != nullptr){
        if(cur->val == val){
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else{
            prev = prev->next;
            cur = cur->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while(cur != nullptr){
        ListNode* temp = cur->next;
        cur->next = prev;

        prev=cur;
        cur=temp;
    }
    return prev;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(6);
    head1->next->next->next = new ListNode(3);

    cout << "Original List 1: ";
    printList(head1);

    head1 = removeElements(head1, 6);
    cout << "Modified List 1 (remove 6): ";
    printList(head1);
    delete head1;

    MyLinkedList myLinkedList = *new MyLinkedList();
    myLinkedList.addAtHead(2);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList.get(1);              // 返回 2
    myLinkedList.deleteAtIndex(0);    // 现在，链表变为 1->3
    myLinkedList.get(0);


    return 0;
}