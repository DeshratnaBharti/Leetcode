class Solution {
public:
    typedef pair<int,pair<int,int>>P;
     vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n= heights[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            auto coord = pq.top().second;

            int i = coord.first;
            int j=coord.second;
            pq.pop();
            if(i==m-1 and j==n-1) return diff;
            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i >=0 and new_i < m and new_j >=0 and new_j<n){
                    int absDiff=abs(heights[i][j]-heights[new_i][new_j]);
                    int maxDiff= max(diff,absDiff);
                    if(result[new_i][new_j]>maxDiff){
                        result[new_i][new_j]=maxDiff;
                        pq.push({maxDiff,{new_i,new_j}});

                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};