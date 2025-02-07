class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int n = intervals.size();
       int ans =0;
       sort(intervals.begin(),intervals.end(),[&](auto &v1,auto &v2){
        return v1[1]<v2[1];
       });
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