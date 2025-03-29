class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int m;
    int n;
    int BFS(vector<vector<int>>& mat,int sr, int sc){
         queue<P>que;
         vector<vector<bool>> visited(m, vector<bool>(n, false));
          visited[sr][sc] = true;
        que.push({sr,sc});
        int count =0;
         while(!que.empty()){
            int len = que.size();
            while(len--){
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;
                 //arr[i][j] = color;
                 if(mat[i][j]==0) return count;
                for(vector<int>&dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i >=0 and new_i <m and new_j >= 0 and new_j <n and !visited[new_i][new_j]){
                          visited[new_i][new_j] = true;
                        que.push({new_i,new_j});
           
                    }
                }
               
            }
            count++;
        }
        return -1;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         m = mat.size();
         n = mat[0].size();
        vector<vector<int>>res(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] !=0){
                    res[i][j] = BFS(mat,i,j);
                }
                else {
                     res[i][j]=mat[i][j];
                }
            }
        }
        return res;
    }
};