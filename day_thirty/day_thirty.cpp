//
// Created by 朱俊驰 on 9/18/24.
//

#include "../helper.h"
using namespace std;

//vector<vector<int>> combine(int n, int k) {
//    vector<vector<int>> answer;
//    for(int i=1;i<n+1;++i){
//        for(int j=i+1;j<n+1;++j){
//            vector<int>sub_store;
//            sub_store.push_back(i);
//            sub_store.push_back(j);
//            answer.push_back(sub_store);
//        }
//    }
//    return answer;
//}

void backtracking(int n, int k, vector<vector<int>> &answer, vector<int> &path, int start_index){
    if(path.size()==k){
        answer.push_back(path);
        return;
    }
    for(int i=start_index;i<n+1;++i){
        path.push_back(i);
        backtracking(n,k,answer,path,i+1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> answer;
    vector<int> path;
    backtracking(n,k,answer,path,1);
    return answer;
}

void backtracking3(int k, int target_sum, int sum,int start_index, vector<vector<int>>&answer, vector<int>&path){
    if(sum>target_sum){
        return;
    }
    if(sum==target_sum){
        answer.push_back(path);
        return;
    }
    for(int i=start_index;i<10;++i){
        sum+=i;
        path.push_back(i);
        backtracking3(k,target_sum,sum,i+1,answer,path);
        sum-=i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>answer;
    vector<int>path;
    int sum=0;
    backtracking3(k,n,sum,1,answer,path);
    return answer;
}


void backtracking2(vector<int>& candidates, int target, int sum, int startindex, vector<vector<int>> &answer, vector<int> &path) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        answer.push_back(path);
        return;
    }
    for (int i = startindex; i < candidates.size(); ++i) {
        // 跳过重复元素
        if (i > startindex && candidates[i] == candidates[i - 1]) {
            continue;
        }
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking2(candidates, target, sum, i + 1, answer, path);  // i + 1 保证每个元素只能用一次
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  // 排序用于去重
    vector<vector<int>> answer;
    vector<int> path;
    int sum = 0;
    backtracking2(candidates, target, sum, 0, answer, path);
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

vector<string> result;
string s;
void backtracking(const string& digits, int index) {
    if (index == digits.size()) {
        result.push_back(s);
        return;
    }
    int digit = digits[index] - '0';        // 将index指向的数字转为int
    string letters = letterMap[digit];      // 取数字对应的字符集
    for (int i = 0; i < letters.size(); i++) {
        s.push_back(letters[i]);            // 处理
        backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
        s.pop_back();                       // 回溯
    }
}
vector<string> letterCombinations(string digits) {
    s.clear();
    result.clear();
    if (digits.size() == 0) {
        return result;
    }
    backtracking(digits, 0);
    return result;
}
//void backtracking(string &digits, vector<string> &answer, string &s, int index){
//    if(index == digits.size()){
//        answer.push_back(s);
//        return;
//    }
//    for(int i=0;i<digits.size();++i){
//
//    }
//}
//
//vector<string> letterCombinations(string digits) {
//    vector<string> answer;
//    string s;
//    backtracking(digits, answer, s,0);
//    return answer;
//
//}

int main() {
    vector<vector<int>> q1_result = combine(4, 2);
    matrix_printer(q1_result);

    vector<vector<int>> q2_result = combinationSum3(3,7);
    vector<int> q3_input = {1,2,6,1,5};
    vector<vector<int>> q3_result = combinationSum2(q3_input, 8);
    string digits="23";
    vector<string> str = letterCombinations(digits);
}