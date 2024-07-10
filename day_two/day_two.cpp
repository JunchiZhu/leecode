//
// Created by 朱俊驰 on 7/4/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vector_printer(const vector<int>& temp){
    for(auto ele:temp){
        cout<< ele << ", ";
    }
}

void matrix_printer(const vector<vector<int>>& temp){
    for(const auto& row:temp){
        for(auto ele:row){
            cout<< ele << ", ";
        }
       cout<<endl;
    }
}

//977.有序数组的平方
//
//题目建议： 本题关键在于理解双指针思想
//
//题目链接：https://leetcode.cn/problems/squares-of-a-sorted-array/
//文章讲解：https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
//视频讲解： https://www.bilibili.com/video/BV1QB4y1D7ep
vector<int> sortedSquares(vector<int>& nums) {
    int left = 0;
    int right=nums.size()-1;
    vector<int> store(right+1);
    int counter=nums.size()-1;
    while(left <= right){
        int left_value = nums[left]*nums[left];
        int right_value = nums[right]*nums[right];
        if(left_value > right_value){
            store[counter]=left_value;
            left+=1;
        } else if(left_value <= right_value){
            store[counter]=right_value;
            right-=1;
        }
        counter-=1;
    }
    return store;
}
//209.长度最小的子数组
//
//题目建议： 本题关键在于理解滑动窗口，这个滑动窗口看文字讲解 还挺难理解的，建议大家先看视频讲解。
//拓展题目可以先不做。
//
//题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/
//文章讲解：https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html
//视频讲解：https://www.bilibili.com/video/BV1tZ4y1q7XE
int minSubArrayLen_brute_force_version(int target, vector<int>& nums) {
    int min_value = INT_MAX;
    for(int i=0; i<nums.size();++i){
        int sum=0;

        for(int j=i; j<nums.size();++j){
            sum+=nums[j];
            if(sum>=target){
                if(min_value>(j-i+1)){
                    min_value=(j-i+1);
                    break;
                }
            }
        }
    }
    if(min_value==INT_MAX){
        return 0;
    } else{
        return min_value;
    }
}

int minSubArrayLen(int target, vector<int>& nums) {
    int min_length = INT_MAX;
    int start_index = 0;
    int sum = 0;
    for(int i=0;i<nums.size();++i){
        sum+=nums[i];
        while(sum>=target){
            int temp_length = i-start_index+1;
            if(min_length>temp_length){
                min_length=temp_length;
            }
            sum-=nums[start_index];
            start_index+=1;
        }
    }
    if(min_length==INT_MAX){
        return 0;
    } else{
        return min_length;
    }
}

//59.螺旋矩阵II
//
//题目建议：  本题关键还是在转圈的逻辑，在二分搜索中提到的区间定义，在这里又用上了。
//
//题目链接：https://leetcode.cn/problems/spiral-matrix-ii/
//文章讲解：https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html
//视频讲解：https://www.bilibili.com/video/BV1SL4y1N7mV/
//  3
// 00 01 02 03
// 00 1 2 3 4 03
// 10 2 3 4 5 13
// 20 1 6 5 6 23
// 30 0 9 8 7 33
// 30 31 32 33

vector<vector<int>> generateMatrix(int n) {
    int rows = n, columns = n;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    int loop = n/2;
    int start_i=0, start_j=0;
    int i,j;
    int offset = 1;
    int counter = 1;
    while(loop){
        for(j=start_j;j<n-offset;++j){
            matrix[start_i][j] = counter;
            counter+=1;
        }
        for (i=start_i; i<n-offset;++i) {
            matrix[i][j] = counter;
            counter+=1;
        }
        for (;j>start_j;--j) {
            matrix[i][j]=counter;
            counter+=1;
        }
        for (;i>start_i;--i) {
            matrix[i][j]=counter;
            counter+=1;
        }
        loop-=1;
        offset+=1;
        start_i+=1;
        start_j+=1;
    }
    if(n%2==1){
        matrix[n/2][n/2]=counter;
    }
    return matrix;
}





int main(){
    vector<int>q1_nums={-4,-1,0,3,10};
    vector_printer(sortedSquares(q1_nums));
    cout<<endl;
    vector<int>q2_nums={2,3,1,2,4,3};
    cout<<minSubArrayLen_brute_force_version(7, q2_nums)<<endl;
    cout<<minSubArrayLen(7, q2_nums)<<endl;

    int q3_input = 4;
    matrix_printer(generateMatrix(q3_input));
}

