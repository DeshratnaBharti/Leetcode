class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        ans.push_back({arr[0][0],arr[0][1]});
        for(int i=1;i<n;i++){
            int a = ans.back()[1];
            int b = arr[i][0];
            int c = arr[i][1];
            if(a>=b){
                ans.back()[1]= max(a,c);
            }
            else{
                ans.push_back({b,c});
            }
        }
        return ans;
    }
};