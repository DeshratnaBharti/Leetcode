class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    int n;
    int DFS(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited,int id){
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==0 or visited[i][j]){
            return 0;
        }
        grid[i][j]=id;
        visited[i][j]=true;
        int length =1;
        for(auto &dir:directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            length+=DFS(grid,new_i,new_j,visited,id);
        }
        return length;
    }
    int largestIsland(vector<vector<int>>& grid) {
         n = grid.size();
        int maxA=0;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        int id =2;
        unordered_map<int,int>mp;
        //pahle dfs me sab 1 ko ek unique id de diya and us id ka length ko map me store  kar liya
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !visited[i][j]){
                   int len = DFS(grid,i,j,visited,id);
                   maxA=max(maxA,len);
                   mp[id]=len;
                   id++;

                }
            }
        }
        //sab ek saath 1 ke liye unique id hoga
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>uniqueIds;
                    for(auto &dir:directions){
                        int new_i =i+dir[0];
                        int new_j=j+dir[1];
                       // jo bhi 0 ke agal bagal me unique id hai usko set me daalo 
                        if(new_i >=0 and new_i <n and new_j >=0 and new_j <n and grid[new_i][new_j]!=0) uniqueIds.insert(grid[new_i][new_j]);
                    }
                    //phir usko sum karo
                    int overallsige =1;
                    for(auto &id:uniqueIds){
                        overallsige +=mp[id];
                    }
                    maxA=max(maxA,overallsige);

                }
            }
        }
        return maxA;
    }
};