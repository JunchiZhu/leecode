//
// Created by 朱俊驰 on 9/22/24.
//

#include "../helper.h"
int findContentChildren(vector<int>& g, vector<int>& s) {
    if(s.size()==0 ||g.size()==0){
        return 0;
    }
    int counter=0;
    // 1 2 3
    // 1 2
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int s_index=s.size()-1;
    for(int i=g.size()-1;i>=0;--i){
        if(s_index>=0 and g[i]<=s[s_index]){
            counter+=1;
            s_index-=1;
        }
    }
    return counter;
}

int wiggleMaxLength(vector<int>& nums) {
    int result=1;
    int pre_num = 0;
    for(int i=0;i<nums.size()-1;++i){
        int post_num = nums[i+1]-nums[i];
        if((post_num>0 and pre_num<=0)||(pre_num>=0 and post_num<0)){
            result+=1;
            pre_num=post_num;
        }
    }
    return result;
}

int maxSubArray(vector<int>& nums) {
    int count=0;
    int max=INT32_MIN;
    for(int num : nums){
        count+=num;
        if(count>max){
            max=count;
        }
        if(count<0){count=0;}
    }
    return max;
}
int main(){
    vector<int>g{1,2,3};
    vector<int>s{1,1};
    cout<<findContentChildren(g,s)<<endl;

    vector<int>q3{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(q3)<<endl;

    return 0;
}
