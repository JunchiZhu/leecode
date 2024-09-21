//
// Created by 朱俊驰 on 9/18/24.
//

#include "../helper.h"
using namespace std;
void backtrack(vector<vector<int>> &answer, vector<int> &path, vector<int>& candidates, int target,int sum, int start_index){
    if(sum>target){
        return;
    }
    if(sum==target){
        answer.push_back(path);
        return;
    }
    for(int i=start_index;i<candidates.size();++i){
        sum+= candidates[i];
        path.push_back(candidates[i]);
        backtrack(answer,path,candidates,target,sum,i);
        path.pop_back();
        sum-= candidates[i];
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> path;
    int sum=0;
    backtrack(answer,path,candidates,target,sum,0);
    return answer;
}

void backtrack1(vector<vector<int>> &answer, vector<int> &path, int n, int k, int start_index ){
    if(path.size()==k){
        answer.push_back(path);
        return;
    }
    for(int i=start_index;i<=n-(k-path.size())+1;++i){
        path.push_back(i);
        backtrack1(answer,path,n,k,i+1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> answer;
    vector<int> path;
    backtrack1(answer,path,n,k,1);
    return answer;
}


void backtrack2(vector<vector<int>> &answer, vector<int> &path, vector<int>& candidates, int target,int sum, int start_index){
    if(sum>target){
        return;
    }
    if(sum==target){
        answer.push_back(path);
        return;
    }
    for(int i=start_index;i<candidates.size()&& sum+candidates[i]<=target;++i){
        if(start_index<i and candidates[i-1]==candidates[i]){
            continue;
        }
        sum+= candidates[i];
        path.push_back(candidates[i]);
        backtrack2(answer,path,candidates,target,sum,i+1);
        sum-= candidates[i];
        path.pop_back();

    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> answer;
    vector<int> path;
    int sum=0;
    backtrack2(answer,path,candidates,target, sum,0);
    return answer;
}



void backtrack3(vector<vector<int>> &answer, vector<int> &path, int n, int k, int start_index, int sum){
    if(sum>n){
        return;
    }
    if(path.size()==k and sum==n){
        answer.push_back(path);
        return;
    }
    for(int i=start_index;i<=9;++i){
        path.push_back(i);
        sum+=i;
        backtrack3(answer,path,n,k,i+1,sum);
        sum-=i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> answer;
    vector<int> path;
    int sum=0;
    backtrack3(answer,path,n,k,1, sum);
    return answer;
}

const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
};

void letter_trackback(vector<string>&answer, string &combine, string &digits, int index) {
    if(digits.size()==index){
        answer.push_back(combine);
        return;
    }
    int digit = digits[index]-'0';
    string letters = letterMap[digit];
    for(char letter : letters){
        combine.push_back(letter);
        letter_trackback(answer,combine,digits,index+1);
        combine.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string>answer;
    string combine;
    if(digits.empty()){
        return answer;
    }
    letter_trackback(answer,combine,digits,0);
    return answer;
}

bool isPalindrome(const string& text, int start, int end){
    while(start<end){
        if(text[start]!=text[end]){
            return false;
        }
        start+=1;
        end-=1;
    }
    return true;
}

void backtrack_text(string &s, vector<vector<string>>&answer, vector<string>&subs, int start){
    if(start==s.size()){
        answer.push_back(subs);
        return;
    }
    for(int end=start; end < s.size(); ++end){
        if(isPalindrome(s, start, end)){
            subs.push_back(s.substr(start,end-start+1));
        } else{
            continue;
        }
        backtrack_text(s,answer,subs,end+1);
        subs.pop_back();
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>>answer;
    vector<string>subs;
    backtrack_text(s,answer,subs, 0);
    return answer;
}

int main() {
    vector<vector<int>> q1_result = combine(4, 2);
    matrix_printer(q1_result);

    vector<vector<int>> q2_result = combinationSum3(3,7);

    vector<int> q3_input = {1,2,6,1,5};
    vector<vector<int>> q3_result = combinationSum2(q3_input, 8);

    string digits = "234";
    vector<string> q5_answer = letterCombinations(digits);
    vector_printer(q5_answer);

    vector<vector<string>> q6_anwers = partition("aab");
    matrix_printer(q6_anwers);
}