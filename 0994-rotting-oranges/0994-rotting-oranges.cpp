class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid.size();
        queue<P>que;
        int freshCount =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) freshCount++;
                else if(grid[i][j]==2) que.push({i,j});
            }
        }
        if(freshCount == 0) return 0;
        int minute =0;
        while(!que.empty()){
            int len = que.size();
            while(len--){
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;
                for(vector<int>& dir: directions){
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];
                    if(new_i >= 0 and new_i <m and new_j >=0 and new_j<n and grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        que.push({new_i,new_j});
                        freshCount--;
                    }
                }
            }
            minute++;
        }
        return freshCount==0 ? (minute-1): -1;
    }
};