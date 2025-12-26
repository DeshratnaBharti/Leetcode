class Solution {
public:
    vector<vector<int>> directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==0 or n==0 or grid[0][0] != 0) return -1;
        auto isSafe = [&](int x,int y){
            return x>=0 and x<n and y>=0 and y<n;
        };
        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0] =1;
        int level =0;
        while(!que.empty()){
            int N = que.size();
            while(N--){
                auto curr = que.front();
                que.pop();
                int x = curr.first;
                int y = curr.second;
                if(x==m-1 and y==n-1) return level+1;

                for(auto dir: directions){
                    int x_new = x + dir[0];
                    int y_new = y + dir[1];
                    if(isSafe(x_new,y_new) and grid[x_new][y_new] == 0){
                        que.push({x_new,y_new});
                        grid[x_new][y_new] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};