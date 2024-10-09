//
// Created by 朱俊驰 on 10/7/24.
//

#include "../helper.h"

int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1, INT_MAX);
    dp[0]=0;
    for(int i=0;i<coins.size();++i){
        for(int j=coins[i];j<amount+1;++j){
            if(dp[j-coins[i]]!=INT_MAX){
                dp[j]=min(dp[j], dp[j-coins[i]]+1);
            }
        }
    }
    vector_printer(dp);
    if(dp[amount]==INT_MAX){return -1;}
    return dp[amount];
}

int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0]=0;
    for(int i=1;i*i<n+1;++i){
        for(int j=i*i;j<n+1;++j){
            dp[j]=min(dp[j],dp[j-i*i]+1);
        }
    }
    return dp[n];
}

// 爬楼梯思维直接秒
// 能否构成字符串s，也即是能否爬上s.size()层楼梯
// 每次爬楼梯的方法都在wordDict中
// 想要爬上楼梯i，需要遍历wrodDict找能够爬上去的方法，
// 但是要确保爬上来的那个台阶也是能够爬到的

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> word_set(wordDict.begin(),wordDict.end());
    vector<bool> dp(s.size()+1, false);
    dp[0]=true;
    for(int i=1; i<s.size()+1;++i){
        for(int j=0; j<i;++j){
            if(word_set.find(s.substr(j,i-j))!=word_set.end() and dp[j]){
                dp[i]=true;
            }
        }
    }
    return dp[s.size()];
}

int main(){
//    vector<int> coins = {2};
//    int amount =3;
//    cout<<numSquares(12)<<endl;

    string test3="catsandog";
    vector<string> words = {"cats","dog","sand","and","cat"};
    cout<<wordBreak(test3,words);
    return 0;
}
