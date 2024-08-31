//
// Created by 朱俊驰 on 8/31/24.
//

#include <iostream>
#include "../linkedlist.h"
using namespace std;

void print_helper(ListNode *head){
    ListNode *cur = head;
    while(cur != nullptr){
        cout<< cur->val << ", ";
        cur = cur->next;
    }
    cout<<endl;
}

ListNode* removeElements(ListNode* head, int val) {
    while(head!= nullptr and head->val == val){
        ListNode* cur = head;
        head = head->next;
        if(cur->val == val){
            delete cur;
        }
    }

    ListNode* cur = head;
    while (cur!= nullptr and cur->next!= nullptr){
        if(cur->next->val == val){
            ListNode *target = cur->next;
            cur->next = target->next;
            delete target;
        }
        else{
            cur = cur->next;
        }
    }
    return head;
}

ListNode* removeElements_dummyHead_version(ListNode* head, int val) {
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* cur = dummy_head;
    while(cur->next!= nullptr){
        ListNode* target = cur->next;
        if(target->val == val){
            cur->next = target->next;
            delete target;
        } else{
            cur = cur->next;
        }
    }
    head = dummy_head->next;
    delete dummy_head;
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next_one;
    while(cur!= nullptr){
        next_one = cur->next;
        cur->next=pre;

        pre = cur;
        cur=next_one;
    }

    return pre;
}

int main(){
    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(5, node6);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* head = new ListNode(1, node1);

    print_helper(head);
    removeElements_dummyHead_version(head, 6);
    print_helper(head);

    MyLinkedList* my_list = new MyLinkedList(head);
    cout<<my_list->get(4)<<endl;

    my_list->addAtHead(100);
    my_list->printer();

    my_list->addAtTail(200);
    my_list->printer();

    my_list->addAtIndex(1,300);
    my_list->printer();

    my_list->deleteAtIndex(2);
    my_list->printer();

    cout<<"testcase : "<<endl;
//    ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex",
//     "addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
//    [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
    MyLinkedList* testcase1 =new MyLinkedList();
    testcase1->addAtHead(7);
    testcase1->addAtHead(2);
    testcase1->addAtHead(1);
    testcase1->addAtIndex(3,0);

    testcase1->deleteAtIndex(2);
    testcase1->addAtHead(6);
    testcase1->addAtTail(4);
    testcase1->printer();
    cout<<testcase1->get(4)<<endl;


}
