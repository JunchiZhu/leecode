//
// Created by 朱俊驰 on 9/21/24.
//

#include "../helper.h"

bool isValid(string &address, int start, int end){
    if(start>end){
        return false;
    }
    if(address[start]=='0' and start!=end){
        return false;
    }
    int sum=0;
    for(int i=start;i<=end;++i){
        if(address[i]<'0' || address[i]>'9'){
            return false;
        }
        sum=sum*10+(address[i]-'0');

        if(sum>255){
            return false;
        }
    }
    return true;
}

void backtracking(vector<string> &answer, string &s, int start,int dot_count){
    if(dot_count == 3){
        if(isValid(s,start,s.size()-1)){
//            cout<<s<<" "<<start<<" "<<s.size()-1<<endl;
            answer.push_back(s);
        }
        return;
    }

    for(int end=start;end<s.size();++end){
        if(isValid(s,start,end)){
            auto iter = s.begin()+end+1;
            s.insert(iter,1,'.');
            dot_count+=1;
            backtracking(answer, s,  end+2, dot_count);
            dot_count-=1;
            s.erase(iter);
        } else{ break;}
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> answer;
    int dot_count=0;
    backtracking(answer,s, 0, dot_count);
    return answer;
}

void backtracking(vector<vector<int>>&answer,vector<int>&path,vector<int>& nums, int start){
    answer.push_back(path);
    for(int i=start;i<nums.size();++i){
        path.push_back(nums[i]);
        backtracking(answer,path,nums,i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>answer;
    vector<int>path;
    backtracking(answer,path,nums,0);
    return answer;
}


void backtracking2(vector<vector<int>>&answer,vector<int>&path,vector<int>& nums, int start){
    answer.push_back(path);
    for(int i=start;i<nums.size();++i){
        if(start<i and nums[i-1]==nums[i]){
            continue;
        }
        path.push_back(nums[i]);
        backtracking(answer,path,nums,i+1);
        path.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>>answer;
    vector<int>path;
    sort(nums.begin(),nums.end());
    backtracking2(answer,path,nums,0);
    return answer;
}
int main(){
//    cout<<isValid((string &) "2551", 0, 4)<<endl;
//    string s = "25525511135";
//    vector_printer(restoreIpAddresses(s));

    vector<int>nums = {1,2,3};
    matrix_printer(subsets(nums));
    return 0;
}
