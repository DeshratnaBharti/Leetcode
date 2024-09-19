bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
    class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort karege ending time ke anussar
         sort(intervals.begin(),intervals.end(),cmp);
         vector<vector<int>>result;
         int n= intervals.size();
         result.push_back(intervals[n-1]);
         for(int i=n-2;i>=0;i--){
            vector<int>curr= intervals[i];//curr={1,3}
            if(curr[1] >= result[result.size()-1][0]){
                //curr.end >= last.start -> overlapping wala case hai
                result[result.size()-1][0] = min (result[result.size()-1][0],curr[0]);
                result[result.size()-1][1] = max (result[result.size()-1][1],curr[1]);

            }else{
               // overlapping nahin hua hai
                result.push_back(intervals[i]);

            }
         }
         reverse(result.begin(),result.end());
         return result;
    }
};