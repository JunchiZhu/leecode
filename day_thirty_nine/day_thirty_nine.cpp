//
// Created by 朱俊驰 on 9/30/24.
//

#include "../helper.h"
int fib(int n) {
    vector<int> dp(n+1,0);
    if(n==0){return 0;}
    if(n==1){return 1;}
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<dp.size();++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(int i : dp){
        cout<<i<<" ";
    }
    cout<<endl;
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n);
    if(n==1){return 1;}
    if(n==2){return 2;}
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;++i){
        dp[i]=dp[i-2]+dp[i-1];
    }
    return dp[n-1];
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1);

    if(cost.size()==1){
        return 0;
    }
    if(cost.size()==2){
        return 0;
    }
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<dp.size();++i){
        dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    for(int i : dp){
        cout<<i<<" ";
    }
    cout<<endl;
    return dp[cost.size()];
}
int main(){
    vector<int> cost{10,15,20};
    cout<<minCostClimbingStairs(cost)<<endl;
}
