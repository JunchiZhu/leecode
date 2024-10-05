//
// Created by 朱俊驰 on 10/2/24.
//

#include "../helper.h"

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int num : nums){
        sum+=num;
    }
    int target = sum/2;
    if (sum % 2 == 1) return false;
    vector<int> dp(target+1, 0);
    for(int num : nums){
        for(int j=target;j>=num;--j){
            dp[j]=max(dp[j], dp[j-num]+num);
        }
    }
    vector_printer(dp);
    cout<<endl;
    if(dp[target]==target){return true;}
    return false;
}

int main(){
    vector<int> q3{1,5,11,5};
    cout<<canPartition(q3)<<endl;
//    int number_of_item=3, number_of_space=4;
//    vector<int>spaces{1,3,4};
//    vector<int>values{15,20,30};
//    vector<int>dp(number_of_space+1, 0);
//
//    for(int i = 0; i < number_of_item; ++i) {
//        for(int j = number_of_space; j >= spaces[i]; --j) {
//            dp[j] = max(dp[j], dp[j - spaces[i]] + values[i]);
//
//        }
//    }
//    vector_printer(dp);
//    cout<<dp[number_of_space];

//    int number_of_item, number_of_space;
//    cin>>number_of_item>>number_of_space;
//    vector<int>spaces(number_of_item,0);
//    vector<int>values(number_of_item,0);
//    for(int i=0;i<number_of_item;++i){
//        cin>>spaces[i];
//    }
//    for(int i=0;i<number_of_item;++i){
//        cin>>values[i];
//    }
//    vector<vector<int>>dp(number_of_item, vector<int>(number_of_space+1,0));
//
//    for(int i=spaces[0];i<=number_of_space;++i){ //number_of_item
//        dp[0][i]=values[0];
//    }
//
//    for(int i=1;i<number_of_item;++i){
//        for(int j=0;j<=number_of_space;++j){
//            if(j<spaces[i]){
//                dp[i][j]=dp[i-1][j];
//            }
//            else{
//                dp[i][j]=max(dp[i-1][j], dp[i-1][j-spaces[i]]+values[i]);
//            }
//        }
//    }
//    matrix_printer(dp);
//    cout<<dp[number_of_item-1][number_of_space];

    return 0;


}