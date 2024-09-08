//
// Created by 朱俊驰 on 9/8/24.
//
#include "../helper.h"
#include "../stack.h"
#include "../queue.h"

bool isValid(string s) {
    if(s.size()%2!=0){return false;}
    stack<char>store;
    for(char chara:s){
        if(chara == '('){
            store.push(')');
        }
        else if(chara == '['){
            store.push(']');
        }
        else if(chara == '{'){
            store.push('}');
        }
        else if(store.empty() || store.top()!=chara){
            return false;
        }
        else{
            store.pop();
        }

    }
    return store.empty();
}

string removeDuplicates(string s) {
    stack<char> store;
    for(char character:s){
        if(store.empty() || store.top()!=character){
            store.push(character);
        }
        else{
            store.pop();
        }
    }
    string answer;
    while (!store.empty()){
        answer+=store.top();
        store.pop();
    }
    reverse(answer.begin(),answer.end());
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


    auto* q1_queue_2 = new MyQueue();
    q1_queue_2->push(1);
    q1_queue_2->push(2);
    q1_queue_2->push(3);
    q1_queue_2->push(4);
    q1_queue_2->pop();
    q1_queue_2->push(5);
    q1_queue_2->pop();
    q1_queue_2->pop();
    q1_queue_2->pop();
    q1_queue_2->pop();

    auto* q2_stack = new MyStack();
    q2_stack->push(1);
    q2_stack->push(2);

    q2_stack->top();
    q2_stack->pop();
    q2_stack->pop();
    q2_stack->empty();

    string q4="abbaca";
    cout<<removeDuplicates(q4)<<endl;
    return 0;
}

