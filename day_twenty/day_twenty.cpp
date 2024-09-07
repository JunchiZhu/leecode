//
// Created by 朱俊驰 on 9/6/24.
//

#include "../helper.h"
void remove_extract_space(string &s) {
    int slow=0,fast=0;
    // spaces before the string
    while(fast<s.size() && s[fast]==' '){
        fast+=1;
    }
    for(;fast<s.size();++fast){
        if(fast==0){
            s[slow]=s[fast];
            slow+=1;
        }
        else{
            if(s[fast-1]==' ' and s[fast]==s[fast-1]){
                continue;
            } else{
                s[slow]=s[fast];
                slow+=1;
            }
        }
    }
    if (s[slow-1]==' ') {
        s.resize(slow-1);
    } else{
        s.resize(slow);
    }
}

string reverseWords(string &s) {
    remove_extract_space(s);
    reverse(s.begin(),s.end());
    int start=0,end=0;
    for(int i=0;i<s.size();++i){
        if(s[i]==' ' or i==s.size()-1){
            end = i;
            if(end == s.size()-1){
                end=end+1;
            }
            reverse(s.begin()+start,s.begin()+end);
            start=i+1;
        }
    }
    return s;
}

// abcdefg -> fgabcde
// gfedcba

void reverse_last_k_characters(string &q2_input, int k){
    reverse(q2_input.begin(),q2_input.end());
    reverse(q2_input.begin(),q2_input.begin()+k);
    reverse(q2_input.begin()+k,q2_input.end());
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Debuggable getNext function to compute LPS array
void getNext(int* next, const string& s) {
    int j = 0;
    next[0] = 0;
    cout << "Initial LPS: " << next[0] << endl;

    for (int i = 1; i < s.size(); i++) {
        // Handle mismatch
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
            cout << "Mismatch at i = " << i << ", updating j to: " << j << endl;
        }
        // Handle match
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j; // Store the LPS value
        cout << "Updated LPS for i = " << i << " is: " << next[i] << endl;
    }
}

int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0; // Edge case when the needle is an empty string
    }

    vector<int> next(needle.size());
    getNext(&next[0], needle); // Precompute the LPS array

    int j = 0; // Pointer for needle
    for (int i = 0; i < haystack.size(); i++) {
        // Handle mismatch during search
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
            cout << "Mismatch in haystack at i = " << i << ", updating j to: " << j << endl;
        }
        // Handle match
        if (haystack[i] == needle[j]) {
            j++;
        }
        // If a complete match is found
        if (j == needle.size()) {
            cout << "Pattern found at index: " << (i - needle.size() + 1) << endl;
            return (i - needle.size() + 1);
        }
    }

    return -1; // No match found
}

int main() {
    string haystack = "ABABDABACDABABCABAB";
    string needle = "ABABCABAB";

    int result = strStr(haystack, needle);
    cout << "The pattern is found at index: " << result << endl;

    return 0;
}


//int main(){
//    string space_test="hello world to";
//    cout<<reverseWords(space_test)<<endl;
//
//    string testcase_q2;
//    int k;
//    cin>>k;
//    cin>>testcase_q2;
//    reverse_last_k_characters(testcase_q2, k);
//    cout<<testcase_q2<<endl;
//
//
//    return 0;
//}