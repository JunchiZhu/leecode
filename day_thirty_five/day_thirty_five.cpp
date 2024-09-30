//
// Created by 朱俊驰 on 9/28/24.
//

#include "../helper.h"

int maxProfit(vector<int>& prices) {
    int max_profit=0;
    for(int i=1;i<prices.size();++i){
        int profit = prices[i]-prices[i-1];
        if(profit>0){
            max_profit+=profit;
        }
    }
    return max_profit;
}

bool canJump(vector<int>& nums) {
    if(nums.size()==0){
        return true;
    }
    int cover = 0;
    for(int i=0;i<=cover;++i){
        cover=max(i+nums[i],cover);
        if(cover>=nums.size()-1){
            return true;
        }
    }
    return false;
}

int jump(vector<int>& nums) {
    if(nums.size()==1){return 0;}
    int current_distance=0; // 0
    int next_distance=0; // 0
    int answer=0; // 0
    for(int i=0;i<nums.size();++i){
        next_distance=max(i+nums[i],next_distance); // 2 4
        if(i==current_distance){
            answer+=1;// 1 2
            current_distance=next_distance;//2 4
            if(current_distance==nums.size()-1){
                break;
            }
        }
    }
    return answer;
}


char kthCharacter(int k) {
    int old_k = k;
    string start="a";
    while(k>=0){
        string new_word;
        for(char i : start){
            new_word+=(i+1);
        }
        start+=new_word;
        k-=1;
        if(start.size()>=old_k){
            break;
        }
    }
    return start[old_k-1];
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size() and k>0;++i){
        if(nums[i]<0){
            nums[i]=-1*nums[i];
            k--;
        }
    }
    if(k%2==1){
        sort(nums.begin(), nums.end());
        nums[0]=nums[0]*-1;
    }
    int answer = 0;
    for(int i=0;i<nums.size();++i){
        answer+=nums[i];
    }
    return answer;
}

//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//    for(int i=0;i<gas.size();++i){
//        int remain = gas[i]-cost[i];
//
//        int circle_index = (i+1)%gas.size();
//        while(remain>0 and i!=circle_index){
//            remain += gas[circle_index]-cost[circle_index];
//            circle_index = (circle_index+1)%gas.size();
//        }
//        if(remain>=0 &&circle_index==i){
//            return i;
//        }
//    }
//    return -1;
//}


int main(){
    vector<int> q2_input = {3,2,1,0,4};
    bool q2 = canJump(q2_input);
    cout<<q2<<endl;
    vector<int> q4_input = {3,-1,0,2};
    cout<<largestSumAfterKNegations(q4_input,3);
    cout<<kthCharacter(5)<<endl;
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};

    return 0;
}
