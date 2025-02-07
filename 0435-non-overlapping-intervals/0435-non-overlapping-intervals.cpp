class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int n = intervals.size();
       int ans =0;
       int lastInterval = intervals[0][1];
       for(int i =1;i<n;i++){
        if(intervals[i][0] < lastInterval){
            ans++;

        }else{
            lastInterval = intervals[i][1];
        }
       } 
       return ans;
    }
};