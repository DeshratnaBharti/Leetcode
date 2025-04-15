/**
1091. Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
***/
//using dijsktra algo
class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        if(m==0 or n==0 or grid[0][0] !=0) return -1;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        result[0][0]=0;
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int>node=pq.top().second;
            int i=node.first;
            int j= node.second;
            pq.pop();
            for(auto &dir:directions){
                int new_i =i+dir[0];
                int new_j = j+dir[1];
                int dist=1;
                if(new_i >=0 and new_i < m and new_j >=0 and new_j<n and grid[new_i][new_j]==0 and d+dist <result[new_i][new_j]){
                    pq.push({d+dist,{new_i,new_j}});
                    result[new_i][new_j]=d+dist;
                }
            }
                            
        }
        if(result[m-1][n-1]==INT_MAX) return -1;
        return result[m-1][n-1]+1;
    }
};


//methos 2
//using queue 

class Solution {
public:
    vector<vector<int>>directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 or n==0 or grid[0][0] !=0) return -1;

        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0] =1;
        int level=0;
        bool flag =true;
        while(!que.empty()){
            int N=que.size();
            while(N--){
                auto curr=que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;
                if(i==m-1 and j==n-1) {
                    flag = false;
                    return level+1;
                }
                for(auto &dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i >=0 and new_i < m and new_j >=0 and new_j<n and grid[new_i][new_j]==0){
                        que.push({new_i,new_j});
                        grid[new_i][new_j]=1;
                    }
                }
            }
            level++;

        }
        return -1;
    }
};
