class Solution {
public:
    typedef pair<int,int>P;
     vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int m = arr.size();
        int n = arr[0].size();
         int originalColor = arr[sr][sc];
        if (originalColor == color) return arr;
        queue<P>que;
        que.push({sr,sc});

        //arr[sr][sc]=color;
        while(!que.empty()){
            int len = que.size();
            while(len--){
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;
                 
                for(vector<int>&dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i >=0 and new_i <m and new_j >= 0 and new_j <n and arr[new_i][new_j]== originalColor){
                        arr[i][j] = color;
                        arr[new_i][new_j]=color;
                        que.push({new_i,new_j});
                    }
                }
            }
        }
         return arr;
      
    }
};