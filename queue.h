//
// Created by 朱俊驰 on 9/8/24.
//

#ifndef LEECODE_QUEUE_H
#define LEECODE_QUEUE_H
#include "helper.h"

class MyQueue {
public:
    MyQueue() = default;
    stack<int> in_stack;
    stack<int> out_stack;
    //queue:  1 2
    //stack1: 2 1
    //stack2: 1 2

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        int temp_value = peek();
        out_stack.pop();
        return temp_value;
    }

    int peek() {
        if(out_stack.empty()){
            while(!in_stack.empty()){
                int value = in_stack.top();
                in_stack.pop();
                out_stack.push(value);
            }
        }

        return out_stack.top();
    }

    bool empty() {
        if(in_stack.empty() and out_stack.empty()){
            return true;
        }
        return false;
    }
};



#endif //LEECODE_QUEUE_H
