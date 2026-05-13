class Solution {
public:
    vector<vector<int>>directions{{1,1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1},{1,-1},{1,0}};
    typedef pair<int,pair<int,int>>P;
    int m,n;
    bool isSafe(int x,int y){
        if(x>=m or y>=n or x<0 or y<0) return false;
        return true;

    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<P,vector<P>,greater<P>>que;
         m = grid.size();
         n = grid[0].size();
        if(m==0 or n ==0 or grid[0][0] != 0) return -1;
         vector<vector<int>>res(m,vector<int>(n,INT_MAX));
         que.push({0,{0,0}});
         res[0][0] = 0;
         while(!que.empty()){
            auto curr = que.top();
            que.pop();
            int pahleWalaDist = curr.first;
            pair<int,int>v= curr.second;
            int x = v.first;
            int y = v.second;
            for(auto &dir:directions){
                int new_x = x+dir[0];
                int new_y = y+dir[1];
                int currDist = 1;
                if(isSafe(new_x,new_y) and grid[new_x][new_y] != 1 and res[new_x][new_y] > pahleWalaDist + currDist){
                    res[new_x][new_y] = pahleWalaDist + currDist;
                    que.push({res[new_x][new_y],{new_x,new_y}});

                }          
            }    
         }
          if(res[m-1][n-1]==INT_MAX) return -1;
        return res[m-1][n-1]+1;
        
    }
};