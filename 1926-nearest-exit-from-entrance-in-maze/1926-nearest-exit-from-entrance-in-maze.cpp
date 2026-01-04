class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>&ent ){
      int m = maze.size();
      int n = maze[0].size();
      queue<pair<int,int>>que;
      int a = ent[0];
      int b = ent[1];
      que.push({a,b});
      maze[a][b] = '+';
      int step = 0;
      while(!que.empty()){
        int N = que.size();
        while(N--){
            auto t = que.front();
            que.pop();
            int i = t.first;
            int j = t.second;
            if(!(t.first==a and t.second == b)and (i==0 or i==m-1 or j==0 or j==n-1))return step;
            for(auto &dir :directions){
                int new_i = i + dir[0];
                int new_j = j+dir[1];
                if(new_i >=0 and new_i <m and new_j >= 0 and new_j <n and maze[new_i][new_j] != '+'){
                    que.push({new_i,new_j});
                    maze[new_i][new_j] = '+';
                }
            }
        }
        step++;
      }
      return -1;
        
    }
};