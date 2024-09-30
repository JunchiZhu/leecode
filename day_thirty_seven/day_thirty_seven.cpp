//
// Created by 朱俊驰 on 9/29/24.
//

#include "../helper.h"
static bool cmp(vector<int>a, vector<int>b){
    return a[0]<b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end());
    int answer = 1;
    for(int i=1;i<points.size();++i){
        if(points[i-1][1]<points[i][0]){
            answer+=1;
        } else{
            points[i][1]=min(points[i-1][1], points[i][1]);
        }
    }
    return answer;
}

static bool cmp_2(vector<int>a, vector<int>b){
    return a[0]<b[0];
}
// [1,2],[1,3],[2,3],[3,4],
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp_2);
    int answer = 0;
    for(int i=1;i<intervals.size();++i){
        if(intervals[i-1][1]>intervals[i][0]){
            answer+=1;
            intervals[i][1]=min(intervals[i-1][1],intervals[i][1]);
        }
    }
    return answer;
}


static bool cmp_3(vector<int>a, vector<int>b){
    return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp_3);
    vector<vector<int>> answer;
    if(intervals.size()==1){return intervals;}
    answer.push_back(intervals[0]);
    for(int i=1;i<intervals.size();++i){
        if(answer.back()[1]>=intervals[i][0]){
            answer.back()[1]=max(answer.back()[1], intervals[i][1]);
        }
        else{
            answer.push_back({intervals[i]});
        }
    }
    return answer;
}


int main(){
//    vector<vector<int>> intervals{{1,100},{11,22},{1,11},{2,12}};
//    cout<<eraseOverlapIntervals(intervals);

    vector<vector<int>> intervals2{{1,4},{5,6}};
    matrix_printer(merge(intervals2));
    return 0;
}