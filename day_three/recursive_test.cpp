//
// Created by 朱俊驰 on 7/5/24.
//
#include <iostream>
#include "../linkedlist.h"



class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Test cases
void testReverseList() {
    Solution solution;

    // Test case 1: Empty list
    ListNode* head1 = nullptr;
    ListNode* result1 = solution.reverseList(head1);
    std::cout << "Test Case 1: ";
    printList(result1);  // Expected output: (empty)

    // Test case 2: Single node list
    ListNode* head2 = new ListNode(1);
    ListNode* result2 = solution.reverseList(head2);
    std::cout << "Test Case 2: ";
    printList(result2);  // Expected output: 1

    // Test case 3: Multiple nodes list
    std::vector<int> vals3 = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(vals3);
    ListNode* result3 = solution.reverseList(head3);
    std::cout << "Test Case 3: ";
    printList(result3);  // Expected output: 5 4 3 2 1

    // Test case 4: List with repeated values
    std::vector<int> vals4 = {1, 1, 2, 3, 3};
    ListNode* head4 = createList(vals4);
    ListNode* result4 = solution.reverseList(head4);
    std::cout << "Test Case 4: ";
    printList(result4);  // Expected output: 3 3 2 1 1
}

int main() {
    testReverseList();
    return 0;
}
