class Solution {
public:
    vector<vector<int>> directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    typedef pair<int,pair<int,int>>P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==0 or n==0 or grid[0][0] != 0) return -1;
        auto isSafe = [&](int x,int y){
            return x>=0 and x<n and y>=0 and y<n;
        };
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        result[0][0] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int>node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(auto dir:directions){
                int x_new = x + dir[0];
                int y_new = y+ dir[1];
                int dist = 1;
                if(isSafe(x_new,y_new) and grid[x_new][y_new]==0 and d + dist < result[x_new][y_new]){
                    pq.push({d + dist,{x_new,y_new}});
                    result[x_new][y_new] = d + dist;
                }
            }
        }
        if(result[m-1][n-1]==INT_MAX) return -1;
        return result[m-1][n-1]+1;
    }
};