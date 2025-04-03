//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int m;
  int n;
   typedef pair<int,int>P;
   int freshOranges;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
   int bfs(vector<vector<int>>& arr,  queue<pair<int,int>>&que,vector<pair<int,int>>visited){
       int count =0;
       while(!que.empty()){
           int N = que.size();
           bool rotted = false;
           while(N--){
               P curr= que.front();
               que.pop();
               int i = curr.first;
                int j = curr.second;
                  //arr[i][j] = color;
                for(vector<int>&dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i >=0 and new_i <m and new_j >= 0 and new_j <n and arr[new_i][new_j]== 1){
                     //   arr[i][j] = color;
                        arr[new_i][new_j]=2;
                       // visited.push_back({new_i,new_j});
                        rotted = true;
                         freshOranges--;
                        que.push({new_i, new_j});
                    }
                }
           }
            if (rotted) count++;
       }
       return count;
   }
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
         m = mat.size();
         n = mat[0].size();
         int count=0;
          freshOranges=0;
        vector<pair<int,int>>visited;
        queue<pair<int,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==2){
                   que.push({i,j}); 
                }else if (mat[i][j] == 1) {
                    freshOranges++;
            }}
        }
        if(freshOranges == 0) return 0;
        count += bfs(mat,que,visited);
       // if(freshOranges == 0) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                   return -1;
                }
            }
        }
         return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends