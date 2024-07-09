//
// Created by 朱俊驰 on 7/9/24.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    map<int, int>store;
    for(int i=0;i<nums1.size();++i){
        for(int j=0;j<nums1.size();++j){
            store[nums1[i]+nums2[j]] += 1;
        }
    }
    int counter = 0;
    for(int i=0;i<nums1.size();++i){
        for(int j=0;j<nums1.size();++j){
            int sub_sum = nums3[i]+nums4[j];
            auto iter = store.find((0-sub_sum));
            if(iter != store.end()){
                counter+=iter->second;
            }
        }
    }
    return counter;
}

bool canConstruct_map_version(const string& ransomNote, const string& magazine) {
    map<char, int>store;
    for(char i : ransomNote){
        store[i]+=1;
    }

    for(char i : magazine){
        if(store.find(i)!=store.end()){
            store[i]-=1;
        }
    }

    for(const auto& pair : store) {
        if (pair.second > 0) {
            return false;
        }
    }
    return true;

//    return all_of(store.begin(),store.end(),[](pair<char, int> pair){
//        return pair.second<=0;
//    });
}

bool canConstruct_vector_version(const string& ransomNote, const string& magazine) {
    vector<int>store(26,0);
    for(char i : ransomNote){
        store[i-'a']+=1;
    }

    for(char i : magazine){
        store[i-'a']-=1;
    }

    for(int i : store) {
        if (i > 0) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> store;

    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size();++i){
        int slow=i+1;
        int fast=nums.size()-1;
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        while(slow<fast){
            if(nums[slow]+nums[fast]+nums[i]>0){
                fast-=1;
            }
            else if(nums[slow]+nums[fast]+nums[i]<0){
                slow+=1;
            } else{
                store.push_back({nums[i], nums[slow], nums[fast]});
                while(fast>slow && nums[slow]==nums[slow+1]){
                    slow+=1;
                }
                while(fast>slow && nums[fast]==nums[fast-1]){
                    fast-=1;
                }
                slow+=1;
                fast-=1;
            }
        }

    }
    return store;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> store;
    for(int i=0;i<nums.size();++i){
        if (nums[i] > target && nums[i] >= 0) {
            break;
        }
        if(i!=0 and nums[i-1]==nums[i]){
            continue;
        }
        for(int j=i+1;j<nums.size();++j){
            int slow = j+1;
            int fast = nums.size()-1;
            if (nums[i]+nums[j] > target && nums[i]+nums[j] >= 0) {
                break;
            }
            if(j!=i+1 and nums[j-1]==nums[j]){
                continue;
            }
            while(slow<fast){
                if((long)nums[i]+nums[j]+nums[slow]+nums[fast]>target){
                    fast-=1;
                }
                else if((long)nums[i]+nums[j]+nums[slow]+nums[fast]<target){
                    slow+=1;
                }
                else{
                    store.push_back({nums[i],nums[j],nums[slow],nums[fast]});
                    while (slow<fast and nums[slow] == nums[slow+1]){
                        slow+=1;

                    }
                    while (slow<fast and nums[fast] == nums[fast-1]){
                        fast-=1;
                    }
                    fast-=1;
                    slow+=1;
                }
            }
        }

    }
    return store;
}

void matrix_printer(const vector<vector<int>>& temp){
    for(const auto& row:temp){
        for(auto ele:row){
            cout<< ele << ", ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> q1_input1 = {1,2};
    vector<int> q1_input2 = {-2,-1};
    vector<int> q1_input3 = {-1,2};
    vector<int> q1_input4 = {0,2};
    int q1_ans = fourSumCount(q1_input1, q1_input2, q1_input3, q1_input4);
    cout<<q1_ans<<endl;

    string q2_input1 = "a";
    string q2_input2 = "b";
    bool q2_ans_map = canConstruct_map_version(q2_input1, q2_input2);
    cout<<q2_ans_map<<endl;
    bool q2_ans_vector = canConstruct_vector_version(q2_input1, q2_input2);
    cout<<q2_ans_vector<<endl;

    vector<int> q3_input = {-2,0,0,2,2};
    vector<vector<int>> q3_ans = threeSum(q3_input);
    matrix_printer(q3_ans);

    vector<int> q4_input = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    int target = 1000000000;
    matrix_printer(fourSum(q4_input, target));
    return 0;
}