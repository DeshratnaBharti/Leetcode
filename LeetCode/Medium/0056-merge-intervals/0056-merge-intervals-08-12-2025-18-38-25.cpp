class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>curr = intervals[i];
            if(curr[0]<= ans[ans.size()-1][1]){
                ans[i-1][0] = min(curr[0],ans[i-1][0]);
                ans[i-1][1] = max(curr[1],ans[i-1][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};