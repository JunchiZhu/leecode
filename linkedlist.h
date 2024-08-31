//
// Created by 朱俊驰 on 8/30/24.
//

#ifndef LEECODE_LINKEDLIST_H
#define LEECODE_LINKEDLIST_H
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value, ListNode *node = nullptr) : val(value), next(node) {}
    ListNode() : val(0), next(nullptr) {}
};

#endif //LEECODE_LINKEDLIST_H
