class Solution {
public:
    typedef pair<int,pair<int,int>>PP;
    vector<vector<int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
;
    int trapRainWater(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        priority_queue<PP,vector<PP>,greater<>>bC;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int r=0;r<m;r++){
            for(int c : {0,n-1}){
                bC.push({arr[r][c],{r,c}});
                visited[r][c]=true;

            }
        }
        for(int c=0;c<n;c++){
            for(int r : {0,m-1}){
                bC.push({arr[r][c],{r,c}});
                visited[r][c]=true;
            }
        }
        int w=0;
        while(!bC.empty()){
            PP p=bC.top();
            bC.pop();
            int h = p.first;
            int i= p.second.first;
            int j = p.second.second;
            //find neighbors
            for(vector<int>&dir:directions){
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(new_i>=0 and new_i <m and new_j >=0 and new_j <n and !visited[new_i][new_j]){
                    w += max(h - arr[new_i][new_j], 0);


                    bC.push({max(arr[new_i][new_j], h), {new_i, new_j}});

                    visited[new_i][new_j] = true;
                }
            }
        }
        return w;
    }
};