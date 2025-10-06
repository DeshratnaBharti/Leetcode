class Solution {
public:
    vector<vector<int>>directions ={{1,0},{-1,0},{0,-1},{0,1}};
    int m,n;
    void dfs(vector<vector<int>>&arr,int i,int j ,int preCVal,vector<vector<bool>>&vis){
        if(i<0 or i>= m or j<0 or j>=n ){
            return;
        }
        if(arr[i][j]<preCVal or vis[i][j]){
            return;
        }
        vis[i][j] = true;
        for(auto &dir:directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            dfs(arr,new_i,new_j,arr[i][j],vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
         m = arr.size();
        n = arr[0].size();
        vector<vector<int>>res;
        vector<vector<bool>>pacVis(m,vector<bool>(n,false));
        vector<vector<bool>>atlVis(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            dfs(arr,0,j,INT_MIN,pacVis);
            dfs(arr,m-1,j,INT_MIN,atlVis);
        }
        for(int i=0;i<m;i++){
            dfs(arr,i,0,INT_MIN,pacVis);
            dfs(arr,i,n-1,INT_MIN,atlVis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacVis[i][j] and atlVis[i][j]) res.push_back({i,j});
            }
        }
        return res;
        
    }
};