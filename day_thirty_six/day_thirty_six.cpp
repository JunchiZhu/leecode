//
// Created by 朱俊驰 on 9/29/24.
//
#include "../helper.h"

//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//    for(int i=0;i<gas.size();++i){
//        int remain = gas[i]-cost[i];
//
//        int circle_index = (i+1)%gas.size();
//        while(remain>0 and i!=circle_index){
//            remain += gas[circle_index]-cost[circle_index];
//            circle_index = (circle_index+1)%gas.size();
//        }
//        if(remain>=0 &&circle_index==i){
//            return i;
//        }
//    }
//    return -1;
//}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum=0;
    int cur_sum=0;
    int start=0;
    for(int i=0;i<gas.size();++i){
        cur_sum+=gas[i]-cost[i];
        sum += gas[i]-cost[i];
        if(cur_sum<0){
            cur_sum=0;
            start=i+1;
        }
    }
    if(sum<0){
        return -1;
    }
    return start;
}

int candy(vector<int>& ratings) {
    vector<int> store(ratings.size(),1);
    // compare left to right
    for(int i=1;i<ratings.size();++i){
        if(ratings[i-1]<ratings[i]){
            store[i]=store[i-1]+1;
        }
    }
    for(int i=ratings.size()-2;i>=0;--i){
        if(ratings[i+1]<ratings[i]){
            store[i]=max(store[i],store[i+1]+1);
        }
    }
    int answer=0;
    for(int ele:store){
        answer+=ele;
    }
    return answer;
}

bool lemonadeChange(vector<int>& bills) {
    int five=0, ten=0, twenty=0;
    for(int i=0;i<bills.size();++i){
        if(bills[i]==5){
            five+=1;
        }
        else if(bills[i]==10){
            if(five<1){return false;}
            five-=1;
            ten+=1;
        }
        else if(bills[i]==20){
            if(ten>0 and five>0){
                ten-=1;
                five-=1;
            }
            else if (five>=3){
                five-=3;
            }
            else{return false;}
        }
    }
    return true;
}
bool cmp(vector<int> &a, vector<int> &b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]>b[0];
}
//排序完的people： [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
//
//插入的过程：
//
//插入[7,0]：[[7,0]]
//插入[7,1]：[[7,0],[7,1]]
//插入[6,1]：[[7,0],[6,1],[7,1]]
//插入[5,0]：[[5,0],[7,0],[6,1],[7,1]]
//插入[5,2]：[[5,0],[7,0],[5,2],[6,1],[7,1]]
//插入[4,4]：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    std::sort(people.begin(), people.end(),cmp);
    list<vector<int>> my_queue;
    for(auto element:people){
        int pos = element[1];
        auto iter = my_queue.begin();
        while(pos--){
            iter++;
        }
        my_queue.insert(iter,element);
    }
    return {my_queue.begin(),my_queue.end()};
}

int main(){
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout<<canCompleteCircuit(gas, cost)<<endl;
    vector<int> ratings{1,2,87,87,87,2,1};
    cout<<candy(ratings);


    return 0;
}