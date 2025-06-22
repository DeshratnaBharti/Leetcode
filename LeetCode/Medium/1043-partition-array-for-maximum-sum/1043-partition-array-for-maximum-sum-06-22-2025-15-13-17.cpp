class Solution {
public:
    int n;
    int solve(int i,vector<int>&arr,int k){
        if(i>=n) return 0;
        int result =0;
        int curr_max =-1;
        for(int j=i;j<n and j-i+1<=k;j++){
            curr_max = max(curr_max,arr[j]);
            result = max(result,((j-i+1)*curr_max)+solve(j+1,arr,k));
        }
        return result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        return solve(0,arr,k);
    }
};