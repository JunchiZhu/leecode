//
// Created by 朱俊驰 on 9/27/24.
//


#include "../helper.h"
// bubble sort
void bubbleSort(int arr[], int n) {
    // Your code here
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1;++j){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
// 5 4 3 2 1
//
// insertion sort
void insertionSort(vector<int> &arr, int n){
    for(int i=1;i<n;++i){
        int val = arr[i];
        int pre_pos=i-1;
        while(pre_pos>=0 and arr[pre_pos]>val){
            arr[pre_pos+1]=arr[pre_pos];
            pre_pos-=1;
        }
        arr[pre_pos+1]=val;
    }
}
// selection sort
void selectionSort(vector<int> &arr, int n)
{
    for(int i=0;i<n;++i){
        int min=arr[i];
        int min_index=i;
        for(int j=i;j<n;++j){
            if(arr[j]<min){
                min=arr[j];
                min_index=j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index]=temp;
    }
}

// merge sort
// quick sort

int main(){
    vector<int> arr1{24, 18, 38, 43 , 14, 40, 1, 54};
    insertionSort(arr1, 8);
    for(auto ele:arr1){
        cout<<ele<<" ";
    }
    return 0;
}