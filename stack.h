//
// Created by 朱俊驰 on 9/8/24.
//

#ifndef LEECODE_STACK_H
#define LEECODE_STACK_H
#include "helper.h"

class MyStack {
public:
    MyStack() = default;
    queue<int> my_queue;

    //
    void push(int x) {
        my_queue.push(x);
    }

    int pop() {
        int size = my_queue.size()-1;
        while (size--){
            int value = my_queue.front();
            my_queue.pop();
            my_queue.push(value);
        }

        int value = my_queue.front();
        my_queue.pop();
        return value;
    }

    int top() {
        int size = my_queue.size()-1;
        while (size--){
            int value = my_queue.front();
            my_queue.push(value);
            my_queue.pop();
        }

        int value = my_queue.front();
        my_queue.push(value);
        my_queue.pop();
        return value;

    }

    bool empty() {
        return my_queue.empty();
    }
};

#endif //LEECODE_STACK_H
