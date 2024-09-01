//
// Created by 朱俊驰 on 8/31/24.
//

#include "iostream"
#include "../linkedlist.h"
using namespace std;

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* cur = dummy_head;
    while(cur->next!= nullptr and cur->next->next!= nullptr ){
        ListNode* first_next = cur->next;
        ListNode* second_next = cur->next->next;
        ListNode* next_iter = second_next->next;

        cur->next = second_next;
        second_next->next=first_next;
        first_next->next = next_iter;

        cur = cur->next->next;
    }
    ListNode* answer = dummy_head->next;
    delete dummy_head;
    return answer;
}

//ListNode* removeNthFromEnd(ListNode* head, int n) {
//    ListNode* dummy_head = new ListNode();
//    dummy_head->next = head;
//    ListNode* fast = dummy_head;
//    ListNode* slow = dummy_head;
//    while(n>=0 and fast != nullptr){
//        fast = fast->next;
//        n-=1;
//    }
//    while(fast!= nullptr){
//        fast=fast->next;
//        slow=slow->next;
//    }
//    slow->next = slow->next->next;
//
//    return dummy_head->next;
//}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(n>0 and fast != nullptr){
        fast = fast->next;
        n-=1;
    }
    if(fast == nullptr){
        head = slow->next;
        delete slow;
        return head;
    }

    while(fast->next!= nullptr){
        fast=fast->next;
        slow=slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int A_len = 0;
    int B_len = 0;
    ListNode* cur_a = headA;
    ListNode* cur_b = headB;
    while(cur_a!= nullptr){
        A_len+=1;
        cur_a = cur_a->next;
    }
    while(cur_b!= nullptr){
        B_len+=1;
        cur_b = cur_b->next;
    }
    int len_diff = abs(A_len-B_len);
    cur_a = headA;
    cur_b = headB;
    if(A_len>=B_len){
        while (len_diff--){
            cur_a=cur_a->next;
        }
    } else {
        while (len_diff--){
            len_diff-=1;
            cur_b=cur_b->next;
        }
    }

    while(cur_a!= nullptr and cur_b!= nullptr){
        if(cur_a==cur_b){
            return cur_a;
        }
        cur_a=cur_a->next;
        cur_b=cur_b->next;
    }
    return nullptr;
}

ListNode *detectCycle(ListNode *head) {
    ListNode* fast_node = head;
    ListNode* slow_node = head;
    ListNode* index1 = head;
    ListNode* index2 = new ListNode();
    while(fast_node!= nullptr and fast_node->next!= nullptr){
        slow_node=slow_node->next;
        fast_node=fast_node->next->next;
        if(fast_node == slow_node){
            index2 = fast_node;
            while (index2 != index1){
                index2=index2->next;
                index1=index1->next;
            }
            return index2;
        }
    }
    return nullptr;
}

int main(){
    ListNode* node3 = new ListNode(4, nullptr);
    ListNode* node2 = new ListNode(3, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* head = new ListNode(1, node1);
//    node3->next=node1;
    cout<<detectCycle(head)->val;

    return 0;
}