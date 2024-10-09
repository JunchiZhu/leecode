//
// Created by 朱俊驰 on 10/6/24.
//

#include "../helper.h"

void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    vector_printer(dp);
    cout << dp[bagWeight] << endl;
}

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int coin : coins){
        for(int j=coin;j<=amount;++j){
            if(dp[j] < INT_MAX - dp[j - coin]){
                dp[j]+=dp[j-coin];
            }
        }
    }
    // for(int i=coins[i];i<=amount;++i){
    //     for(int j=0;j<coins.size();++j){
    //         if(i-coins[j]>=0){
    //             dp[i]+=dp[i-coins[j]];
    //         }
    //     }
    // }
    return dp[amount];
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<=target;++i){
        for(int j=0;j<nums.size();++j){
            if(i-nums[j]>=0 && dp[i] < INT_MAX - dp[i - nums[j]]){
                dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}

void test_CompletePack(vector<int> weight, vector<int> value, int bagWeight) {
    vector<int> dp(bagWeight+1,0);
    // for(int i=0;i<weight.size();++i){
    //     for(int j=weight[i];j<=bagWeight;++j){
    //         dp[j]=max(dp[j], value[i]+dp[j-weight[i]]);
    //     }
    // }
    for(int i=0;i<=bagWeight;++i){
        for(int j=0;j<weight.size();++j){
            if(i>=weight[j]){
                dp[i]=max(dp[i],dp[i-weight[j]]+value[j]);
            }
        }
    }

    cout<<dp[bagWeight];
}

int main() {
//    test_CompletePack();
    vector<int> coins = {1,2,3};
    cout<<change(4,coins);

//    int N, V;
//    cin >> N >> V;
//    vector<int> weight;
//    vector<int> value;
//    for (int i = 0; i < N; i++) {
//        int w;
//        int v;
//        cin >> w >> v;
//        weight.push_back(w);
//        value.push_back(v);
//    }
//    test_CompletePack(weight, value, V);
//    return 0;
    // 1.
    // 01背包 每个物品只能添加一次，dp中每个cell的含义为dp[i][j]表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
    // two dimension dp forward order
    // one dimension dp backward order 必须先物品后背包容量
    // 用max
    // 2.
    // 求方法数量
    // 使用下标为[0, i]的nums[i]能够凑满j（包括j）这么大容量的包，有dp[i][j]种方法。
    // 不用max，上一层物品前加后
    // 3.
    // 完全背包
    // one dimension dp forward order 物品和背包容量循环随意
    // max

//    // 0/1 背包的二维 DP 更新
//    if (j >= w[i]) {
//        dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
//    } else {
//        dp[i][j] = dp[i-1][j];
//    }
//
//    // 完全背包的二维 DP 更新
//    if (j >= w[i]) {
//        dp[i][j] = max(dp[i-1][j], dp[i][j - w[i]] + v[i]);
//    } else {
//        dp[i][j] = dp[i-1][j];
//    }
// 爬楼梯

    int n, m;
    while (cin >> n >> m) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i=1;i<n+1;++i){
            for(int j=1;j<=m;++j){
                if(i-j>=0){
                    dp[i]=dp[i]+dp[i-j];
                }
            }
        }
        std::cout << dp[n] << std::endl;
    }
}

