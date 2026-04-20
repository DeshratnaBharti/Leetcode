class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>ans;
         sort(arr.begin(),arr.end());
        ans.push_back({arr[0][0],arr[0][1]});
        //sort(arr.begin(),arr.end());
        for(int i=1;i<m;i++){
            int a = ans.back()[0];
            int b  = ans.back()[1];
            int c = arr[i][0];
            int d = arr[i][1];
            if(b>=c){
                ans.back()[1] = max(b,d);

            }else{
                 ans.push_back({c,d});
            }


        }
        return ans;
    }
};