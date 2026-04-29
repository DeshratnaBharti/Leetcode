// User function Template for C++

class Solution {
  public:
    int m,n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&mat,int i,int j){
        if(j < 0 || j >= n) return -1e9;
        if(i==m-1) return mat[i][j];
       

        if(dp[i][j] != -1) return dp[i][j];
        int leftD = mat[i][j] + solve(mat,i+1,j-1);
        int down = mat[i][j] + solve(mat,i+1,j);
        int rightD = mat[i][j] + solve(mat,i+1,j+1);
        return dp[i][j]=max({leftD,down,rightD});
    }
   
    int maximumPath(vector<vector<int>>& mat) {
        // code here
         m = mat.size();
         n = mat[0].size();
         dp.resize(m,vector<int>(n,-1));
         int maxi =INT_MIN;
         for(int j=0;j<n;j++){
             maxi = max(maxi , solve(mat,0,j));
         }
        return maxi;
    }
};