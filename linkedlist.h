//
// Created by 朱俊驰 on 8/30/24.
//

#ifndef LEECODE_LINKEDLIST_H
#define LEECODE_LINKEDLIST_H
#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x, ListNode *pointer):val(x),next(pointer){};

};

class MyLinkedList{
public:
    MyLinkedList():size(0), myhead(){};
    MyLinkedList(ListNode* head):size(0), myhead(head){};
    int get(int index){
        if(index>=size || index<0){
            return -1;
        }
        ListNode* cur = myhead;
        while(index>0){
            cur=cur->next;
            index-=1;
        }
        return cur->val;
    }

    void addAtHead(int val){
        ListNode* new_head = new ListNode(val);
        new_head->next = myhead;
        myhead = new_head;
        size+=1;
    }

    void addAtTail(int val) {
        if(size==0){
            addAtHead(val);
            return;
        }
        ListNode* new_tail = new ListNode(val);
        ListNode* cur = myhead;
        while(cur!= nullptr and cur->next!= nullptr){
            cur= cur->next;
        }
        cur->next = new_tail;
        size+=1;
    }

    void addAtIndex(int index, int val) {
        if(index>size || index<0){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        ListNode* new_node = new ListNode(val);
        ListNode* cur = myhead;
        while(index>1){
            cur=cur->next;
            index-=1;
        }
        new_node->next =cur->next;
        cur->next = new_node;
        size+=1;
    }

    void deleteAtIndex(int index) {
        if(index>=size || index<0){
            return;
        }
        if(index == 0 and size==1){
            delete myhead;
            size-=1;
            return;
        }

        if(index == 0 and size!=1){
            ListNode* node = myhead;
            myhead = myhead->next;
            delete node;
            size-=1;
            return;
        }

        ListNode* cur = myhead;
        while(index>1){
            cur=cur->next;
            index-=1;
        }
        cur->next = cur->next->next;
        size-=1;
    }

    void printer(){
        ListNode *cur = myhead;
        while(cur != nullptr){
            cout<< cur->val << ", ";
            cur = cur->next;
        }
        cout<<endl;
    }

private:
    size_t size;
    ListNode* myhead;
};
#endif //LEECODE_LINKEDLIST_H
