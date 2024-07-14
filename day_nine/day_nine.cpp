//
// Created by 朱俊驰 on 7/12/24.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void remove_extra_space(string &temp){
    int slow = 0;
    int fast = 0;
    while (fast<temp.size() && temp[fast]==' '){
        fast+=1;
    }

    while(fast<temp.size()){
        if(temp[fast] !=' '){ // 当前所读第一个字符不是空格
            temp[slow] = temp[fast];
            slow+=1;
            fast+=1;
        } else{ // 当前所读字符是空格
            while(fast<temp.size() && temp[fast] == ' '){
                fast+=1;
            }
            if(fast<temp.size()){
                temp[slow] = ' ';
                slow+=1;
            }
        }
    }
    temp.resize(slow);
}

void reverse_word(string &temp, int start, int end){
    while(start<end){
        char tem_char = temp[start];
        temp[start] = temp[end];
        temp[end] = tem_char;
        start+=1;
        end-=1;
    }
}


string reverseWords(string &s) {
    remove_extra_space(s);
    reverse_word(s, 0, s.size()-1);
    int start = 0;
    for(int i=0;i<s.size()+1;++i){
        if(s[i] == ' ' || i==s.size()-1){
            reverse_word(s,start, i-1);
            start = i+1;
        }

    }

    return s;
}

int main(){
    string q1_input = "the sky is blue";
    reverseWords(q1_input);
    cout<<q1_input<<endl;

    int q2_num;
    string q2_input;
    cin>>q2_input>>q2_num;
    reverse( q2_input.begin(),q2_input.end());
    reverse( q2_input.begin(),q2_input.begin()+q2_num);
    reverse( q2_input.begin()+q2_num,q2_input.end());


//  "blue is sky the"
}