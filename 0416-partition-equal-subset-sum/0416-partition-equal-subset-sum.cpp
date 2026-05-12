class Solution {
public:
    //int n;
    vector<vector<int>>dp;
    bool solve(vector<int>&nums,int i,int sum,int tgt){
        if(i<0 or sum>tgt) return false;
        if(sum==tgt ) return true;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool take = solve(nums,i-1,sum + nums[i],tgt);
        bool skip = solve(nums,i-1,sum,tgt);
        return dp[i][sum]=take or skip ;


    }
    bool canPartition(vector<int>& arr) {
       int n = arr.size(); 
         
        int s= accumulate(arr.begin(),arr.end(),0);
        if(s%2 !=0) return false;
        int target = s/2;
         vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }
        
        for(int j=1; j<=target; j++){
            dp[0][j] = false;
        }

        // Fill DP table
        for(int i=1; i<=n; i++){
            for(int sum=1; sum<=target; sum++){
                dp[i][sum] = dp[i-1][sum]; // skip
                if(sum >= arr[i-1]) {
                    dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i-1]]; // take
                }
            }
        }

        return dp[n][target];
    }
};