//
// Created by 朱俊驰 on 7/12/24.
//

#include<iostream>
#include<vector>
#include <stack>
#include <queue>
#include <string>
#include "../stack.h"
#include "../queue.h"
using namespace std;
//
//
//class MyQueue {
//public:
//    stack<int> inStack;
//    stack<int> outStack;
//
//    MyQueue() = default;
//
//
//    void push(int x) {
//        inStack.push(x);
//    }
//
//    int pop() {
//        if(outStack.empty()){
//            while (!inStack.empty()){
//                int value = inStack.top();
//                inStack.pop();
//                outStack.push(value);
//            }
//        }
//        int ans = outStack.top();
//        outStack.pop();
//        return ans;
//    }
//
//    int peek() {
//        int value = pop();
//        outStack.push(value);
//        return value;
//    }
//
//    bool empty() const {
//        if(inStack.empty() && outStack.empty()){
//            return true;
//        }
//        return false;
//    }
//};
//
//class MyStack {
//public:
//    queue<int> inQueue;
//    queue<int> outQueue;
//    MyStack() = default;
//
//    void push(int x) {
//        inQueue.push(x);
//    }
//
//    int pop() {
//        int size = inQueue.size();
//        while (size>1){
//            int temp = inQueue.front();
//            inQueue.pop();
//            outQueue.push(temp);
//            size-=1;
//        }
//        int ans = inQueue.front();
//        inQueue.pop();
//
//        inQueue = outQueue;
////        while (!outQueue.empty()) { // 清空que2
////            outQueue.pop();
////        }
//
//        return ans;
//    }
//
//    int top() {
//        return inQueue.back();
//    }
//
//    bool empty() {
//        if(inQueue.empty()){
//            return true;
//        }
//        return false;
//    }
//};

bool isValid(string s) {
    stack<char> store1;
    for(char i : s){
        if(i=='('){
            store1.push(')');
        }
        else if(i=='['){
            store1.push(']');
        }
        else if(i=='{'){
            store1.push('}');
        }
        else if(store1.empty() || store1.top()!=i){
            return false;
        }
        else{
            store1.pop();
        }
    }

    return store1.empty();
}

string removeDuplicates(string s) {
    stack<int> store;
    for(char i : s){
        if(store.empty() || store.top() != i){
            store.push(i);
        } else{
            store.pop();
        }
    }
    string answer;
    while(!store.empty()){
        char temp = store.top();
        store.pop();
        answer+=temp;
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
    auto* q1_queue = new MyQueue();
    q1_queue->push(1);
    q1_queue->push(2);
    q1_queue->push(3);
    while(!q1_queue->empty()) {
        cout << q1_queue->peek() << ", "<<endl;
        q1_queue->pop();
    }

    auto* q2_stack= new MyStack();
    q2_stack->push(1);
    q2_stack->push(2);
    cout<<q2_stack->top()<<endl;
    cout<<q2_stack->pop()<<endl;
    cout<<q2_stack->pop()<<endl;

    auto q3_input = "]";
    cout<<isValid(q3_input)<<endl;


    auto q4_input = "aaabbcc";
    cout<<removeDuplicates(q4_input)<<endl;

}
