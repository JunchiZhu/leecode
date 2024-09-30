//
// Created by 朱俊驰 on 9/30/24.
//


#include "../helper.h"

vector<int> partitionLabels(string s) {
    int hash[26] = {0};
    for(int i=0;i<s.size();++i){
        hash[s[i]-'a'] = i;
    }
    int left = 0;
    int right = 0;
    vector<int> answer;
    for(int i=0;i<s.size();++i){
        right = max(hash[s[i]-'a'], right);
        if(right==i){
            answer.push_back(right-left+1);
            left=right+=1;
        }
    }
    return answer;
}


int monotoneIncreasingDigits(int n) {
    string n_str = to_string(n);
    int flag = n_str.size();
    for(int i=n_str.size()-1;i>0;i--){
        if(n_str[i]<n_str[i-1]){
            n_str[i-1]-=1;
            flag=i;
        }
    }
    for(int i=flag;i<n_str.size();++i){
        n_str[i]='9';
    }
    return stoi(n_str);
}

int main(){
//    string s = "ababcbacadefegdehijhklij";
//    vector_printer(partitionLabels(s));
    int n = 10;
    cout<<monotoneIncreasingDigits(n)<<endl;
    return 0;
}