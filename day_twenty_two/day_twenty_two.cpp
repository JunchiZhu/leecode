//
// Created by 朱俊驰 on 9/8/24.
//

#include "../helper.h"
int evalRPN(vector<string>& tokens) {
    stack<long long> store;
    for(auto& character: tokens){
        if(character=="/" || character=="*"|| character=="+"|| character=="-"){
            long long num1 = store.top();
            store.pop();
            long long num2 = store.top();
            store.pop();
            if(character == "/"){
                store.push(((num2/num1)));
            }
            else if(character == "+"){
                store.push(((num2+num1)));
            }
            else if(character == "-"){
                store.push(((num2-num1)));
            }
            else if(character == "*"){
                store.push(((num2*num1)));
            }
        }
        else{
            store.push(stoll(character));
        }
    }
    long long answer = store.top();
    store.pop();
    return answer;
}

//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//
//}

int main(){
    vector<string> q1_testcase_input1{"4","13","5","/","+"};
    cout<<evalRPN(q1_testcase_input1)<<endl;
    return 0;
}