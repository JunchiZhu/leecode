//
// Created by 朱俊驰 on 9/6/24.
//

#include "../helper.h"
void reverseString(vector<char>& s) {
    int left= 0;
    int right = s.size()-1;
    while (left<right){
        char temp = s[right];
        s[right] = s[left];
        s[left] = temp;

        right-=1;
        left+=1;
    }
}

string reverseStr(string s, int k) {
    for(int i=0;i<s.size();i+=2*k){
        if(i+k<=s.size()){
            reverse(s.begin()+i,s.begin()+i+k);
        } else{
            reverse(s.begin()+i,s.end());
        }
    }
    return s;
}

void replace_number(string input){
    int counter = 0;
    for(char i : input){
        if(isdigit(i)){
            counter+=1;
        }
    }
    int left = input.size()-1;
    input.resize(input.size()+counter*5);
    int right= input.size()-1;
    while(left>=0){
        if(isalpha(input[left])){
            input[right] = input[left];
            right-=1;
        }//number
        else if(!isalpha(input[left])){
            input[right--] = 'r';
            input[right--] = 'e';
            input[right--] = 'b';
            input[right--] = 'm';
            input[right--] = 'u';
            input[right--] = 'n';
        }
        left-=1;
    }
    cout<<input<<endl;

}


int main(){
    string q1_testcase1 = "abcdefg";
    int q1_testcase1_k = 2;
    cout<<reverseStr(q1_testcase1, q1_testcase1_k)<<endl;

    string input;
    cin>>input;
    replace_number(input);
}
