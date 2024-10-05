//
// Created by 朱俊驰 on 10/1/24.
//

#include "../helper.h"
//
// m*n 2*3
// x x x 00 01 02
// x x x
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));;

    for(int i=0;i<n;++i){
        dp[0][i]=1;
    }
    for(int i=0;i<m;++i){
        dp[i][0]=1;
    }
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    matrix_printer(dp);
    return dp[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0]==1){return 0;}
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));;
    for(int i=0;i<m;++i){
        if(obstacleGrid[i][0]!=1){
            dp[i][0]=1;
        }
        else{
            break;
        }
    }
    for(int i=0;i<n;++i){
        if(obstacleGrid[0][i]!=1){
            dp[0][i]=1;
        }
        else{
            break;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;++j){
            if(obstacleGrid[i][j]==1){
                continue;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

// 1 1 1 1 1
// 0 1 0 0 0
// 1 1 1 1 1
int main(){
    vector<vector<int>> obstacleGrid{{0,0},{1,1},{0,0}};
    cout<<uniquePathsWithObstacles(obstacleGrid)<<endl;
//    for(int i=0;i<2;++i){
//        for(int j=0;j<3;++j){
//            cout<<i<<j<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}