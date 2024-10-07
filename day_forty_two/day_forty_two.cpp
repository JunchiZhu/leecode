//
// Created by 朱俊驰 on 10/5/24.
//

#include "../helper.h"

int lastStoneWeightII(vector<int>& stones) {
    int sum = std::accumulate(stones.begin(),stones.end(),0);
    int target = sum/2;
    vector<int>dp(target+1,0);
    for(int stone : stones){
        for(int j=target;j>=stone;--j){
            dp[j]=max(dp[j],dp[j-stone]+stone);
        }
    }

    vector_printer(dp);
    return sum-(2*dp[target]);
}

int lastStoneWeightII_two_dimension(vector<int>& stones) {
    int sum = std::accumulate(stones.begin(),stones.end(),0);
    int target = sum/2;
    vector<vector<int>>dp(stones.size(),vector<int>(target+1,0));
    for(int i=stones[0];i<=target;++i){
        dp[0][i]=stones[0];
    }
    for(int i=1;i<stones.size();++i){
        for(int j=0;j<target+1;++j){
            if(j<stones[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-stones[i]]+stones[i]);
            }

        }
    }
    matrix_printer(dp);
    return sum-(2*dp[stones.size()-1][target]);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = std::accumulate(nums.begin(),nums.end(),0);
    if((sum+target)%2){
        return 0;
    }
    if(abs(target)>sum){
        return 0;
    }
    int bag_size = (sum+target)/2;
    vector<vector<int>>dp(nums.size(), vector<int>(bag_size+1,0));
    // first row
    if(bag_size>=nums[0]){
        dp[0][nums[0]]=1;
    }
    // first column
    dp[0][0]=1;
    int num_of_zero=0;
    for(int i=0;i<nums.size();++i){
        if(nums[i]==0){
            num_of_zero+=1;
        }
        dp[i][0]=int(std::pow(2,(num_of_zero)));
    }

    for(int i=1;i<nums.size();++i){
        for(int j=0;j<bag_size+1;++j){
            if(j<nums[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i]];
            }
        }
    }
    return dp[nums.size()-1][bag_size];
}


int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0)); // 默认初始化0
    for (string str : strs) { // 遍历物品
        int oneNum = 0, zeroNum = 0;
        for (char c : str) {
            if (c == '0') zeroNum++;
            else oneNum++;
        }
        for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
            for (int j = n; j >= oneNum; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
            }
        }
    }
    matrix_printer(dp);
    return dp[m][n];
}

int findTargetSumWays_2(vector<int>& nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if (abs(target) > sum) return 0; // 此时没有方案
    if ((target + sum) % 2 == 1) return 0; // 此时没有方案
    int bagSize = (target + sum) / 2;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (int num : nums) {
        for (int j = bagSize; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    vector_printer(dp);
    return dp[bagSize];
}

int main(){
//    vector<int>stones{1,1,4,2,2};
//    cout<<lastStoneWeightII_two_dimension(stones)<<endl;
    vector<int>nums{1,1,1,1,1};
    cout<<findTargetSumWays_2(nums, 3);

//    vector<string> strs = {"11000001", "10", "0001", "1", "0"};
//    int m = 5;  // maximum zeros
//    int n = 3;  // maximum ones
//    int result = findMaxForm(strs, m, n);
//    cout << "Test Case 1: " << result << endl;  // Expected output: 4

    return 0;
}
