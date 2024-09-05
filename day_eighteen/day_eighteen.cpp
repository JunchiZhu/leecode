//
// Created by 朱俊驰 on 9/3/24.
//

#include "../helper.h"
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int>store;

    for(int i : nums1){
        for(int j : nums2){
            store[i+j]+=1;
        }
    }
    int counter = 0;
    for(int i : nums3){
        for(int j : nums4){
            auto iter = store.find((0-(i+j)));
            if(iter!=store.end()){
               counter+=iter->second;
           }
        }
    }
    return counter;
}


bool canConstruct(const string& ransomNote, const string& magazine) {
    vector<int>store(26,0);
    for(char i:magazine){
        int index = i-'a';
        store[index]+=1;
    }
    for(char i:ransomNote){
        int index = i-'a';
        store[index]-=1;
    }
    for(int i:store){
        if(i<0){
            return false;
        }
    }
    return true;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());


    vector<vector<int>> answer;
    for(int i=0;i<nums.size();++i){
        int left = i+1;
        int right = nums.size()-1;
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        while(left < right){
            if(nums[i]+nums[left]+nums[right]>0){
                right-=1;
            }
            else if(nums[i]+nums[left]+nums[right]<0){
                left+=1;
            }
            else{
                answer.push_back({nums[i],nums[left],nums[right]});
                while(left<right && nums[right]==nums[right-1]){
                    right--;
                }
                while(left<right && nums[left]==nums[left+1]){
                    left++;
                }
                left+=1;
                right-=1;
            }
        }
    }
    return answer;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answer;
    sort(nums.begin(),nums.end());
    for(int i =0;i<nums.size();++i){
        if (nums[i] > target && nums[i] >= 0) {
            break;
        }
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<nums.size();++j){
            if (nums[i]+nums[j] > target && nums[i]+nums[j]  >= 0) {
                break;
            }
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int left = j+1;
            int right =nums.size()-1;

            while (left<right){
                if(nums[i]+nums[j]+nums[left]+nums[right]>target){
                    right-=1;
                }
                else if(nums[i]+nums[j]+nums[left]+nums[right]<target){
                    left+=1;
                }
                else{
                    answer.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left+=1;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        right-=1;
                    }
                    left+=1;
                    right-=1;
                }
            }
        }
    }
    return answer;
}

int main(){
    vector<int> q1_test1_case1 = {-1,-1};
    vector<int> q1_test1_case2 = {-1,1};
    vector<int> q1_test1_case3 = {-1,1};
    vector<int> q1_test1_case4 = {1,-1};
    cout<<fourSumCount(q1_test1_case1,q1_test1_case2,q1_test1_case3,q1_test1_case4)<<endl;

    vector<int> q3_test1_case1 = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    matrix_printer(threeSum(q3_test1_case1));

    cout<<endl;
    vector<int> q4_test1_case1 = {-2,-1,-1,1,1,2,2};
    int target = 0;
    matrix_printer(fourSum(q4_test1_case1, target));
}