class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    int m,n;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool isSafe(int x,int y){
        if(x>=m or y>=n or x<0 or y<0) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
         n = heights[0].size();
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        res[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int diff = curr.first;
            pair<int,int>v = curr.second;
            int x = v.first;
            int y = v.second;
            if(x == m-1 and y == n-1) return diff;
            for(auto &dir:directions){
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                 if(isSafe(new_x,new_y)){
                  int new_diff = abs(heights[x][y] - heights[new_x][new_y]);
                  int  maxDiff = max(diff,new_diff);
                 
                  if(res[new_x][new_y]>maxDiff){
                      res[new_x][new_y] = maxDiff;
                      pq.push({maxDiff,{new_x,new_y}});
                  }
                 }
            }
        }
        return res[m-1][n-1];
    }
};