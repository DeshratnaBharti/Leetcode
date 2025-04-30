//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
     vector<int> parent, rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); 
    }

    void unionS(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
     parent.resize(n * m);
        rank.resize(n * m, 0);
        for (int i = 0; i < n * m; i++) parent[i] = i;

        vector<vector<int>> grid(n, vector<int>(m, 0)); // Correct initialization
        vector<int> ans;
        int count = 0;
        
        // Correct direction vectors for up, down, left, right
        vector<int> dirX = { -1, 0, 1, 0 };
        vector<int> dirY = { 0, -1, 0, 1 };

        for (auto &pos : operators) {
            int row = pos[0], col = pos[1];

            if (grid[row][col] == 1) {  // Already land, no changes
                ans.push_back(count);
                continue;
            }

            grid[row][col] = 1; // Convert water to land
            count++;

            int index = row * m + col; // Convert 2D index to 1D
            for (int k = 0; k < 4; k++) {
                int new_r = row + dirX[k];
                int new_c = col + dirY[k];

                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c] == 1) {
                    int new_index = new_r * m + new_c;
                    if (find(new_index) != find(index)) {
                        unionS(new_index, index);
                        count--;  // Merge reduces island count
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends