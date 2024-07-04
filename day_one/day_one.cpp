//
// Created by 朱俊驰 on 7/3/24.
//

#include <iostream>
#include <vector>
using namespace std;

//704. 二分查找
//题目建议： 大家今天能把 704.二分查找 彻底掌握就可以，
//至于 35.搜索插入位置 和 34. 在排序数组中查找元素的第一个和最后一个位置 ，如果有时间就去看一下，没时间可以先不看，二刷的时候在看。
//
//先把 704写熟练，要熟悉 根据 左闭右开，左闭右闭 两种区间规则 写出来的二分法。
//
//题目链接：https://leetcode.cn/problems/binary-search/
//文章讲解：https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html
//视频讲解：https://www.bilibili.com/video/BV1fA4y1o715
//-1,0,3,5,9,12
// version one 左闭右闭
int binary_search_version_one(vector<int>& nums, int target) {
    size_t size = nums.size();
    int mid = size/2;
    int left = 0, right = size-1;
    while(left<=right){
        if(nums[mid]>target){
            right=mid-1;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            return mid;
        }
        mid = (left+right)/2;
    }
    return -1;
}

// version two 左闭右开   -1,0,3,5,9,12
int binary_search_version_two(vector<int>& nums, int target) {
    size_t size = nums.size();
    int mid = size/2;
    int left = 0, right = size;
    while(left<right){
        if(nums[mid]>target){
            right = mid;
        }
        else if(nums[mid]<target){
            left = mid+1;
        }
        else{
            return mid;
        }

        mid = (right+left)>>1;
    }
    return -1;
}

//27. 移除元素
//
//题目建议：  暴力的解法，可以锻炼一下我们的代码实现能力，建议先把暴力写法写一遍。
//双指针法 是本题的精髓，今日需要掌握，至于拓展题目可以先不看。
//
//题目链接：https://leetcode.cn/problems/remove-element/
//文章讲解：https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html
//视频讲解：https://www.bilibili.com/video/BV12A4y1Z7LP
// 3,2,2,3
int removeElement_brute_version(vector<int>& nums, int val) {
    size_t size = nums.size();
    for(size_t i=0;i<size;i++){
        if(nums[i]==val){
            for(size_t j=i+1;j<nums.size();++j){
                nums[j-1] = nums[j];
            }
            i--;
            size -=1;
        }
    }
    return size;
}

int removeElement_two_pointers_version(vector<int>& nums, int val) {
    size_t slow_index = 0;
    for(size_t fast_index=0;fast_index<nums.size();fast_index++){
        if(nums[fast_index] != val){
            nums[slow_index] = nums[fast_index];
            slow_index+=1;
        }
    }
    return slow_index;
}

//int main(){
//    vector<int> q1_numbers = {-1,0,3,5,9,12};
//    int target = 9;
//    cout<<binary_search_version_one(q1_numbers, target)<<endl;
//    cout<<binary_search_version_two(q1_numbers, target)<<endl;
//
//    vector<int> q2_numbers = {0,1,2,2,3,0,4,2};
//    cout<<removeElement_brute_version(q2_numbers, 2)<<endl;
//    cout<<removeElement_two_pointers_version(q2_numbers, 2)<<endl;
//}