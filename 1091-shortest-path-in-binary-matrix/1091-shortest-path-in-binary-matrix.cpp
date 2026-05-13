class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    bool isSafe(int x,int y){
        if(x>=0 and y>=0 and x<m and y<n ) return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
         if(m==0 or n==0 or grid[0][0] != 0) return -1;
        queue<pair<int,int>>que;
        grid[0][0] =1;
        que.push({0,0});
        int count =0;
        while(!que.empty()){
            int N= que.size();
            while(N--){
                auto curr = que.front();
                que.pop();
                int x = curr.first;
                int y = curr.second;
                if(x==m-1 and y==n-1) return count+1;
                for(auto &dir:directions){
                    int new_x = x + dir[0];
                    int new_y = y+dir[1];
                    if(isSafe(new_x,new_y) and grid[new_x][new_y] == 0){
                        que.push({new_x,new_y});
                        grid[new_x][new_y] = 1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};