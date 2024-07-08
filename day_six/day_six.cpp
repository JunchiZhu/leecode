//
// Created by 朱俊驰 on 7/8/24.
//
#include <iostream>
#include <numeric>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }
    vector<int> store(26, 0);
    for(char i : s){
        int index = int(i)-int('a');
        store[index] += 1;
    }
    for(char i : t){
        int index = int(i)-int('a');
        if(store[index] != 0){
            store[index] -= 1;
        }
    }
    int checker= accumulate(store.begin(),store.end(),0);
    if(checker==0){return true;}
    return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> store(nums1.begin(), nums1.end());
    set<int> result;
    for(int i : nums2){
        if(store.find(i)!=store.end()){
            result.insert(i);
        }
    }
    return {result.begin(),result.end()};
}

void vector_printer(vector<int> temp){
    for(auto ele:temp){
        cout<< ele << ", ";
    }
}

int summation(int n){
    int sum = 0;
    while(n){
        int digit = n%10;
        n = n/10;
        sum+=(digit*digit);
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> store;
    int temp_sum =summation(n);
    while(store.insert(temp_sum).second){
        temp_sum = summation(temp_sum);
    }
    if(store.find(temp_sum)!=store.end() and temp_sum!=1){
        return false;
    }
    return true;
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>store;
    for(int i=0;i<nums.size();++i){
        store[nums[i]] = i;
    }
    vector<int> ans;
    for(int i=0;i<nums.size();++i){
        auto iter = store.find(target-nums[i]);
        if(iter != store.end() and i!=iter->second){
            ans.push_back(iter->second);
            ans.push_back(i);
            return ans;
        }
    }
    return ans;

}


int main(){
    string q1_test1_str ="rat";
    string q1_test2_str ="car";
    cout<<isAnagram(q1_test1_str, q1_test2_str)<<endl;

    vector<int>q2_nums_1 = {1,2,2,1};
    vector<int>q2_nums_2 = {2,2};
    vector<int>q2_ans = intersection(q2_nums_1, q2_nums_2);
    vector_printer(q2_ans);
    cout<<endl;

    int q3_number = 19;
    cout<<isHappy(q3_number)<<endl;

    vector<int>q4_input = {3,2,4};
    vector<int>q4_ans = twoSum(q4_input, 6);
    vector_printer(q4_ans);
    cout<<endl;
    return 0;
}