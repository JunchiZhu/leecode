//
// Created by 朱俊驰 on 9/8/24.
//

#ifndef LEECODE_STACK_H
#define LEECODE_STACK_H
#include "helper.h"
// 1 2 3 4 1 2 3 -> 1
// 4 1 2 3 -> 1
// 4 -> 4
// 3
// 2
// 1
class MyStack {
public:
    MyStack()=default;
    queue<int>my_queue;

    void push(int x) {
        my_queue.push(x);
    }

    int pop() {
        int size =my_queue.size();
        size-=1;
        while(size--){
            int temp = my_queue.front();
            my_queue.pop();
            my_queue.push(temp);
        }
        int answer = my_queue.front();
        my_queue.pop();
        return answer;
    }

    int top() {
        int size =my_queue.size();
        size-=1;
        while(size--){
            int temp = my_queue.front();
            my_queue.pop();
            my_queue.push(temp);
        }
        int answer = my_queue.front();
        my_queue.pop();
        my_queue.push(answer);
        return answer;
    }

    bool empty() {
        if(my_queue.empty()){
            return true;
        }
        return false;
    }
};

#endif //LEECODE_STACK_H
