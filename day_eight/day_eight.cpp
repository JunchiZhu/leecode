//
// Created by 朱俊驰 on 7/10/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverseString(vector<char>& s) {
    int left=0;
    int right= s.size()-1;
    for(int i=0;i<s.size()/2;++i){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left+=1;
        right-=1;
    }
}


void vector_printer(const vector<char>& temp){
    for(auto ele:temp){
        cout<< ele << ", ";
    }
}

void partial_reverse(string& temp, int start, int end) {
    int left = start;
    int right = end;

    while (left < right) {
        std::swap(temp[left], temp[right]);
        left += 1;
        right -= 1;
    }
}

string reverseStr(string &s, int k) {
    for(int i=0;i<s.size();i+=2*k){
        int end = min(i+k-1,  static_cast<int>(s.size()-1));
        partial_reverse(s, i, end);

    }
    return s;
}

void question_three(string& input){
    int number_counter = 0;
    for(char i : input){
        if(i-'a'<0){
            number_counter+=1;
        }
    }
    int j = input.size()-1;

    int expand_size = j+1+number_counter*5;
    int i=expand_size-1;
    input.resize(expand_size);

    while(j>=0){
        if(input[j]-'a'>=0){
            input[i] = input[j];
            i--;
        } else{
            input[i--]='r';
            input[i--]='e';
            input[i--]='b';
            input[i--]='m';
            input[i--]='u';
            input[i--]='n';
        }
        j--;
    }
    cout<<input<<endl;
}



int main(){
    vector<char> q1_input = {'h','e','l','l','o'};
    reverseString(q1_input);
    vector_printer(q1_input);
    cout<<endl;

    string q2_input_1 = "abcdefg";
    int q2_input_2 = 2;
    cout<<reverseStr(q2_input_1, q2_input_2)<<endl;

    string q3_input = "a5b";
    question_three(q3_input);
}