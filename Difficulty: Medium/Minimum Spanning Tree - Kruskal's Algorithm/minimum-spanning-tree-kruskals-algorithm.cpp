//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  vector<int>parent;
  vector<int>rank;
   int find( int x) {
        // add code here
        if(x==parent[x]) return x;
         return parent[x]=find(parent[x]);
    }
    
    void unionS(int x, int y) {
        // add code here.
        int x_parent =find(x);
        int y_parent = find(y);
        if(x_parent ==y_parent) return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
           parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }

    
    int kruskal(vector<vector<int>> &edges){
        int s=0;
        for(auto &temp:edges){
            int u=temp[0];
            int v=temp[1];
            int w=temp[2];
            
            int parent_u=find(u);
            int parent_v=find(v);
            if(parent_u != parent_v){
                unionS(u,v);
                s+=w;
            }
        }
        return s;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        auto cmp=[&](auto edge1,auto edge2){
            return edge1[2]<edge2[2];
        };
        sort(edges.begin(),edges.end(),cmp);
        return kruskal(edges);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Solution obj;
        cout << obj.kruskalsMST(V, edges) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends