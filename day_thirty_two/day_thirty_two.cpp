//
// Created by 朱俊驰 on 9/22/24.
//
#include "../helper.h"

void trackback(vector<vector<int>> &answer,  vector<int> &path, vector<int>& nums, int start){
    if(path.size()>1){
        answer.push_back(path);
    }
    unordered_set<int> uset;
    for(int end=start;end<nums.size();++end){
        if((path.size()>0 and path.back()>nums[end]) || uset.find(nums[end]) != uset.end()){
            continue;
        }
        uset.insert(nums[end]);
        path.push_back(nums[end]);
        trackback(answer, path, nums, end+1);
        path.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> answer;
    vector<int>path;
    trackback(answer,path,nums,0);
    return answer;
}


void backtracking(vector<int>& candidates, int target, vector<vector<int>>&answer, vector<int>& path,int sum, int start){
    if(sum==target){
        answer.push_back(path);
        return;
    }
    for(int end=start;end<candidates.size();++end){
        if(start<end and candidates[end]==candidates[end-1]){
            continue;
        }
        sum+=candidates[end];
        path.push_back(candidates[end]);
        backtracking(candidates,target,answer,path,sum,end+1);
        sum-=candidates[end];
        path.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>answer;
    vector<int>path;
    sort(candidates.begin(),candidates.end());
    int start = 0;
    int sum=0;
    backtracking(candidates,target,answer,path,sum, start);
    return answer;

}

void track_back( vector<vector<int>>& answer,vector<int>& path,vector<bool>& uset, vector<int>& nums){
    if(path.size()==nums.size()){
        answer.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();++i){
        if(!uset[i]){
            path.push_back(nums[i]);
            uset[i]=true;
            track_back(answer,path,uset,nums);
            path.pop_back();
            uset[i]=false;
        }
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>answer;
    vector<bool> uset(nums.size(),false);
    vector<int> path;
    track_back(answer, path,uset,nums);
    return answer;
}

void track_back2( vector<vector<int>>& answer,vector<int>& path,vector<bool>& uset, vector<int>& nums){
    if(path.size()==nums.size()){
        answer.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();++i){
        path.push_back(nums[i]);
        track_back2(answer,path,uset,nums);
        path.pop_back();
    }
}

vector<vector<int>> permute2(vector<int>& nums) {
    vector<vector<int>>answer;
    vector<bool> uset(nums.size(),false);
    vector<int> path;
    track_back2(answer, path,uset,nums);
    return answer;
}


int main(){
    vector<int> test{10,1,2,7,6,1,5};
    combinationSum2(test,8);
    vector<int> test2{1,2,3};
    matrix_printer(permute(test2));
    matrix_printer(permute2(test2));
    return 0;
}