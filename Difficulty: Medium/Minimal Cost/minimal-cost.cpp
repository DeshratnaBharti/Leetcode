class Solution {
  public:
   int n;
   vector<int>dp;
    int solve(int i,int k,vector<int>&arr){
        if(i==n-1) return 0;
        int mini= INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int j =1;j<=k;j++){
            if(i+j<n){
                int cost = abs(arr[i] - arr[i+j]) + solve(i+j,k,arr);
                mini = min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
         n = arr.size();
         dp.resize(n+1,-1);
        return solve(0,k,arr);
    }
};