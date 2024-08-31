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


class MyLinkedList {
public:
    MyLinkedList(): head(nullptr),size(0) {}

    int get(int index) {
        if(index>size-1 || index<0){
            return -1;
        }
        ListNode* cur = head;
        int tracker=0;
        while (cur!= nullptr){
            if(tracker==index){
                return cur->val;
            }
            tracker+=1;
            cur = cur->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = head;
        head = new_node;
        size+=1;
    }
//    head -> [1] -> [2] -> [3] -> nullptr

    void addAtTail(int val) {
        ListNode* new_node = new ListNode(val);
        if(head == nullptr){
            head=new_node;
            size+=1;
            return;
        }
        else {
            ListNode *cur = head;
            while (cur->next != nullptr) {
                cur=cur->next;
            }
            cur->next=new_node;
            size+=1;
        }
    }

    void addAtIndex(int index, int val) {
        if(index<0){
            index = 0;
        }
        if(index>size){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        ListNode* new_node = new ListNode(val);
        ListNode* cur = head;
        while(index>1){
            cur=cur->next;
            index-=1;
        }

        new_node->next = cur->next;
        cur->next = new_node;
        size+=1;
    }

    void deleteAtIndex(int index) {
        if(index<0){
            index = 0;
        }
        if(index>=size){
            return;
        }
        if(index==0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size-=1;
            return;
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(index>1){ // 1 2 3  index = 2
            cur=cur->next;
            prev=prev->next;
            index-=1;
        }
        prev->next = cur->next;
        delete cur;
        size-=1;
    }
private:
    ListNode* head;
    int size;
};
//pre cur
//     1 2 3
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