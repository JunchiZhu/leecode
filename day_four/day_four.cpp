//
// Created by 朱俊驰 on 7/6/24.
//
#include <iostream>
#include <vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int value, ListNode* point = nullptr):val(value),next(point){}
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(ListNode *&head) {
    while(head!= nullptr){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* cur = dummy;
    while(cur->next!= nullptr and cur->next->next != nullptr){
        ListNode* temp1 = cur->next;
        ListNode* temp2 = cur->next->next;
        ListNode* temp3 = cur->next->next->next;
        cur->next=temp2;
        temp2->next=temp1;
        temp1->next=temp3;

        cur = cur->next->next;
    }
    ListNode* answer = dummy->next;
    delete dummy;
    return answer;
}

//  1,2,3,4
//
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow_prev = dummy;
    while(n>0){
        fast = fast->next;
        n-=1;
    }
    while(fast->next != nullptr){
        slow_prev = slow_prev->next;
        fast = fast->next;
    }
    ListNode* target = slow_prev->next;
    slow_prev->next = target->next;
    delete target;

    return dummy->next;

}
// 4 1 8 4 5  5 0 1 8 4 5
// 5 0 1 8 4 5  4 1 8 4 5

ListNode *getIntersectionNode_version_one(ListNode *headA, ListNode *headB) {
    if(headA==nullptr || headB == nullptr){
        return nullptr;
    }
    ListNode* cur_A = headA;
    ListNode* cur_B = headB;
    int a_len=0, b_len=0;
    int diff_len = 0;
    while(cur_A->next != nullptr){
        a_len+=1;
        cur_A = cur_A->next;
    }
    while(cur_B->next != nullptr){
        b_len+=1;
        cur_B = cur_B->next;
    }
    cur_A=headA;
    cur_B=headB;
    if(a_len>b_len){
        diff_len=a_len-b_len;
        while (diff_len>0){
            cur_A=cur_A->next;
            diff_len-=1;
        }
    } else{
        diff_len=b_len-a_len;
        while (diff_len>0){
            cur_B=cur_B->next;
            diff_len-=1;
        }
    }

    while(cur_A != nullptr and cur_B != nullptr){
        if(cur_A==cur_B){
            return cur_A;
        }
        cur_A=cur_A->next;
        cur_B=cur_B->next;
    }
    return nullptr;
}

ListNode *getIntersectionNode_version_two(ListNode *headA, ListNode *headB) {
    if(headA==nullptr || headB == nullptr){
        return nullptr;
    }
    ListNode* cur_A=headA;
    ListNode* cur_B=headB;
    while (cur_A != cur_B){
        if(cur_A== nullptr){
            cur_A = headB;
        } else{
            cur_A= cur_A->next;
        }

        if(cur_B== nullptr){
            cur_B = headA;
        }else{
            cur_B= cur_B->next;
        }
    }
    return cur_A;
}

ListNode *detectCycle(ListNode *head) {
    if(head == nullptr){
        return nullptr;
    }
    ListNode* fast=head;
    ListNode* slow=head;
    while (fast != nullptr and fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            ListNode* start=head;
            ListNode* meet_point=slow;
            while(start!=meet_point){
                start=start->next;
                meet_point=meet_point->next;
            }
            return meet_point;
        }
    }
    return nullptr;
}

int main() {
    // Test case for swapPairs
    ListNode* q1_head = new ListNode(1);
    q1_head->next = new ListNode(2);
    q1_head->next->next = new ListNode(3);
    q1_head->next->next->next = new ListNode(4);

    cout << "Original q1 List: ";
    printList(q1_head);

    ListNode* q1_answer = swapPairs(q1_head);
    cout << "Answer: q1 List: ";
    printList(q1_answer);

    deleteList(q1_answer);  // Properly delete the swapped list

    // Test case for removeNthFromEnd
    ListNode* q2_head = new ListNode(1);
    q2_head->next = new ListNode(2);
    q2_head->next->next = new ListNode(3);
    q2_head->next->next->next = new ListNode(4);
    q2_head->next->next->next->next = new ListNode(5);

    cout << "Original q2 List: ";
    printList(q2_head);

    q2_head = removeNthFromEnd(q2_head, 2);
    cout << "After removing 2nd from end, q2 List: ";
    printList(q2_head);

    deleteList(q2_head);  // Properly delete the list after removal

    // Test case for getIntersectionNode_version_two
    ListNode *common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode *headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    ListNode *headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode *intersectionNode = getIntersectionNode_version_two(headA, headB);
    if (intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    deleteList(headA);
    deleteList(headB);

    return 0;
}