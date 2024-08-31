//
// Created by 朱俊驰 on 8/6/24.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> store;
    int answer = 0;
    int left=0;
    for(int right=0;right<fruits.size();++right){
        store[fruits[right]]+=1;
        while(store.size()>2){
            store[fruits[left]]-=1;
            if(store[fruits[left]] == 0){
                store.erase(fruits[left]);
            }
            left+=1;
        }
        answer = max(answer, right-left+1);
    }
    return answer;
}

void sortColors(vector<int>& nums) {
    int zero=0;
    int two=nums.size()-1;
    for(int i=0;i<nums.size();++i){
        while(nums[i]==2 && i<= two){
            swap(nums[i],nums[two]);
            two-=1;
        }
        if(nums[i]==0){
            swap(nums[i],nums[zero]);
            zero+=1;
        }
    }
}

int main(){
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << "Total Fruit: " << totalFruit(fruits) << endl; // Output should be 5

    return 0;
}