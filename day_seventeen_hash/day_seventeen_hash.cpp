//
// Created by 朱俊驰 on 9/2/24.
//

#include "../helper.h"
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }
    vector<int>store(26,0);
    for(char letter:s){
        int index = letter-'a';
        store[index] += 1;
    }
    for(char letter:t){
        int index = letter-'a';
        store[index] -= 1;
    }
    for(int i : store){
        if(i>0){
            return false;
        }
    }
    return true;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> store(nums1.begin(),nums1.end());
    set<int> ans;
    for(int i : nums2){
        if(store.find(i)!=store.end()){
            ans.insert(i);
        }
    }
    return vector<int>(ans.begin(),ans.end());
}

bool isHappy(int n) {
    int number=0;
    unordered_set<int> store;
    while(true){
        while(n){
            int digit = n%10;
            number+=digit*digit;
            n=n/10;
        }
        if(number==1){
            return true;
        }
        if(!store.insert(number).second){
            return false;
        }
        n=number;
        number=0;
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>store;
    vector<int>answer;
    for(int i=0;i<nums.size();++i){
        auto iter = store.find(target-nums[i]);
        if(iter!=store.end()){
            answer.push_back(iter->second);
            answer.push_back(i);
        }
        else{
            store[nums[i]]=i;
        }
    }
    return answer;
}

int main(){
    string q1_test1_str ="anagram";
    string q1_test2_str ="nagaram";
    cout<<isAnagram(q1_test1_str, q1_test2_str)<<endl;

    vector<int> q2_test_1 = vector<int>{1,2,2,1};
    vector<int> q2_test_2 = vector<int>{2,2};
    vector_printer(intersection(q2_test_1,q2_test_2));

    int q3_test_1 = 19;
    cout<<isHappy(q3_test_1);

    return 0;
}

